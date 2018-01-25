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

#include "DTCoTDeviceGimasi.h"

#include "utility/DTCoTDebugOutput.h"

using namespace DTCoT;

#define DEBUG_PRINT(x) Serial.println(x) 

CoTConfigDeviceGimasi::CoTConfigDeviceGimasi ( 
	const char* serverIP
	, const unsigned short serverPort
	, const char* imsi
	, const char* password)
	: CoTConfigDeviceNBIoT( serverIP, serverPort, 
		imsi, password)
{
	
   
}

CoTDeviceGimasi::CoTDeviceGimasi(  CoTConfigDeviceGimasi& config)
	: CoTDeviceNBIoT( config)
 {
 }

bool CoTDeviceGimasi::init() {
	CoTDeviceNBIoT::init();
	DEBUG_PRINT("CoTDeviceGimasi::CoTDeviceGimasi");
	
	return false;
}

void CoTDeviceGimasi::errorHandler( const CoTHandlerParam& error )
{ }


#endif