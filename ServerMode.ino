
const char *ssidConf = "Arduino WIFI AP";
const char *passConf = "12345678";

String UserName="admin";
String AdminPass="admin";

String mensaje = "";

void paginaconf() {
  
  LoadWebPage();
  if(_Loged==true)
  {
  Serial.println(pagina);
    server.send(200, "text/html", pagina + mensaje + paginafin); 
  }
  else
  {
    server.send(200, "text/html", pagina_Login + mensaje + paginafin);
  }
}

void paginalogin() {
  server.send(200, "text/html", pagina_Login + mensaje + paginafin); 
}

void modoconf() {
   
  delay(100);
  digitalWrite(ConLed, HIGH);
  delay(100);
  digitalWrite(ConLed, LOW);
  delay(100);
  digitalWrite(ConLed, HIGH);
  delay(100);
  digitalWrite(ConLed, LOW);

  WiFi.softAP(ssidConf, passConf);
  IPAddress myIP = WiFi.softAPIP(); 
  Serial.println("");
  Serial.print("IP del acces point: ");
  Serial.println(myIP);
  Serial.println("WebServer iniciado...");

  server.on("/", paginaconf); //esta es la pagina de configuracion
  server.on("/guardar_conf", guardar_conf); //Graba en la eeprom la configuracion
  server.on("/escanear", escanear); //Escanean las redes wifi disponibles
  server.on("/Login", Login); //Escanean las redes wifi disponibles
  server.on("/exit", Login); //Escanean las redes wifi disponibles

  server.begin();

  while (true) 
  {    
      server.handleClient();
  }
}

void IOT_Mode()
{
  
  Serial.println("WebServer iniciado...");
  
  server.on("/", paginaconf); //esta es la pagina de configuracion
  server.on("/guardar_conf", guardar_conf); //Graba en la eeprom la configuracion
  server.on("/escanear", escanear); //Escanean las redes wifi disponibles
  server.on("/Login", Login); //Escanean las redes wifi disponibles
  server.on("/exit", Login); //Escanean las redes wifi disponibles
  LoadWebPage();
  server.begin();
  } 
void Close()
{
  _Loged=false;
  mensaje = "";
  paginaconf();
  }

void Login()
{
if(server.arg("login")==UserName&&server.arg("pass")==AdminPass)
{
  _Loged=true;
  mensaje = "";
  LoadWebPage();
  paginaconf();
  }
 else
 {
  mensaje="Loging Error...";
  paginalogin();
  }
  }

void guardar_conf() {
  
  if(server.arg("ssid")!=""||server.arg("pass")!=""||server.arg("dev_name")!=""||server.arg("op_name")!=""||server.arg("pp_cycle")!="")
  {
  ssid=server.arg("ssid");
  Serial.println(ssid);//Recibimos los valores que envia por GET el formulario web
  //EEPROM_SAVE(ssid,ADDR_ssid); 
  
  password =server.arg("pass");
  Serial.println(password);
//  EEPROM_SAVE(password,ADDR_password);

  Device=server.arg("dev_name");
  Serial.println(Device);
//  EEPROM_SAVE(Device,ADDR_Device);

  OP=server.arg("op_name");
  Serial.println(OP);
//  EEPROM_SAVE(OP,ADDR_OP);
  
  PartsProd=server.arg("pp_cycle");
  Serial.println(PartsProd);
//  EEPROM_SAVE(PartsProd,ADDR_PartsProd);

  CFG_SAVE();
  mensaje = "CONFIGURATION SAVED...";
  paginaconf();
  }
  else
  {
  mensaje = "INPUTS CAN NOT BE EMPTY...";
  paginaconf();
    }
}

void escanear() {  
  if(_Loged)
  {
  int n = WiFi.scanNetworks(); //devuelve el número de redes encontradas
  Serial.println("Wifi Scan Finished");
  if (n == 0) { //si no encuentra ninguna red
    Serial.println("No Wifi signas were found.");
    mensaje = "No Wifi signas were found.";
  }  
  else
  {
    Serial.print(n);
    Serial.println(" redes encontradas");
    mensaje = "";
    String T_Header="<table border= 'solid'>"
    " <tr> <th>No.</th> <th>WiFi SSID</th> <th>WiFi Strength</th> <th>Channel</th> <th>WiFi Encryption Type</th> </tr>";
    String T_Row="";
    for (int i = 0; i < n; ++i)
    {
      // agrega al STRING "mensaje" la información de las redes encontradas 
      mensaje = (mensaje) + "<p>" + String(i + 1) + ": " + WiFi.SSID(i) + " (" + WiFi.RSSI(i) + ") Ch: " + WiFi.channel(i) + " Enc: " + WiFi.encryptionType(i) + " </p>\r\n";
      T_Row= T_Row+"<tr> <td>"+String(i + 1)+"</td> <td>"+WiFi.SSID(i)+"</td> <td>"+ WiFi.RSSI(i) +"</td> <td>"+WiFi.channel(i)+"</td> <td>"+encryptionType(WiFi.encryptionType(i))+"</td> </tr>";
      //WiFi.encryptionType 5:WEP 2:WPA/PSK 4:WPA2/PSK 7:open network 8:WPA/WPA2/PSK
      delay(10);
    }
    Serial.println(mensaje);
    mensaje=T_Header+T_Row+"</table>";
    paginaconf();
  }
  }
}
String encryptionType(int eType)
{
  if(eType==5)
  { return "WEP"; }
  
  if(eType==2)
  { return "WPA/PSK"; }
  
  if(eType==4)
  { return "WPA2/PSK"; }
  
  if(eType==7)
  { return "Open Network"; }
  
  if(eType==8)
  { return "WPA/WPA2/PSK"; }

  else
  {return "";
    }
    
}
