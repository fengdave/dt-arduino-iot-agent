/**
 * @file DTCoTDeviceNBIoT.cpp
 * @description Base class for management and operations for all NB-IoT devices
 * @author mm1 Technology GmbH
 * @copyright (C) 2017-2018 Deutsche Telekom AG- all rights reserved. 
 * @licence MIT licence
 */

#include "DTCOTSetup.h"

#if CONN_TYPE == NB_IOT

#include "DTCoTPrivate.h"
#include "devices/DTCoTDeviceNBIoT.h"

#include "utility/DTCoTDebugOutput.h"

using namespace DTCoT;

CoTConfigDeviceNBIoT::CoTConfigDeviceNBIoT(
	const char* serverIP
	, const unsigned short serverPort
	, const char* imsi
	, const char* password
	, Stream& serial
	, int resetPin )
	:  _serverIP(serverIP), _serverPort(serverPort), 
		_imsi(imsi), _password(password), _serial(serial), _resetPin(resetPin), CoTConfigDevice()
	
{
	//DEBUG_PRINT("CoTConfigDeviceNBIoT::CoTConfigDeviceNBIoT");
}

const char* CoTConfigDeviceNBIoT::getServerIP() { 
	return _serverIP;
}

const unsigned short CoTConfigDeviceNBIoT::getServerPort() {
	return _serverPort;
}


const char* CoTConfigDeviceNBIoT::getIMSI() { 
	return _imsi;
}


const char* CoTConfigDeviceNBIoT::getPassword() { 
	return _password; 
}


Stream & CoTConfigDeviceNBIoT::getSerial() {
	return _serial;
}

int CoTConfigDeviceNBIoT::getResetPin() {
	return _resetPin;
}

CoTDeviceNBIoT::CoTDeviceNBIoT(	 CoTConfigDeviceNBIoT& nbiotConfig)
	: CoTDeviceBase( nbiotConfig)
		
	,_nbiotClient (NbiotClient( nbiotConfig.getServerIP()
				, nbiotConfig.getServerPort()
				, nbiotConfig.getIMSI()
				, nbiotConfig.getPassword()
				, nbiotConfig.getSerial()
				, nbiotConfig.getResetPin()
				))
					
					
{
}

bool CoTDeviceNBIoT::init() {
		DEBUG_PRINT("CoTDeviceNBIoT::init");

	/* TODO: Initialize Gimasi modem here */
		
	_nbiotClient.init();	
		
	
	return false;
}


Client * CoTDeviceNBIoT::getClient() const {
	return (Client*)(&_nbiotClient);
}


#endif