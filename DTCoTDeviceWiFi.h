#ifndef DT_COT_DEVICE_WIFI_HEADER_FILE
#define DT_COT_DEVICE_WIFI_HEADER_FILE

#include "DTCoTPrivate.h"
#include "DTCoTExtensionIface.h"

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

class CoTDeviceWiFi: public CoTDeviceBase { 
public:
	CoTDeviceWiFi( const CoTConfigDeviceWiFi& wifiDeviceConfig);
};

} /* namespace DTCoT */

#endif /* DT_COT_DEVICE_WIFI_HEADER_FILE */

