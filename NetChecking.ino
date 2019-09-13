void HeartBeatTick()
{
  _HeartBeatTick = true;
}

void NetworkCheck()
{
  //Serial.println();
  if (WiFi.status() == WL_CONNECTED) {
    //Serial.println(" WIFI Network Connected");

    PostData = "{\"Name\": \"" + Device + "\",\"MAC\":" + MAC + "}";

    //    if (client.connected()) {
    //    client.println("hello from ESP8266");
    //  }
    Serial.println(Device + " Heart Beat");
    HTTPPOST(PostData, APIserver, IoTPing);
  } else
  {
    Serial.println(Device + " WIFI Network Not Connected");
  }
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  _HeartBeatTick = false;
}
