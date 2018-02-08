/**
 * @file DTCoTDeviceGimasi.cpp
 * @description Class for management and operations for Gimasi NB-IoT device
 * @author mm1 Technology GmbH
 * @copyright (C) 2017-2018 Deutsche Telekom AG- all rights reserved. 
 * @licence MIT licence
 */

#include "DTCOTSetup.h"

#if CONN_TYPE == NB_IOT

#include "DTCoTDeviceGimasi.h"

#include "utility/DTCoTDebugOutput.h"

using namespace DTCoT;


CoTConfigDeviceGimasi::CoTConfigDeviceGimasi ( 
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