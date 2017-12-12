#include <Wire.h>
#include <SparkFun_APDS9960.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>



// Global Variables
SparkFun_APDS9960 apds = SparkFun_APDS9960();
uint8_t proximity_data = 0;

//COnnect to wifi
const char* ssid = "iPhone (Riku)";
const char* password = "RoTaProjekti2017qw";
const char* mqtt_server = "172.20.10.6";

long lastMsg = 0;
char msg1[100];
char msg0[100];
boolean rotta = 0;


boolean Info(){
    if (proximity_data > 30){
      
      Serial.println("rotta havaittu");
      return rotta = 1;
      }
    else{
      
      Serial.println("ei rottaa");
      return rotta = 0;
      }
    }

WiFiClient espClient;
PubSubClient client(espClient);


void setup_wifi() {

  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void haku(){
   Info();
   if (rotta==1){
    snprintf (msg1, 100, "Rotta");
      Serial.print("Publish message: ");
     Serial.println(msg1);
    client.publish("sensori", msg1);
    }
  else{
    snprintf (msg0, 100, "Ei rottaa");
    Serial.print("Publish message: ");
    Serial.println(msg0);
    client.publish("sensori", msg0);
    }
  }

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  // Switch on the LED if an 1 was received as first character
  if ((char)payload[0] == '1') {
    digitalWrite(BUILTIN_LED, LOW);
  haku();
  // Turn the LED on (Note that LOW is the voltage level
    // but actually the LED is on; this is because
    // it is acive low on the ESP-01)
  } else {
    digitalWrite(BUILTIN_LED, HIGH);  // Turn the LED off by making the voltage HIGH
  }

}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      client.publish("sensori", "yhteys muodostettu");
      // ... and resubscribe
      client.subscribe("mqtt2");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void setup() {
  
  // Initialize Serial port
   pinMode(BUILTIN_LED, OUTPUT);     // Initialize the BUILTIN_LED pin as an output
   Serial.begin(9600);
  setup_wifi();
  client.setServer(mqtt_server, 1883); ///8883 secure mqtt
  client.setCallback(callback);
 
  Serial.println();
  Serial.println(F("------------------------------------"));
  Serial.println(F("SparkFun APDS-9960 - ProximitySensor"));
  Serial.println(F("------------------------------------"));
  
  // Initialize APDS-9960 (configure I2C and initial values)
  if ( apds.init() ) {
    Serial.println(F("APDS-9960 initialization complete"));
  } else {
    Serial.println(F("Something went wrong during APDS-9960 init!"));
  }
  
  // Adjust the Proximity sensor gain
  if ( !apds.setProximityGain(PGAIN_2X) ) {
    Serial.println(F("Something went wrong trying to set PGAIN"));
  }
  
  // Start running the APDS-9960 proximity sensor (no interrupts)
  if ( apds.enableProximitySensor(false) ) {
    Serial.println(F("Proximity sensor is now running"));
  } else {
    Serial.println(F("Something went wrong during sensor init!"));
  }
}


void loop() {
  
  // Read the proximity value
  if ( !apds.readProximity(proximity_data) ) {
    Serial.println("Error reading proximity value");
  } 
  else {
    Serial.print("Proximity: ");
    Serial.println(proximity_data);
    Info();
    if (!client.connected()) {
    reconnect();
  }
  client.loop();
  }
  long now = millis();
  if (now - lastMsg > 100) {
    lastMsg = now;
    if (rotta==1){
    snprintf (msg1, 100, "Rotta");
      Serial.print("Publish message: ");
     Serial.println(msg1);
    client.publish("sensori", msg1);
    }
    /*else{
    snprintf (msg0, 100, "Ei rottaa");
    Serial.print("Publish message: ");
    Serial.println(msg0);
    client.publish("sensori", msg0);
    }*/
    
  
  
  
  // Wait 2000 ms before next reading
  delay(2000);
      }
    }
