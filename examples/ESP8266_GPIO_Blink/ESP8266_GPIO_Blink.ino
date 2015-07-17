/************************************************************
ESP8266_GPIO_Blink.h
SparkFun ESP8266 AT library - GPIO Blink Demo
Jim Lindblom @ SparkFun Electronics
Original Creation Date: July 16, 2015
https://github.com/sparkfun/SparkFun_ESP8266_AT_Arduino_Library

This example uses the ESP8266 GPIO commands to control the
ESP8266's onboard LED, attached to pin 5.

Note: Once pin 5 is set to a mode with pinMode, it will not 
show the WiFi state. Resetting the ESP8266 with either
esp8266.reset() or cycling power, will set the pin 5 LED back
to a STAT indicator.

The ESP8266 WiFi Shield GPIO API includes:
  - esp8266.pinMode([pin], [mode])
  - esp8266.digitalWrite([pin], [state])
  - [state] esp8266.digitalRead([pin])

[pin] can be any of 0, 2, 4, 5, 12, 13, 14, 15, 16 (XPD).
[mode] can be INPUT, OUTPUT, or INPUT_PULLUP
[state] can be HIGH or LOW

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
  // Initialize the ESP8266 shield, make sure it's present:
  while (esp8266.begin() != true)
  {
    Serial.print("Error connecting to ESP8266.");
    delay(1000);
  }
  // Set pin 5 (STAT LED) to OUTPUT:
  esp8266.pinMode(5, OUTPUT);
}

void loop() 
{
  esp8266.digitalWrite(5, HIGH);
  delay(500);
  esp8266.digitalWrite(5, LOW);
  delay(500);
}
