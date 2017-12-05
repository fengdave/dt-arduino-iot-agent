#ifndef CoTDeviceWiFi_h_
#define CoTDeviceWiFi_h_

#include <DTCoTDeviceBase.h>

#include <String.h>

// @todo - derive this!
#if defined(ESP8266)
#include <ESP8266WiFi.h>
#else
unimplemented
#include <WiFi.h>
#endif

namespace DTCoT {

class DeviceWiFi : public DeviceBase {
	
public:
	void begin(char * ssid, char * password);

	virtual Client * getClient();

private:
	WiFiClient wifiClient;
};

}

#endif