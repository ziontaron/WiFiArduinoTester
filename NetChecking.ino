void HeartBeatTick()
{
  _HeartBeatTick=true;
  }

void NetworkCheck()
{
  Serial.println();
  if (WiFi.status() == WL_CONNECTED) {
    //Serial.println(" WIFI Network Connected");
    
     PostData = "{\"Name\": \""+Device+"\",\"MAC\":"+MAC+"}";

//    if (client.connected()) {
//    client.println("hello from ESP8266");
//  }
     Serial.println("Hart Beat");
     HTTPPOST(PostData, APIserver, IoTPing);
  } else
  {
    Serial.println(" WIFI Network Not Connected");
  }
  
  _HeartBeatTick=false;
}
