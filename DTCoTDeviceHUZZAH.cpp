#include "DTCoTDeviceHUZZAH.h"

using namespace DTCoT;

CoTConfigDeviceHUZZAH::CoTConfigDeviceHUZZAH ( 
	const char* WiFiSSID
	, const char* WiFiPassword )
	: CoTConfigDeviceWiFi( WiFiSSID, WiFiPassword) 
{
}

CoTDeviceHUZZAH::CoTDeviceHUZZAH( const CoTConfigDeviceHUZZAH& config)
	: CoTDeviceWiFi( config)
 { }

bool CoTDeviceHUZZAH::init() { return false; }

void CoTDeviceHUZZAH::errorHandler( const CoTHandlerParam& error )
{ }


