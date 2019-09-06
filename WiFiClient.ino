#include <ESP8266WiFi.h>
#include <EEPROM.h>
#include <ESP8266WebServer.h>
#include <Ticker.h>

ESP8266WebServer server(80);

//unsigned long beginMicros, endMicros;
int contconexion = 0;
unsigned long byteCount = 0;
bool printWebData = false;  // set to false for better speed measurement
Ticker NetCheckTimer;

/////////////////////////////////////////////////////////////

String Device = "ArdWiFi-01";
String OP = "Mold 74";
//const char* ssid     = "C@P WIFI";
//const char* password = "C@psonic01!";
String ssid     = "C@P WIFI";
String password = "C@psonic01!";
//String ssid     = "C@PEP";
//String password = "9158723500";
String Value = "110011";
String Status = "TestWiFi";
String PartsProd = "1";
String MAC = "00:00:00:00:00:00";
String Ver = "1.2";
String HartBeat = "120";
bool _HeartBeatEN = true;

/////CONFIG FLAGS///////

bool ChgDevName = false;
bool ChgOPName = false;
bool CfgMode = false;
bool PartsPCycle = false;
bool _SSID = false;
bool _PASS = false;
bool _Loged = false;
bool _HeartBeat = false;
bool _HeartBeatTick = false;
////////////////////////

String PostData = "{\"OP\": \"" + OP + "\", \"Value\": " + Value + ", \"Status\": \"" + Status + "\",\"PartsProduced\": " + PartsProd + "}";
String UrlPath_q = "/Production/Sample?OP=" + OP + "&Value=" + Value + "&Status=" + Status;
//String UrlPath="/Production/Sample";
String UrlPath = "/Production/ArduinoNode";
String IoTPing = "/Production/IoTPing";
char APIserver[] = "apps.capsonic.com";    // name address for Google (using DNS)

/////////////////////////////////////////////////////////////

String inputString = "";         // a String to hold incoming data
bool stringComplete = false;  // whether the string is complete

///////////////////////////////////////////////////////////////////////////
// constants won't change. They're used here to set pin numbers:
const int buttonPin = 13;    // the number of the pushbutton pin 13
const int ModeButton = 12;    // the number of the pushbutton pin 12
const int ledPin = 16;      // the number of the LED pin
const int ConLed = 14;      // the number of the LED pin

// Variables will change:
int ledState = HIGH;         // the current state of the output pin
int buttonState = HIGH;            // the current reading from the input pin
int lastButtonState = HIGH;   // the previous reading from the input pin

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

////////////////////////////////////////////////////////////////////

void setup() {
  ///Starts Serial Com
  Serial.begin(115200);
  //Serial.begin(9600);
  delay(10);

  ///Reads EEPROM's Default values
  EEPROM.begin(512);
  CFG_LOAD();

  ///////////////////////////////////////////////////
  pinMode(buttonPin, INPUT);
  pinMode(ModeButton, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(ConLed, OUTPUT);

  // set initial LED state
  digitalWrite(ledPin, ledState);
  digitalWrite(ConLed, LOW);
  ///////////////////////////////////////////////////
  MAC = WiFi.softAPmacAddress().c_str();
  if (digitalRead(ModeButton) == 0) {
    modoconf();
  }

  // We start by connecting to a WiFi network
  WiFi.softAPdisconnect (true);
  Wifi_SetUp();
  inputString.reserve(200);
  CommandDefinition("CFG_PRINT");
  IOT_Mode();

  ///Setup Network Hart Beat
  if (_HeartBeatEN) {
    NetCheckTimer.attach(HartBeat.toInt(), HeartBeatTick);
  }

}

int value = 0;

void loop() {
  if (_HeartBeatTick)
  {
    NetworkCheck();
  }
  PostTrigger();
  SerialRead();
  server.handleClient();
}
