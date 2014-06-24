/*
  Bitcoin Price Fetcher
 
 This sketch connects to a coinbase (https://coinbase.com/api/v1/prices/spot_rate)
 using a sparkcore. 
 

 created 9 June 2014
 by Kurush Dubash
 by Hassaan Shakeel
 
1. Reset
2. Use puTTy to connect to internet using command "w"
3. Wait for it to connect and everything, then flash online wirelessly.
4. Should work.

 */

// Includes LCD LiquidCrystal Library
#include "LiquidCrystal/LiquidCrystal.h" 
#include <SPI.h>
#include <Ethernet.h>
// Initializes these PINS as taking control of LCD (6 PINS)
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

 char server[] = "https://coinbase.com/";    
 EthernetClient client;
 void setup() {
 // Open serial communications and wait for port to open:
  Serial.begin(9600);
  if (client.connect(server, 80)) {
    Serial.println("connected");
    // Make a HTTP request:
    client.println("GET api/v1/prices/spot_rate HTTP/1.1");
    client.println("Host: https://coinbase.com/");
    client.println("Connection: close");
    client.println();
  } 
  // Initializes LCD Display as (20 Characters, 4 rows)
  lcd.begin(20, 4);
}

void loop()
{
  Serial.println("Connecting...");
  Serial.println("Connected");
  if (client.available()) {
    char c = client.read();
    Serial.print(c);
    lcd.print(c);
  }
  delay(60000);
  }
}