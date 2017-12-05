
#include <DTCoTDeviceHUZZAH.h>
#include <DTCoTMQTTCommunication.h>

// NOTE - these classes are called internally from the CoTCloud module - but we can separate them out for testing

// MQTT settings
#define mqtt_server "io.adafruit.com"
#define mqtt_username "jimmyio"
#define mqtt_key "eaa66e7fe19c41e9836bdeec82e1fca9"

// WiFi settings
#define wifi_ssid "mm1-technology-gast"
#define wifi_password "We2RF1tec"

// If you want to use a different wifi library from the default, ie WifiMulti, or
// use an offboard module,etc. you can override this class. 
DTCoT::DeviceWiFi device = DTCoT::DeviceAdafruitHUZZAH(); 
DTCoT::MQTTCommunication communication = DTCoT::MQTTCommunication(device, mqtt_server, mqtt_username, mqtt_key); 


void setup() {
  Serial.begin(115200);
	Serial.println("Connecting to wifi...");
	device.begin(wifi_ssid, wifi_password);
	Serial.println("Connected!");
  communication.begin();
}

void loop() {
  static int loops;
  loops++;
  /* Update cloud infrastructure client */
    Serial.println("Sending to MQTT...");
    communication.send("newlib", loops&1 ? "Flip" : "Flop"); // Just provisional - we can setup a more universal protocol.
    delay(10000);

}
