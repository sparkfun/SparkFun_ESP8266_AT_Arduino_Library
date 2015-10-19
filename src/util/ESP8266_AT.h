/******************************************************************************
ESP8266_AT.h
ESP8266 AT Command Definitions
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

//////////////////////
// Common Responses //
//////////////////////
const char RESPONSE_OK[] = "OK\r\n";
const char RESPONSE_ERROR[] = "ERROR\r\n";
const char RESPONSE_FAIL[] = "FAIL";
const char RESPONSE_READY[] = "READY!";

///////////////////////
// Basic AT Commands //
///////////////////////
const char ESP8266_TEST[] = "";	// Test AT startup
const char ESP8266_RESET[] = "+RST"; // Restart module
const char ESP8266_VERSION[] = "+GMR"; // View version info
//!const char ESP8266_SLEEP[] = "+GSLP"; // Enter deep-sleep mode
const char ESP8266_ECHO_ENABLE[] = "E1"; // AT commands echo
const char ESP8266_ECHO_DISABLE[] = "E0"; // AT commands echo
//!const char ESP8266_RESTORE[] = "+RESTORE"; // Factory reset
const char ESP8266_UART[] = "+UART"; // UART configuration

////////////////////
// WiFi Functions //
////////////////////
const char ESP8266_WIFI_MODE[] = "+CWMODE"; // WiFi mode (sta/AP/sta+AP)
const char ESP8266_CONNECT_AP[] = "+CWJAP"; // Connect to AP
//!const char ESP8266_LIST_AP[] = "+CWLAP"; // List available AP's
const char ESP8266_DISCONNECT[] = "+CWQAP"; // Disconnect from AP
//!const char ESP8266_AP_CONFIG[] = "+CWSAP"; // Set softAP configuration
//!const char ESP8266_STATION_IP[] = "+CWLIF"; // List station IP's connected to softAP
//!const char ESP8266_DHCP_EN[] = "+CWDHCP"; // Enable/disable DHCP
//!const char ESP8266_AUTO_CONNECT[] = "+CWAUTOCONN"; // Connect to AP automatically
//!const char ESP8266_SET_STA_MAC[] = "+CIPSTAMAC"; // Set MAC address of station
const char ESP8266_GET_STA_MAC[] = "+CIPSTAMAC"; // Get MAC address of station
//!const char ESP8266_SET_AP_MAC[] = "+CIPAPMAC"; // Set MAC address of softAP
//!const char ESP8266_SET_STA_IP[] = "+CIPSTA"; // Set IP address of ESP8266 station
//!const char ESP8266_SET_AP_IP[] = "+CIPAP"; // Set IP address of ESP8266 softAP

/////////////////////
// TCP/IP Commands //
/////////////////////
const char ESP8266_TCP_STATUS[] = "+CIPSTATUS"; // Get connection status
const char ESP8266_TCP_CONNECT[] = "+CIPSTART"; // Establish TCP connection or register UDP port
const char ESP8266_TCP_SEND[] = "+CIPSEND"; // Send Data
const char ESP8266_TCP_CLOSE[] = "+CIPCLOSE"; // Close TCP/UDP connection
const char ESP8266_GET_LOCAL_IP[] = "+CIFSR"; // Get local IP address
const char ESP8266_TCP_MULTIPLE[] = "+CIPMUX"; // Set multiple connections mode
const char ESP8266_SERVER_CONFIG[] = "+CIPSERVER"; // Configure as server
const char ESP8266_TRANSMISSION_MODE[] = "+CIPMODE"; // Set transmission mode
//!const char ESP8266_SET_SERVER_TIMEOUT[] = "+CIPSTO"; // Set timeout when ESP8266 runs as TCP server
const char ESP8266_PING[] = "+PING"; // Function PING

//////////////////////////
// Custom GPIO Commands //
//////////////////////////
const char ESP8266_PINMODE[] = "+PINMODE"; // Set GPIO mode (input/output)
const char ESP8266_PINWRITE[] = "+PINWRITE"; // Write GPIO (high/low)
const char ESP8266_PINREAD[] = "+PINREAD"; // Read GPIO digital value
