/**
 * @file DTCoTDeviceFeatherM0-WiFi.cpp
 * @description Basic setup and protocol to interact 
 * with the Deutsche Telekom Cloud of things MQTT-SN connector.
 * @author Andreas Krause
 * @copyright (C) 2018 mm1 Technology GmbH - all rights reserved. 
 * @licence MIT licence
 * 
 * Find out more about mm1 Technology:
 * Company: http://mm1-technology.de/
 * GitHub:  https://github.com/mm1technology/
 */

#include "DTCoTDeviceFeatherM0-WiFi.h"

#include "utility/DTCoTDebugOutput.h"

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
