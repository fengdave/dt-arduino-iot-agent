#ifndef CoTDeviceWiFi_h_
#define CoTDeviceWiFi_h_

#include <DTCoTDeviceBase.h>

#include <String.h>
#include <WiFi.h>

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