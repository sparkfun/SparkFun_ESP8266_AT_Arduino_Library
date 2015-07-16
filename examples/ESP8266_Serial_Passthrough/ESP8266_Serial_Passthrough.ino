/************************************************************
ESP8266_Serial_Passthrough.h
SparkFun ESP8266 AT library - Serial Passthrough Utility
Jim Lindblom @ SparkFun Electronics
Original Creation Date: July 16, 2015
https://github.com/sparkfun/SparkFun_ESP8266_AT_Arduino_Library

This example sketch is a handy "serial passthrough". Anything
sent to the Arduino serial port will be routed to the ESP8266
software serial port, and vice-versa.

If you use the Serial Monitor, make sure you SET THE LINE
ENDING PULLDOWN to "Both NL & CR".

Then try typing commands from the AT command set
(https://cdn.sparkfun.com/assets/learn_tutorials/4/0/3/4A-ESP8266__AT_Instruction_Set__EN_v0.30.pdf)

For example, to set the mode to STA, connect to a network,
and check your IP address, type:
AT+CWMODE=1
AT+CWJAP="networkName","networkPassword"
AT+CIFSR

Development environment specifics:
  IDE: Arduino 1.6.5
  Hardware Platform: Arduino Uno
  ESP8266 WiFi Shield Version: 1.0

This code is released under the MIT license.

Distributed as-is; no warranty is given.
************************************************************/
#include <SoftwareSerial.h>
#include <SparkFunESP8266WiFi.h>

void setup() 
{
  Serial.begin(9600);
  esp8266.begin();
}

void loop() 
{
  serialPassthrough();
}

void serialPassthrough()
{
  while (Serial.available())
    esp8266.write(Serial.read());
  while (esp8266.available())
    Serial.write(esp8266.read());
}
