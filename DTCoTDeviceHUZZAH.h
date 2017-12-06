#ifndef DT_COT_DEVICE_HUZZAH_HEADER_FILE
#define DT_COT_DEVICE_HUZZAH_HEADER_FILE

#include "DTCoTPrivate.h"
#include "DTCoTDeviceWiFi.h"

namespace DTCoT {

class CoTConfigDeviceHUZZAH: public CoTConfigDeviceWiFi {
public:
	CoTConfigDeviceHUZZAH( const char* WiFiSSID
		, const char* WiFiPassword );
};


class CoTDeviceHUZZAH : public CoTDeviceWiFi {
public:
	CoTDeviceHUZZAH( const CoTConfigDeviceHUZZAH& cfg );

public:
	bool init();	

	void errorHandler( const CoTHandlerParam& error );
};

} /* namespace DTCoT */

#endif /* DT_COT_DEVICE_ADAFRUIT_FONA_HEADER_FILE */
