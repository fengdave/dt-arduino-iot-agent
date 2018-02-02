/**
 * @file DTCoTDeviceFeatherM0-WiFi.cpp
 * @description Basic setup and protocol to interact 
 * with the Deutsche Telekom Cloud of things MQTT-SN connector.
 * @author mm1 Technology GmbH
 * @copyright (C) 2018 Deutsche Telekom AG- all rights reserved. 
 * @licence MIT licence
 */

#include "DTCoTDeviceFeatherM0-WiFi.h"

#include "utility/DTCoTDebugOutput.h"

using namespace DTCoT;


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
