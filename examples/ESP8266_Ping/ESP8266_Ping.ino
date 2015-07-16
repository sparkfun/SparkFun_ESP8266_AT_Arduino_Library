/************************************************************
ESP8266_Ping.h
SparkFun ESP8266 AT library - Ping Demo
Jim Lindblom @ SparkFun Electronics
Original Creation Date: July 16, 2015
https://github.com/sparkfun/SparkFun_ESP8266_AT_Arduino_Library

This example pings a destination server over and over and over.
It'll print the response time (in ms) to the serial monitor.

Development environment specifics:
  IDE: Arduino 1.6.5
  Hardware Platform: Arduino Uno
  ESP8266 WiFi Shield Version: 1.0

This code is released under the MIT license.

Distributed as-is; no warranty is given.
************************************************************/

#include <SoftwareSerial.h>
#include <SparkFunESP8266WiFi.h>

// Replace these two character strings with the name and
// password of your WiFi network.
const char mySSID[] = "yourSSIDhere";
const char myPSK[] = "yourPWDhere";

char destServer[] = "sparkfun.com";

void setup() 
{
  Serial.begin(9600);
  while (esp8266.begin() != true)
  {
    Serial.print("Error connecting to ESP8266.");
	delay(1000);
  }
  
  if (esp8266.status() <= 0)
  {
    while (esp8266.connect(mySSID, myPSK) < 0)
      delay(1000);
  }
  delay(1000);
  Serial.print("Pinging ");
  Serial.println(destServer);
}

void loop() 
{
  Serial.println(esp8266.ping(destServer));
  delay(1000);
}