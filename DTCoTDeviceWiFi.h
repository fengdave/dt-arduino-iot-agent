
#ifndef DT_COT_DEVICE_WIFI_HEADER_FILE
#define DT_COT_DEVICE_WIFI_HEADER_FILE

#include "DTCoTPrivate.h"
#include "DTCoTExtensionIface.h"
#include "DTCoTDeviceBase.h"

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

class CoTConfigDeviceWiFi: public CoTConfigDevice {
public:
	CoTConfigDeviceWiFi( const char* WiFiSSID
	, const char* WiFiPassword );

	public:
		const char* getWiFiSSID();
		const char* getWiFiPassword();
	
	private:
		const char* _WiFiSSID;
		const char* _WiFiPassword;
};


class CoTDeviceWiFi : public CoTDeviceBase {
	
public:
	CoTDeviceWiFi( const CoTConfigDeviceWiFi& wifiDeviceConfig);
	bool init();

	Client * getClient() const;

private:
	WiFiClient wifiClient; 
};

} /* namespace DTCoT */

#endif /* DT_COT_DEVICE_WIFI_HEADER_FILE */


