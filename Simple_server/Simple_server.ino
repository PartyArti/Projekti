/*
 This is server code, which must be started first.
 Open serial monitor to see what IP address is given
 to your HUZZAH. Client should use that IP addres as
 it's HOST address.
 */

#include <ESP8266WiFi.h>

const char* ssid = "Honor 8 Lite";
const char* password = "SyksyNSN1";

// Create an instance of the server
// specify the port to listen on as an argument
const int Port = 100;
WiFiServer server(Port);

void setup() {
  Serial.begin(115200);
  delay(10);

  // prepare GPIO2
  pinMode(2, OUTPUT);
  digitalWrite(2, 0);
  
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  
  // Start the server
  server.begin();
  Serial.println("Server started");

  // Print the IP address
  Serial.println(WiFi.localIP());
}

void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }


  // Wait until the client sends some data
  Serial.println("new client has connected");
 
  while(true)
  {
  
    if(Serial.available())
    {
       String line = Serial.readStringUntil('\r');
       client.print(line);
    }
 
 
    while(client.available()){
       String req = client.readStringUntil('\r');
       Serial.println(req);
    }
    digitalWrite(2, !digitalRead(2));
    delay(100);
  }

} /* end of loop */

