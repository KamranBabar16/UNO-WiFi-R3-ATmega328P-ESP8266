#include <Arduino.h>

/**************************************************************
 *
 * In this IoT project, you can turn both Atmega328p modules can 
 * communicate with each other.
 * Before uploading the sketch you will need to activate the 
 * deep switches 3, 4 and select Arduino IDE --> Tools --> Board: --> Arduino Uno.
 *
 *   Project:                    https://github.com/KamranBabar16/UNO-WiFi-R3-ATmega328P-ESP8266
 *   My Website:                 https://bit.ly/3nNIqyj
 *   Social networks:            https://twitter.com/KamranBabar16
 *                               https://www.facebook.com/KamranBabarOfficial
 *                               https://www.linkedin.com/in/kamranbabar16/
 *
 *
 **************************************************************/


#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#define BLYNK_DEBUG
#define BLYNK_TIMEOUT_MS 5000 // Longer timeout as connection was sometimes lost

#include <BlynkSimpleStream.h>
#include <SoftwareSerial.h>

#define rxPin 10
#define txPin 11

SoftwareSerial SwSerial(rxPin, txPin); // RX, TX

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"; // Replace with your Auth Token in the Blynk App.

BlynkTimer timer;

void setup()
{
  // Debug console
  Serial.begin(9600);
  Serial.print("BLYNK_TIMEOUT_MS : ");
  Serial.println(BLYNK_TIMEOUT_MS);
  Serial.print("BLYNK_MAX_SENDBYTES : ");
  Serial.println(BLYNK_MAX_SENDBYTES);
  delay(10000);

  // define pin modes for tx, rx:
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);

  // Blynk will work through SoftwareSerial
  SwSerial.begin(9600);
  Blynk.begin(SwSerial, auth);

}

void loop()
{
  Blynk.run();
  timer.run();
  delay(100);
}
