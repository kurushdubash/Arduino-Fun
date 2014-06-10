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

 char server[] = "https://coinbase.com/api/v1/prices/spot_rate";    
 void setup() {
 // Open serial communications and wait for port to open:
  Serial.begin(9600);
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
  delay(60000);
}