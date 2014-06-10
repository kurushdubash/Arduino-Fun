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
// Initializes these PINS as taking control of LCD (6 PINS)
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

 char server[] = "https://coinbase.com/api/v1/prices/spot_rate";    
 void setup() {
 // Open serial communications and wait for port to open:
  Serial.begin(9600);
<<<<<<< HEAD
=======
  Serial1.begin(9600);
  Serial.println("Connecting...");
   
   while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }

  delay(1000);
  
  Serial.println("Connected");

  // Initializes LCD Display as (20 Characters, 4 rows)
  lcd.begin(20, 4);
>>>>>>> 3728c40b8a78f293e6ac46ccc5047ad7f9ec16eb
}

void loop()
{
  // if there are incoming bytes available 
  // from the server, read them and print them:
  if (client.available()) {
    char c = client.read();
    Serial.print(c);
  }

  // if the server's disconnected, stop the client:
  if (!client.connected()) {
    Serial.println();
    Serial.println("disconnecting.");
    client.stop();

    // do nothing forevermore:
    while(true);
    
  }
<<<<<<< HEAD
  delay(60000);
}
=======
}
>>>>>>> 3728c40b8a78f293e6ac46ccc5047ad7f9ec16eb
