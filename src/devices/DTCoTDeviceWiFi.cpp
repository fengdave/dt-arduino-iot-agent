/**
 * @file DTCoTDeviceWiFi.cpp
 * @description Base class for management and operations for all Wifi devices 
 * @author mm1 Technology GmbH
 * @copyright (C) 2017-2018 Deutsche Telekom AG- all rights reserved. 
 * @licence MIT licence
 */

#include "DTCoTPrivate.h"
#include "DTCoTDeviceWiFi.h"

#include "utility/DTCoTDebugOutput.h"

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
}


bool CoTDeviceWiFi::init() {
		DEBUG_PRINT("CoTDeviceWiFi::init");

	CoTConfigDeviceWiFi & config = (CoTConfigDeviceWiFi&)_deviceConfig;
	
    delay(10);

	DEBUG_PRINT("DTCoT::DeviceWiFi::begin");

	char out[256]; // @todo bounds checking
	sprintf(out, "Connecting to %s pwd %s... ", config.getWiFiSSID(), config.getWiFiPassword());
	DEBUG_PRINT(out);
	/*
	#if defined(ARDUINO_ARCH_SAMD)
 		// necessary because feather M0 need the ssid as not const instead of the huzzah
		#error "feather M0"
		char _feather_ssid[255];
		strcpy(_feather_ssid, config.getWiFiSSID());
		WiFi.begin(_feather_ssid, config.getWiFiPassword());
		
	#else 
		#error "ich komm doch hier her"
		WiFi.begin(config.getWiFiSSID(), config.getWiFiPassword());
	
	#endif
	*/
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
