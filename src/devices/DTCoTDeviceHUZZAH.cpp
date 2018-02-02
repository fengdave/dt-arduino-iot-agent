/**
 * @file DTCoTDeviceHUZZAH.cpp
 * @description Basic setup and protocol to interact 
 * with the Deutsche Telekom Cloud of things MQTT-SN connector.
 * @author mm1 Technology GmbH
 * @copyright (C) 2018 Deutsche Telekom AG- all rights reserved. 
 * @licence MIT licence
 */

#include "DTCoTDeviceHUZZAH.h"

#include "utility/DTCoTDebugOutput.h"

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

 }

bool CoTDeviceHUZZAH::init() { 
	CoTDeviceWiFi::init();
		 DEBUG_PRINT("CoTDeviceHUZZAH::CoTDeviceHUZZAH");
	return false;
}

void CoTDeviceHUZZAH::errorHandler( const CoTHandlerParam& error )
{ }


