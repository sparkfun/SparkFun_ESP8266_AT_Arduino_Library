/******************************************************************************
SparkFunESP8266Client.cpp
ESP8266 WiFi Shield Library Client Source File
Jim Lindblom @ SparkFun Electronics
Original Creation Date: June 20, 2015
http://github.com/sparkfun/SparkFun_ESP8266_AT_Arduino_Library

!!! Description Here !!!

Development environment specifics:
	IDE: Arduino 1.6.5
	Hardware Platform: Arduino Uno
	ESP8266 WiFi Shield Version: 1.0

This code is beerware; if you see me (or any other SparkFun employee) at the
local, and you've found our code helpful, please buy us a round!

Distributed as-is; no warranty is given.
******************************************************************************/

#include "SparkFunESP8266WiFi.h"
#include <Arduino.h>
#include "util/ESP8266_AT.h"
#include "SparkFunESP8266Server.h"

ESP8266Server::ESP8266Server(uint16_t port)
{
    _port = port;
}

void ESP8266Server::begin()
{
	esp8266.configureTCPServer(_port, 1);
}

ESP8266Client ESP8266Server::available(uint8_t wait)
{
	if (esp8266.readForResponse(",CONNECT", wait) > 0)
	{
		char * p = esp8266.searchBuffer(",CONNECT");
		p -= 1;
		//p -= 1; // Move p back one character
		uint8_t sock = *p - 48;
		ESP8266Client client(sock);
		return client;
	}
	if (esp8266.updateStatus())
	{
		for (int sock=0; sock<ESP8266_MAX_SOCK_NUM; sock++)
		{
			if ((esp8266._status.ipstatus[sock].linkID != 255) &&
			      (esp8266._status.ipstatus[sock].tetype == ESP8266_SERVER))
			{
				ESP8266Client client(sock);
				
				return client;
			}
		}
	}
	
	return ESP8266Client(255);
}

uint8_t ESP8266Server::status() 
{
	return esp8266.status();
}


size_t ESP8266Server::write(uint8_t b)
{
    return write(&b, 1);
}

size_t ESP8266Server::write(const uint8_t *buffer, size_t size)
{	

	size_t n = 0;
/*
    for (int sock = 0; sock < MAX_SOCK_NUM; sock++)
    {
        if (WiFiClass::_server_port[sock] != 0)
        {
        	ESP8266Client client(sock);

            if (WiFiClass::_server_port[sock] == _port &&
                client.status() == ESTABLISHED)
            {                
                return esp8266.tcpSend(sock, buf, size);
            }
        }
    }
*/
    return n;
}