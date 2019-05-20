
const char *ssidConf = "Arduino WIFI AP";
const char *passConf = "12345678";

String UserName="admin";
String AdminPass="admin";

String mensaje = "";

void paginaconf() {
  if(_Loged==true)
  {
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

  pagina.replace("@ssid", ssid);
  pagina.replace("@pass", password);
  pagina.replace("@dev_name", Device);
  pagina.replace("@op_name", OP);
  pagina.replace("@partcycle", PartsProd);

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
  Serial.println(server.arg("ssid"));//Recibimos los valores que envia por GET el formulario web
  EEPROM_SAVE(server.arg("ssid")+'\0',ADDR_ssid);  
  //grabar(0,server.arg("ssid"));
  Serial.println(server.arg("pass"));
  EEPROM_SAVE(server.arg("pass")+'\0',ADDR_password);
  
  Serial.println(server.arg("dev_name"));
  EEPROM_SAVE(server.arg("dev_name")+'\0',ADDR_Device);
  
  Serial.println(server.arg("op_name"));
  EEPROM_SAVE(server.arg("op_name")+'\0',ADDR_OP);
  
  Serial.println(server.arg("pp_cycle"));
  EEPROM_SAVE(server.arg("pp_cycle")+'\0',ADDR_PartsProd);

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
