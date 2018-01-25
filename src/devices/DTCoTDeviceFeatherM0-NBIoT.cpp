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

#include "DTCOTSetup.h"

#if CONN_TYPE == NB_IOT

#include "DTCoTDeviceFeatherM0-NBIoT.h"

#include "utility/DTCoTDebugOutput.h"

using namespace DTCoT;

#define DEBUG_PRINT(x) Serial.println(x) 

CoTConfigDeviceFeatherM0_NBIoT::CoTConfigDeviceFeatherM0_NBIoT ( 
	const char* serverIP
	, const unsigned short serverPort
	, const char* imsi
	, const char* password)
	: CoTConfigDeviceNBIoT( serverIP, serverPort, 
		imsi, password)
{
	
   
}

CoTDeviceFeatherM0_NBIoT::CoTDeviceFeatherM0_NBIoT(  CoTConfigDeviceFeatherM0_NBIoT& config)
	: CoTDeviceNBIoT( config)
 {
 }

bool CoTDeviceFeatherM0_NBIoT::init() {
	CoTDeviceNBIoT::init();
	DEBUG_PRINT("CoTDeviceFeatherM0_NBIoT::CoTDeviceFeatherM0_NBIoT");
	
	return false;
}

void CoTDeviceFeatherM0_NBIoT::errorHandler( const CoTHandlerParam& error )
{ }


#endif