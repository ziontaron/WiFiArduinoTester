/*
 *  This sketch sends data via HTTP GET requests to data.sparkfun.com service.
 *
 *  You need to get streamId and privateKey at data.sparkfun.com and paste them
 *  below. Or just customize this script to talk to other HTTP servers.
 *
 */

#include <ESP8266WiFi.h>

WiFiClient client;

const char* host = "data.sparkfun.com";
const char* streamId   = "....................";
const char* privateKey = "....................";


unsigned long beginMicros, endMicros;
unsigned long byteCount = 0;
bool printWebData = false;  // set to false for better speed measurement

/////////////////////////////////////////////////////////////

String OP="ArdWiFi-01";
String Value="110011";
String Status="TestWiFi";

String PostData = "{\"OP\": \""+OP+"\", \"Value\": "+Value+", \"Status\": \""+Status+"\"}";
String UrlPath_q="/Production/Sample?OP="+OP+"&Value="+Value+"&Status="+Status;
String UrlPath="/Production/Sample";
/////////////////////////////////////////////////////////////


String inputString = "";         // a String to hold incoming data
bool stringComplete = false;  // whether the string is complete

///////////////////////////////////////////////////////////////////////////
// constants won't change. They're used here to set pin numbers:
const int buttonPin = 16;    // the number of the pushbutton pin
const int ledPin = 12;      // the number of the LED pin
const int ConLed = 12;      // the number of the LED pin

// Variables will change:
int ledState = HIGH;         // the current state of the output pin
int buttonState= HIGH;             // the current reading from the input pin
int lastButtonState = HIGH;   // the previous reading from the input pin

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers
////////////////////////////////////////////////////////////////////

void setup() {
  //Serial.begin(115200);
  Serial.begin(9600);
  delay(10);

///////////////////////////////////////////////////
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  //pinMode(ConLed, OUTPUT);

  // set initial LED state
  digitalWrite(ledPin, ledState);
///////////////////////////////////////////////////


  // We start by connecting to a WiFi network  
  Wifi_SetUp();
  inputString.reserve(200);
  
}

int value = 0;

void loop() {
  //delay(5000);

    PostTrigger();

//  int reading = digitalRead(buttonPin);
//
//  Serial.println(reading);
    
  delay(10);
    
if (stringComplete) {
    Serial.println(inputString);
    // clear the string:
    inputString = "";
    stringComplete = false;
  }
  
  // Read all the lines of the reply from server and print them to Serial
//  while(client.available()){
//    String line = client.readStringUntil('\r');
//    Serial.print(line);
//  }
//  
//  Serial.println();
//  Serial.println("closing connection");
}
