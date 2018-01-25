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

