
#include "DTCoTPrivate.h"
#include "DTCoTDeviceWiFi.h"

#include "DTCoTDebugOutput.h"

using namespace DTCoT;

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
	DEBUG_PRINT("CoTDeviceWiFi::CoTDeviceWiFi");
}


bool CoTDeviceWiFi::init() {
		DEBUG_PRINT("CoTDeviceWiFi::init");
	
	CoTConfigDeviceWiFi & config = (CoTConfigDeviceWiFi&)_deviceConfig;
	
    delay(10);

	DEBUG_PRINT("DTCoT::DeviceWiFi::begin");

    WiFi.begin(config.getWiFiSSID(), config.getWiFiPassword());

    while (WiFi.status() != WL_CONNECTED) {

		DEBUG_PRINT("connecting...");
	  	delay(500);
    }

	DEBUG_PRINT("DTCoT::DeviceWiFi::connected!");
}

/*Client * DTCoT::CoTDeviceWiFi::getClient() const {
	return (Client*)(&wifiClient);
}*/
