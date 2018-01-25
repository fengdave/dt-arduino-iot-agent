/**
 * @file DTCoTDeviceGPRS.h
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

#ifndef DT_COT_DEVICE_GPRS_HEADER_FILE
#define DT_COT_DEVICE_GPRS_HEADER_FILE

#include "DTCoTPrivate.h"
#include "DTCoTExtensionIface.h"

namespace DTCoT {

   /**
    * Config class for generic GPRS capable device.
    */
class CoTConfigDeviceGPRS: public CoTConfigDevice {
public:
	CoTConfigDeviceGPRS( const char* APN
		, const char* userName
		, const char* password);

public:
	const char* getAPN();
	const char* getUserName();
	const char* getPassword();

private:
	const char* _APN;
	const char* _userName;
	const char* _password;	
};

/**
 * Device class for generic GPRS capable device.
 */
class CoTDeviceGPRS: public CoTDeviceBase { 
public:
	CoTDeviceGPRS( const CoTConfigDeviceGPRS& gprsConfig);

};

} /* namespace DTCoT */

#endif /* DT_COT_DEVICE_GPRS_HEADER_FILE */

