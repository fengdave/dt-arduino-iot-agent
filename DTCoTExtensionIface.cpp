#include "DTCoTExtensionIface.h"

using namespace DTCoT;

CoTConfigCommunicationMQTT::CoTConfigCommunicationMQTT( 
	const char* serverUrl
	, unsigned long portNumber 
	, const char* password
	, const char* userId )
	: _serverUrl( serverUrl)
	, _portNumber( portNumber)
	, _password( password)
	, _userId( userId)
	, CoTConfigBase( )
{ }

const char* CoTConfigCommunicationMQTT::getUrl() { 
	return _serverUrl;
}

unsigned long CoTConfigCommunicationMQTT::getPortNumber() { 
	return _portNumber;
}

const char* CoTConfigCommunicationMQTT::getPassword() { 
	return _password;
}

const char* CoTConfigCommunicationMQTT::getUserId() { 
	return _userId;
}


CoTCommunicationMQTT::CoTCommunicationMQTT(
	const CoTDeviceBase& device
	, const CoTConfigBase& config
	, const CoTAuthBase& authentication )
	: CoTCommunicationBase( device, config, authentication) 
{
}

CoTConfigDevice::CoTConfigDevice(): CoTConfigBase() { }

