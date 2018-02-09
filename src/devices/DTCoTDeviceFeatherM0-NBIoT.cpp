/**
 * @file DTCoTDeviceFeatherM0-NBIoT.cpp
 * @description Class for management and operations for all NB-IoT devices
 * @author mm1 Technology GmbH
 * @copyright (C) 2017-2018 Deutsche Telekom AG- all rights reserved. 
 * @licence MIT licence
 */

#include "DTCoTSetup.h"

#if CONN_TYPE == NB_IOT

#include "DTCoTDeviceFeatherM0-NBIoT.h"

#include "utility/DTCoTDebugOutput.h"

using namespace DTCoT;


CoTConfigDeviceFeatherM0_NBIoT::CoTConfigDeviceFeatherM0_NBIoT ( 
	const char* serverIP
	, const unsigned short serverPort
	, const char* imsi
	, const char* password
	, Stream & serial
	, int resetPin)
	: CoTConfigDeviceNBIoT( serverIP, serverPort, 
		imsi, password, serial, resetPin)
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