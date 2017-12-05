
#include <DTCoTDeviceHUZZAH.h>
#include <DTCoTMQTTCommunication.h>


// If you want to use a different wifi library from the default, ie WifiMulti, or
// use an offboard module,etc. you can override this class. 
DTCoT::DeviceWiFi device = DTCoT::DeviceAdafruitHUZZAH(); 
DTCoT::MQTTCommunication communication = DTCoT::MQTTCommunication(device); 


void setup() {
  Serial.begin(115200);
	Serial.println("Connecting to wifi...");
	device.begin("mm1-technology-gast", "We2RF1tec");
	Serial.println("Connected!");
}

void loop() {
  /* Update cloud infrastructure client */
    Serial.println("Sending to MQTT...");
    communication.send("temp-newlib", "25"); // Just provisional - we can setup a more universal protocol.
    delay(10000);

}
