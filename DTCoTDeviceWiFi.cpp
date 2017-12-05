#include <DTCoTDeviceWiFi.h>


#define DEBUG_PRINT(x) Serial.println(x) // @todo - make this universal?

/*DeviceWiFi::DeviceWiFi() {

}*/

void DTCoT::DeviceWiFi::begin(char * ssid, char * password) {
    delay(10);

	DEBUG_PRINT("DTCoT::DeviceWiFi::begin");

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {

		DEBUG_PRINT("connecting...");
	  	delay(500);
    }

	DEBUG_PRINT("DTCoT::DeviceWiFi::connected!");
}

Client * DTCoT::DeviceWiFi::getClient() {
	return &wifiClient;
}
