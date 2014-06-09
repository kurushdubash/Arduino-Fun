/*
  Bitcoin Price Fetcher
 
 This sketch connects to a coinbase (https://coinbase.com/api/v1/prices/spot_rate)
 using a sparkcore. 
 

 created 9 June 2014
 by Kurush Dubash
 by Hassaan Shakeel
 
 */

 char server[] = "https://coinbase.com/api/v1/prices/spot_rate";    
 void setup() {
 // Open serial communications and wait for port to open:
  Serial.begin(9600);
  Serial1.begin(9600);
   while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }

  delay(1000);
  Serial.println("Connecting...");
  Serial.println("Connected");
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
}