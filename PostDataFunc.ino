 
char APIserver[] = "apps.capsonic.com";    // name address for Google (using DNS)
 void PostDataFunc()
  {
      //PartsProd++;
      //PostData = "{\"OP\": \""+OP+"\", \"Value\": "+Value+", \"Status\": \""+Status+"\",\"PartsProduced\": "+PartsProd+"}";
      //PostData = "{\"OP\": \""+OP+"\", \"Value\": "+Value+", \"Status\": \""+Device+"\",\"PartsProduced\": "+PartsProd+"}";
      PostData = "{\"OP\": \""+OP+"\", \"Name\": \""+Device+"\",\"PartsProduced\": "+PartsProd+"}";
    
      Serial.println("Post Sent");
//    // if you get a connection, report back via serial:
      if (client.connect(APIserver, 80))
      {
        //Serial.print("connected to ");
        //Serial.println(client.remoteIP());
        // Make a HTTP POST request:
        client.println("POST "+UrlPath+" HTTP/1.1");
        //Serial.println("POST "+UrlPath);
        client.println("Host: apps.capsonic.com");
        client.println("Connection: close");
        client.println("Content-Type: application/json");    
        client.println("Accept: application/json");
        client.print("Content-Length: ");
        client.println(PostData.length());
        client.println();
        client.println(PostData);
      }
      else
      {
        // if you didn't get a connection to the server:
        Serial.println("connection failed");
      }
    }
