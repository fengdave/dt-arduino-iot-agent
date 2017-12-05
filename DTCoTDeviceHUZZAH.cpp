#include "DTCoTDeviceHUZZAH.h"

using namespace DTCoT;

CoTConfigDeviceHUZZAH::CoTConfigDeviceHUZZAH ( 
	const char* wifiSsid
	, const char* wifiPassword )
	: CoTConfigBase() 
{

}

CoTDeviceHUZZAH::CoTDeviceHUZZAH( const CoTConfigDeviceHAZZAH& config):
	CoTDeviceWiFi( config)
 { }

CoTDeviceHUZZAH::init() { return false; }

void CoTDeviceHUZZAH::registerHandler( const CoTCloudMessage& message
		, const CoTCloudMessaheHandler& handler ) 
{
}


