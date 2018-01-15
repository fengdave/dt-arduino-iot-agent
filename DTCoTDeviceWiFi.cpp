
#include "DTCoTPrivate.h"
#include "DTCoTDeviceWiFi.h"

#include "DTCoTDebugOutput.h"

using namespace DTCoT;

#define DEBUG_PRINT(x) Serial.println(x) 

CoTConfigDeviceWiFi::CoTConfigDeviceWiFi(
	const char* WiFiSSID
	, const char* WiFiPassword )
	: _WiFiSSID( WiFiSSID)
	, _WiFiPassword( WiFiPassword)
	, CoTConfigDevice( )
{
}

const char* CoTConfigDeviceWiFi::getWiFiSSID() { 
	return _WiFiSSID;
}

const char* CoTConfigDeviceWiFi::getWiFiPassword() { 
	return _WiFiPassword; 
}


CoTDeviceWiFi::CoTDeviceWiFi(	const CoTConfigDeviceWiFi& wifiConfig)
	: CoTDeviceBase( wifiConfig)
{
}


bool CoTDeviceWiFi::init() {
		DEBUG_PRINT("CoTDeviceWiFi::init");

	CoTConfigDeviceWiFi & config = (CoTConfigDeviceWiFi&)_deviceConfig;
	
    delay(10);

	DEBUG_PRINT("DTCoT::DeviceWiFi::begin");

	char out[256]; // @todo bounds checking
	sprintf(out, "Connecting to %s pwd %s... ", config.getWiFiSSID(), config.getWiFiPassword());
	DEBUG_PRINT(out);

    WiFi.begin(config.getWiFiSSID(), config.getWiFiPassword());

    while (WiFi.status() != WL_CONNECTED) {
		/* TODO: Check re-tries here, report with "false" return value */
		DEBUG_PRINT("connecting...");
	  	delay(500);
    }

	DEBUG_PRINT("DTCoT::DeviceWiFi::connected!");
	
	return true;
}

Client * DTCoT::CoTDeviceWiFi::getClient() const {
	return (Client*)(&wifiClient);
}
