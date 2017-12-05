
#include <DTCoTDeviceHUZZAH.h>
#include <DTCoTMQTTCommunication.h>


// If you want to use a different wifi library from the default, ie WifiMulti, or
// use an offboard module,etc. you can override this class. 
DTCoT::DeviceWiFi device = DTCoT::DeviceAdafruitHUZZAH(); 
DTCoT::MQTTCommunication communication = DTCoT::MQTTCommunication(device); 


void setup() {
	Serial.println("Connecting to wifi...");
	device.begin("mm1-wifi", "password");
	Serial.println("Connected!");
	
	communication.send("temp", "25"); // Just provisional - we can setup a more universal protocol.
}

void loop() {
  /* Update cloud infrastructure client */

}