#include "DTCoTDeviceFeatherM0-WiFi.h"

#include "DTCoTDebugOutput.h"

using namespace DTCoT;

#define DEBUG_PRINT(x) Serial.println(x) 

CoTConfigDeviceFeatherM0_WiFi::CoTConfigDeviceFeatherM0_WiFi ( 
	const char* WiFiSSID
	, const char* WiFiPassword )
	: CoTConfigDeviceWiFi( WiFiSSID, WiFiPassword) 
{
}

CoTDeviceFeatherM0_WiFi::CoTDeviceFeatherM0_WiFi( const CoTConfigDeviceFeatherM0_WiFi& config)
	: CoTDeviceWiFi( config)
 {

 }

bool CoTDeviceFeatherM0_WiFi::init() { 
	CoTDeviceWiFi::init();
		 DEBUG_PRINT("CoTDeviceFeatherM0_WiFi::CoTDeviceFeatherM0_WiFi");
	return false;
}

void CoTDeviceFeatherM0_WiFi::errorHandler( const CoTHandlerParam& error )
{ }
