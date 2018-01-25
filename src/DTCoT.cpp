/**
 * @file DTCoT.cpp
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

#include "DTCoT.h"

using namespace DTCoT;



#if defined(AUTHENTICATION_TLS)
	#define PREFERED_AUTHENTICATION_METHOD CoTAuthTLS
#elif defined(AUTHENTICATION_FINGERPRINT )
	#define PREFERED_COMMUNICATION_METHOD CoTAuthFingerprint
#elif defined(AUTHENTICATION_NONE)
	#define PREFERED_AUTHENTICATION_METHOD CoTAuthNone
#endif

const CoTAuthBase& getCloudAuthMethodInst() {
	static PREFERED_AUTHENTICATION_METHOD cloudAuthMethod;
	return cloudAuthMethod;
}

CoTCloud::CoTCloud( const CoTDeviceBase& device
	, const CoTConfigBase& config ) 
	: _selectedDevice( device)
	, _preferedCommunication ( 
			device
			, config
			, getCloudAuthMethodInst()
		)
{ }

bool CoTCloud::init() { 
	 DEBUG_PRINT("CoTCloud::init");
	 delay(1000);
	_preferedCommunication.init();
}

#ifdef COMMUNICATION_MQTT

bool CoTCloud::publish( const char* varName
	, const char* varValue) { 
		_preferedCommunication.publish(varName, varValue);
		return true;
}

bool CoTCloud::publish( const char* varName
	, unsigned long varValue) { 
	return false; 
}

bool CoTCloud::publish( const char* varName
	, double varValue) { 
	return false; 
}



#endif

bool CoTCloud::subscribe( const char* varName
		, const CoTHandler handler ) {
	return false;
}

#ifdef COMMUNICATION_MQTTSN
int CoTCloud::Mqttsn_RegisterTopic(char* topic, char valueType) {
	
 	return _preferedCommunication.Mqttsn_RegisterTopic(topic, valueType);
	
	
}

bool CoTCloud::publish( int topicId
	, const char* varValue) { 
		_preferedCommunication.publish(topicId, varValue);
		return true;
}

bool CoTCloud::publish( int topicId
	, unsigned long varValue) { 
	return false; 
}

bool CoTCloud::publish( int topicId
	, double varValue) { 
	return false; 
}
#endif


bool CoTCloud::errorHandler( const CoTHandlerParam error) {
	return false;
}

bool CoTCloud::process() { return false; }


