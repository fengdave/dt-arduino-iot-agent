
#include <DTCoTDeviceHUZZAH.h>
#include <DTCoTDeviceWifi.h>


// If you want to use a different wifi library from the default, ie WifiMulti, or
// use an offboard module,etc. you can override this class. 
DTCoT::DeviceWiFi device = DTCoT::DeviceAdafruitHUZZAH(); 


void setup() {
	Serial.println("Connecting to wifi...");
	device.connect("mm1-wifi", "password");
	Serial.println("Connected!");
}

void loop() {
  /* Update cloud infrastructure client */

}