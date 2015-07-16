#include <SoftwareSerial.h>
#include <SparkFunESP8266WiFi.h>

IPAddress ip(204, 144, 132, 37);
void setup() 
{
  Serial.begin(9600);
  while (!Serial.available()) ;
  while (esp8266.begin() != true) ;
  if (esp8266.status() <= 0)
  {
    while (esp8266.connect("sparkfun-guest", "sparkfun6333") < 0)
      delay(1000);
  }
  delay(1000);
  Serial.print("Pinging 204.144.132.37: ");
}

void loop() 
{
  Serial.println(esp8266.ping(ip));
  delay(1000);
}