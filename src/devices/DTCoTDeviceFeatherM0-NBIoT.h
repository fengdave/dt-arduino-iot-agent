/**
 * @file DTCoTDeviceFeatherM0-NBIoT.h
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

#ifndef DT_COT_DEVICE_FEATHER_M0_NBIOT_HEADER_FILE
#define DT_COT_DEVICE_FEATHER_M0_NBIOT_HEADER_FILE


#include "DTCOTSetup.h"

#if CONN_TYPE == NB_IOT

#include "DTCoTPrivate.h"
#include "devices/DTCoTDeviceNBIoT.h"

namespace DTCoT {

	/**
	* Hardware interface representing the Feather M0 board running NBIoT communications.
	*/
class CoTConfigDeviceFeatherM0_NBIoT: public CoTConfigDeviceNBIoT {
public:
   /**
    * Constructor
    * @param serverIP IP address of the NBIoT server
    * @param serverPort port of the NBIoT server
    * @param imsi IMSI UID of this device
    * @param password matching password for the connection
    */
	CoTConfigDeviceFeatherM0_NBIoT(const char* serverIP, const unsigned short serverPort, const char* imsi, const char* password, Stream& serial, int resetPin );
};


/**
 * Feather M0 board running NBIoT connection
 */
class CoTDeviceFeatherM0_NBIoT : public CoTDeviceNBIoT {
public:
	/**
	 * constructor
	* @param cfg configuration class to setup the device.
	*/
	CoTDeviceFeatherM0_NBIoT(  CoTConfigDeviceFeatherM0_NBIoT& cfg );

public:
	bool init();	

	/**
	 * Called on an error conditions.
	*/
	void errorHandler( const CoTHandlerParam& error );
};

} /* namespace DTCoT */

#endif

#endif /* DT_COT_DEVICE_FEATHER_M0_HEADER_NBIOT_FILE */
