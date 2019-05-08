

void Wifi_SetUp()
{
  
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  bool blinkLed=false;
  for(int i=0;i<10;i++)
  {          
      digitalWrite(ConLed, blinkLed);
      blinkLed=!blinkLed;
      delay(500);
  }  
      digitalWrite(ConLed, false);
  }
