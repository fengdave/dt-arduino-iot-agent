#ifndef DT_COT_DEVICE_FEATHER_M0_WIFI_HEADER_FILE
#define DT_COT_DEVICE_FEATHER_M0_WIFI_HEADER_FILE


#include "DTCOTSetup.h"

#include "DTCoTPrivate.h"
#include "DTCoTDeviceWiFi.h"

namespace DTCoT {

class CoTConfigDeviceFeatherM0_WiFi: public CoTConfigDeviceWiFi {
public:
	CoTConfigDeviceFeatherM0_WiFi( const char* WiFiSSID
		, const char* WiFiPassword  );
};


class CoTDeviceFeatherM0_WiFi : public CoTDeviceWiFi {
public:
	CoTDeviceFeatherM0_WiFi(  const CoTConfigDeviceFeatherM0_WiFi& cfg );

public:
	bool init();	

	void errorHandler( const CoTHandlerParam& error );
};

} /* namespace DTCoT */


#endif /* DT_COT_DEVICE_FEATHER_M0_HEADER_WIFI_FILE */
