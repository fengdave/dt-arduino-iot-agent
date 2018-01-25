/**
 * @file {{file}}
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

#ifndef DT_COT_DEVICE_FEATHER_M0_WIFI_HEADER_FILE
#define DT_COT_DEVICE_FEATHER_M0_WIFI_HEADER_FILE


#include "DTCOTSetup.h"

#include "DTCoTPrivate.h"
#include "DTCoTDeviceWiFi.h"

namespace DTCoT {

	/**
	 * Config class for Feather M0 WiFi setup
	 */
class CoTConfigDeviceFeatherM0_WiFi: public CoTConfigDeviceWiFi {
public:
   /**
    * Constructor
    * @param WiFiSSID wifi AP name
    * @param WiFiPassword password for the wifi network
    */
	CoTConfigDeviceFeatherM0_WiFi( const char* WiFiSSID
		, const char* WiFiPassword  );
};



/**
 * Feather M0 board running WiFi connection
 */
class CoTDeviceFeatherM0_WiFi : public CoTDeviceWiFi {
public:
/**
 * constructor
* @param cfg configuration class to setup the device.
*/
	CoTDeviceFeatherM0_WiFi(  const CoTConfigDeviceFeatherM0_WiFi& cfg );

public:
	bool init();	

	void errorHandler( const CoTHandlerParam& error );
};

} /* namespace DTCoT */


#endif /* DT_COT_DEVICE_FEATHER_M0_HEADER_WIFI_FILE */
