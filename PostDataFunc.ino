//
//void PostDataFunc()
//{
//
//  WiFiClient client;
//  //PartsProd++;
//  //PostData = "{\"OP\": \""+OP+"\", \"Value\": "+Value+", \"Status\": \""+Status+"\",\"PartsProduced\": "+PartsProd+"}";
//  //PostData = "{\"OP\": \""+OP+"\", \"Value\": "+Value+", \"Status\": \""+Device+"\",\"PartsProduced\": "+PartsProd+"}";
//  PostData = "{\"OP\": \"" + OP + "\", \"Name\": \"" + Device + "\",\"PartsProduced\": " + PartsProd + ",\"MAC\":" + MAC + "}";
//
//  Serial.println("Post Sent");
//  Serial.println(APIserver);
//  //    // if you get a connection, report back via serial:
//  if (client.connect(APIserver, 80))
//  {
//    //Serial.print("connected to ");
//    //Serial.println(client.remoteIP());
//    // Make a HTTP POST request:
//    client.println("POST " + UrlPath + " HTTP/1.1");
//    //Serial.println("POST "+UrlPath);
//    client.println("Host: apps.capsonic.com");
//    client.println("Connection: close");
//    client.println("Content-Type: application/json");
//    client.println("Accept: application/json");
//    client.print("Content-Length: ");
//    client.println(PostData.length());
//    client.println();
//    client.println(PostData);
//    Serial.println(client.read());
//    client.stop();
//  }
//  else
//  {
//    // if you didn't get a connection to the server:
//    Serial.println("connection failed");
//  }
//}

void HTTPPOST(String _PostData, String _APIserver, String _UrlPath)
{
  WiFiClient client;
  Serial.println("Post Sent");
  //Serial.println(_APIserver);
  //    // if you get a connection, report back via serial:
  if (client.connect(_APIserver, 80))
  {
    client.println("POST " + _UrlPath + " HTTP/1.1");
    //Serial.println("POST "+_UrlPath+" HTTP/1.1");
    client.println("Host: " + _APIserver);
    //Serial.println("Host: "+_APIserver);
    client.println("Connection: close");
    client.println("Content-Type: application/json");
    client.println("Accept: application/json");
    client.print("Content-Length: ");
    client.println(_PostData.length());
    //Serial.println(_PostData.length());
    client.println();
    client.println(_PostData);
    //Serial.println(_PostData);
    //Serial.println(client.read());
    client.stop();
  }
  else
  {
    // if you didn't get a connection to the server:
    Serial.println("connection failed");
  }
  Serial.println();
}
