#include "DTCoTDeviceHUZZAH.h"

#include "DTCoTDebugOutput.h"

using namespace DTCoT;

CoTConfigDeviceHUZZAH::CoTConfigDeviceHUZZAH ( 
	const char* WiFiSSID
	, const char* WiFiPassword )
	: CoTConfigDeviceWiFi( WiFiSSID, WiFiPassword) 
{
}

CoTDeviceHUZZAH::CoTDeviceHUZZAH( const CoTConfigDeviceHUZZAH& config)
	: CoTDeviceWiFi( config)
 {
	 DEBUG_PRINT("CoTDeviceHUZZAH::CoTDeviceHUZZAH");
 }

bool CoTDeviceHUZZAH::init() { return false; }

void CoTDeviceHUZZAH::errorHandler( const CoTHandlerParam& error )
{ }


