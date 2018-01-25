/**
 * @file DTCoTDeviceHUZZAH.h
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

#ifndef DT_COT_DEVICE_HUZZAH_HEADER_FILE
#define DT_COT_DEVICE_HUZZAH_HEADER_FILE

#include "DTCoTPrivate.h"
#include "DTCoTDeviceWiFi.h"

namespace DTCoT {

   /**
    * Config class for HUZZAH ESP8266 device.
    */
class CoTConfigDeviceHUZZAH: public CoTConfigDeviceWiFi {
public:
	CoTConfigDeviceHUZZAH( const char* WiFiSSID
		, const char* WiFiPassword );
};


/**
 * Device class for HUZZAH ESP8266. This class should also work for any other ESP8266 based board running wifi.
 */
class CoTDeviceHUZZAH : public CoTDeviceWiFi {
public:
	CoTDeviceHUZZAH( const CoTConfigDeviceHUZZAH& cfg );

public:
	bool init();	

	void errorHandler( const CoTHandlerParam& error );
};

} /* namespace DTCoT */

#endif /* DT_COT_DEVICE_ADAFRUIT_FONA_HEADER_FILE */
