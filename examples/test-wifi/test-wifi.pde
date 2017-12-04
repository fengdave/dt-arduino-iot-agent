#include "DTCoT.h"

// If you want to use a different wifi library from the default, ie WifiMulti, or
// use an offboard module,etc. you can override this class. 
CoT::Device blinkerDevice = CoT::DeviceAdafruitHUZZAH(); 


void setup() {
	Serial.println("Connecting to wifi...");
	blinkerDevice.connect("mm1-wifi", "password");
	Serial.println("Connected!");
}

void loop() {
  /* Update cloud infrastructure client */

}
