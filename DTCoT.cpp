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
	_preferedCommunication.init();
}
 
bool CoTCloud::publish( const char* varName
	, const char* varValue) { 
		return false;
}

bool CoTCloud::publish( const char* varName
	, unsigned long varValue) { 
	return false; 
}

bool CoTCloud::publish( const char* varName
	, double varValue) { 
	return false; 
}

bool CoTCloud::subscribe( const char* varName
	, const CoTHandler handler ) { 
	return false; 
}

bool CoTCloud::errorHandler( const CoTHandlerParam error) {
	return false;
}

bool CoTCloud::process() { return false; }


