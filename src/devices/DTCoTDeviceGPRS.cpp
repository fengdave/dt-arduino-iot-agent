/**
 * @file DTCoTDeviceGPRS.cpp
 * @description Base class for management and operations for all GRPS devices
 * with the Deutsche Telekom Cloud of things MQTT-SN connector.
 * @author mm1 Technology GmbH
 * @copyright (C) 2017-2018 Deutsche Telekom AG- all rights reserved. 
 * @licence MIT licence
 */

#include "DTCoTPrivate.h"
#include "DTCoTDeviceGPRS.h"

using namespace DTCoT;

CoTConfigDeviceGPRS::CoTConfigDeviceGPRS( const char* APN
		, const char* userName
		, const char* password)
		: _APN( APN)
		, _userName( userName)
		, _password( password)
		, CoTConfigDevice() 
{ }

const char* CoTConfigDeviceGPRS::getAPN() { 
	return _APN; 
}

const char* CoTConfigDeviceGPRS::getUserName() { 
	return _userName; 
}

const char* CoTConfigDeviceGPRS::getPassword() { 
	return _password; 
}


CoTDeviceGPRS::CoTDeviceGPRS( 
	const CoTConfigDeviceGPRS& gprsConfig)
	: CoTDeviceBase( gprsConfig)
{ }

