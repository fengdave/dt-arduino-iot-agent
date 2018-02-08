/**
 * @file DTCoTDeviceWiFi.h
 * @description header file for base class for management and operations for all Wifi devices 
 * @author mm1 Technology GmbH
 * @copyright (C) 2017-2018 Deutsche Telekom AG- all rights reserved. 
 * @licence MIT licence
 */

#ifndef DT_COT_DEVICE_WIFI_HEADER_FILE
#define DT_COT_DEVICE_WIFI_HEADER_FILE

#include "DTCoTPrivate.h"
#include "DTCoTExtensionIface.h"
#include "base-classes/DTCoTDeviceBase.h"

// @todo - derive this!
#if defined(ESP8266)
	#include <ESP8266WiFi.h>
	//#error "ESP8266"
#elif defined(ARDUINO_ARCH_SAMD) 
	// for Feather M0
	#include <WiFi101.h>
	//#error "Feather M0"
	
#else
	//* !!! unimplemented !!!	
	//#error "the normal case"
	#include <WiFi.h>
		
#endif


namespace DTCoT {

   /**
    * Config class for generic WiFi device.
    */
class CoTConfigDeviceWiFi: public CoTConfigDevice {
public:
	
	/**
	 * constructor
	 * param WiFiSSID wifi AP
	 * param WiFiPassword wifi password
	 */
	CoTConfigDeviceWiFi( const char* WiFiSSID
	, const char* WiFiPassword );

	public:
		/**
		 * Getter for wifi SSID
		*/
		const char* getWiFiSSID();
		
		/**
		 * Getter for password
		*/
		const char* getWiFiPassword();
	
	private:
		const char* _WiFiSSID;
		const char* _WiFiPassword;
};

/**
 * Device class for generic WiFi device.
 */
class CoTDeviceWiFi : public CoTDeviceBase {
	
public:
	CoTDeviceWiFi( const CoTConfigDeviceWiFi& wifiDeviceConfig);
	bool init();

	/**
	 * Get the Arduino standard Client interface for this device
	 */
	Client * getClient() const;

private:
	WiFiClient wifiClient; 
};

} /* namespace DTCoT */

#endif /* DT_COT_DEVICE_WIFI_HEADER_FILE */


