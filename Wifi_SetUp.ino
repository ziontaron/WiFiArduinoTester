void Wifi_SetUp()
{
  bool blinkLed = false;
  EEPROM.begin(512);
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED and contconexion < 50)
  {
    ++contconexion;
    delay(500);
    Serial.print(".");
    digitalWrite(ConLed, blinkLed);
    blinkLed = !blinkLed;
  }
  if (!WiFi.status())
  {
    Serial.println("");
    Serial.println("WiFi Not Connected ");
    digitalWrite(ConLed, false);

  }
  else
  {
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    //  for(int i=0;i<10;i++)
    //  {
    //      digitalWrite(ConLed, blinkLed);
    //      //digitalWrite(14, blinkLed);
    //      blinkLed=!blinkLed;
    //      delay(500);
    //  }
    digitalWrite(ConLed, true);
  }
}
