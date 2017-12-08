#include "DTCoTDeviceHUZZAH.h"

#include "DTCoTDebugOutput.h"

using namespace DTCoT;

#define DEBUG_PRINT(x) Serial.println(x) 

CoTConfigDeviceHUZZAH::CoTConfigDeviceHUZZAH ( 
	const char* WiFiSSID
	, const char* WiFiPassword )
	: CoTConfigDeviceWiFi( WiFiSSID, WiFiPassword) 
{
}

CoTDeviceHUZZAH::CoTDeviceHUZZAH( const CoTConfigDeviceHUZZAH& config)
	: CoTDeviceWiFi( config)
 {

 }

bool CoTDeviceHUZZAH::init() { 
	CoTDeviceWiFi::init();
		 DEBUG_PRINT("CoTDeviceHUZZAH::CoTDeviceHUZZAH");
	return false;
}

void CoTDeviceHUZZAH::errorHandler( const CoTHandlerParam& error )
{ }


