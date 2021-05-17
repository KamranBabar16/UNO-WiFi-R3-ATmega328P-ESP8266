#include <Arduino.h>

/**************************************************************
 *
 * In this IoT project, you can turn both Atmega328p modules can 
 * communicate with each other.
 * Before uploading the sketch you will need to activate the 
 * deep switches 5, 6, 7 and select Arduino IDE --> Tools --> Board: --> Generic ESP8266 Module.
 * Also unplug serial wires that connected From ESP8266 to the Arduino ATmega328P Board 9 and 10 pins.
 *
 *
 *   Project:                    https://github.com/KamranBabar16/UNO-WiFi-R3-ATmega328P-ESP8266
 *   My Website:                 https://bit.ly/3nNIqyj
 *   Social networks:            https://twitter.com/KamranBabar16
 *                               https://www.facebook.com/KamranBabarOfficial
 *                               https://www.linkedin.com/in/kamranbabar16/
 *
 *
 **************************************************************/


#include <ESP8266WiFi.h>

// uncomment following line to generate debugging info
//#define DEBUG

#ifdef DEBUG
#define DEBUG_PRINT(x)     Serial.print (x)
#define DEBUG_PRINTLN(x)   Serial.println (x)
#else
#define DEBUG_PRINT(x)
#define DEBUG_PRINTLN(x)
#endif

const char* ssid     = "<YOUR WiFi SSD NAME>"; // Replace with your WiFi SSD Name.
const char* password = "<YOUR WiFi PASS>"; // Replace with your WiFi Pass.

// host & port for Blynk server
const char* host = "blynk-cloud.com";
const int port = 8442;

// host & port for local test server
//const char* host = "192.168.128.53";
//const int port = 10001;

int reconnectCount = 0;
byte incomingByte = 0;

// Use WiFiClient class to create TCP connections
WiFiClient client;

void setup() {
  Serial.begin(9600);
  delay(100);

  // We start by connecting to a WiFi network
  DEBUG_PRINT("Connecting to ");
  DEBUG_PRINTLN(ssid);

  WiFi.begin(ssid, password);
  DEBUG_PRINTLN(WiFi.macAddress());

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    if (reconnectCount >= 60) {
      ESP.restart();
    }
    reconnectCount++;
    DEBUG_PRINT(".");
  }
  reconnectCount = 0;

  DEBUG_PRINTLN("");
  DEBUG_PRINTLN("WiFi connected");
  DEBUG_PRINT("IP address: ");
  DEBUG_PRINTLN(WiFi.localIP());

  // Now connecting to the server
  connectToServer();
  while (!client.connected()) {
    delay(500);
    if (reconnectCount >= 60) {
      ESP.restart();
    }
    DEBUG_PRINTLN("Try again...");
    connectToServer();
    reconnectCount++;
  }
}

void loop() {
//  if (Serial.available()) {
  while (Serial.available()) {
    incomingByte = Serial.read();
    if (client.connected()) {
      client.write(incomingByte);
    } else {
      delay(500);
      if (reconnectCount >= 60) {
        ESP.restart();
      }
      DEBUG_PRINTLN("Connection lost!");
      DEBUG_PRINTLN("Try to reconnect...");
      connectToServer();
      reconnectCount++;
    }
    //yield();
  }

//  if (client.available()) {
  while (client.available()) {
    incomingByte = client.read();
    Serial.write(incomingByte);
    //yield();
  }
  yield();
}

void connectToServer() {
  DEBUG_PRINT("connecting to ");
  DEBUG_PRINTLN(host);
  if (!client.connect(host, port)) {
    DEBUG_PRINTLN("connection failed");
    return;
  } else {
    DEBUG_PRINTLN("ESP8266 Connected");
    #ifdef DEBUG
      client.println("ESP8266 Connected");
    #endif
    reconnectCount = 0;
    return;
  }
}
