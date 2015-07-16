/************************************************************
ESP8266_Phant_Library.h
SparkFun ESP8266 AT library - Phant Posting Example
Jim Lindblom @ SparkFun Electronics
Original Creation Date: July 16, 2015
https://github.com/sparkfun/SparkFun_ESP8266_AT_Arduino_Library

This example demonstrates how to use the TCP client 
functionality of the SparkFun ESP8266 WiFi library to post 
sensor readings to a Phant stream on 
https://data.sparkfun.com

This sketch is set up to post to a publicly available stream
https://data.sparkfun.com/streams/DJjNowwjgxFR9ogvr45Q
Please don't abuse it! But feel free to post a few times to
verify the sketch works. If it fails, check the HTTP response
to make sure the post rate hasn't been exceeded.

This sketch also requires that the Phant Arduino library be
installed. You can download it from the GitHub repository:
https://github.com/sparkfun/phant-arduino

Development environment specifics:
  IDE: Arduino 1.6.5
  Hardware Platform: Arduino Uno
  ESP8266 WiFi Shield Version: 1.0

This code is beerware; if you see me (or any other SparkFun 
employee) at the local, and you've found our code helpful, 
please buy us a round!

Distributed as-is; no warranty is given.
************************************************************/
// The SparkFunESP8266WiFi library uses SoftwareSerial
// to communicate with the ESP8266 module. Include that
// library first:
#include <SoftwareSerial.h>
// Include the ESP8266 AT library:
#include <SparkFunESP8266WiFi.h>
// This example also requires the Phant Arduino library.
// Download the library from our GitHub repo:
// https://github.com/sparkfun/phant-arduino
#include <Phant.h>

//////////////////////////////
// WiFi Network Definitions //
//////////////////////////////
// Replace these two character strings with the name and
// password of your WiFi network.
//const char mySSID[] = "PiFi";
//const char myPSK[] = "sparkfun";

//IPAddress myIP; // IPAddress to store the local IP

/////////////////////
// Phant Constants //
/////////////////////
// Phant detsination server:
const char phantServer[] = "data.sparkfun.com";
// Phant public key:
const char publicKey[] = "DJjNowwjgxFR9ogvr45Q";
// Phant private key:
const char privateKey[] = "P4eKwGGek5tJVz9Ar84n";
// Create a Phant object, which we'll use from here on:
Phant phant(phantServer, publicKey, privateKey);

void setup() 
{
  int status;
  Serial.begin(9600);
  
  // To turn the MG2639 shield on, and verify communication
  // always begin a sketch by calling cell.begin().
  status = esp8266.begin();
  if (status <= 0)
  {
    Serial.println(F("Unable to communicate with shield. Looping"));
    while(1) ;
  }
  /*
  esp8266.setMode(ESP8266_MODE_STA); // Set WiFi mode to station
  if (esp8266.status() <= 0) // If we're not already connected
  {
    if (esp8266.connect(mySSID, myPSK) < 0)
    {
      Serial.println(F("Error connecting"));
      while (1) ;
    }    
  }
  
  // Get our assigned IP address and print it:
  Serial.print(F("My IP address is: "));
  Serial.println(esp8266.localIP());*/
  
  Serial.println(F("Press any key to post to Phant!"));
}

void loop()
{
  /*
  // If data has been sent over a TCP link:
  if (.available())
  {  // Print it to the serial monitor:
    Serial.write(gprs.read());
  }*/
  // If a character has been received over serial:
  if (Serial.available())
  {
    // !!! Make sure we haven't posted recently
    // Post to Phant!
    postToPhant();
    // Then clear the serial buffer:
    while (Serial.available())
      Serial.read();
  }
}

void postToPhant()
{
  // Create a client, and initiate a connection
  ESP8266Client client;
  
  if (client.connect(phantServer, 80) <= 0)
  {
    Serial.println(F("Failed to connect to server."));
    return;
  }
  Serial.println(F("Connected."));
  
  // Set up our Phant post using the Phant library. For
  // each field in the Phant stream we need to call
  // phant.add([field], value).
  // Value can be any data type, in this case we're only
  // using integers.
  phant.add(F("analog0"), analogRead(A0));
  phant.add(F("analog1"), analogRead(A1));
  phant.add(F("analog2"), analogRead(A2));
  phant.add(F("analog3"), analogRead(A3));
  phant.add(F("analog4"), analogRead(A4));
  phant.add(F("analog5"), analogRead(A5));
  // Storing fields in flash (F()) will save a good chunk
  // of RAM, which is very precious.
  
  Serial.println(F("Posting to Phant!"));
  // Encapsulate a phant.post() inside a gprs.print(). 
  // phant.post() takes care of everything in the HTTP header
  // including newlines.
  client.print(phant.post());

  // available() will return the number of characters
  // currently in the receive buffer.
  while (client.available())
    Serial.write(client.read()); // read() gets the FIFO char
  
  // connected() is a boolean return value - 1 if the 
  // connection is active, 0 if it's closed.
  if (client.connected())
    client.stop(); // stop() closes a TCP connection.
}
