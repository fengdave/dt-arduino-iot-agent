#include "DTCoT.h"

using namespace DTCoT;


CoTDeviceBase::CoTDeviceBase( const CoTConfigBase& deviceConfig)
	:_deviceConfig( deviceConfig) { }


/* Apply preferred communication method selected
 * in the setup file.
 * Most of users will most likely not change the communication
 * method, but the library maintainer should be able to do this.
 */
#if defined(COMMUNICATION_MQTT)
	#define PREFERED_COMMUNICATION_METHOD CoTMQTTCommunication
#elif defined(COMMUNICATION_MQTT_SN )
	#define PREFERED_COMMUNICATION_METHOD CoTMQTTSNTCommunication
#elif defined(COMMUNICATION_REST)
	#define PREFERED_COMMUNICATION_METHOD CoTRESTCommunication
#endif


#if defined(AUTHENTICATION_TLS)
	#define PREFERED_AUTHENTICATION_METHOD CoTAuthTLS
#elif defined(AUTHENTICATION_FINGERPRINT )
	#define PREFERED_COMMUNICATION_METHOD CoTAuthFingerprint
#elif defined(AUTHENTICATION_NONE)
	#define PREFERED_AUTHENTICATION_METHOD CoTAuthNone
#endif




CoTCloud::CoTCloud( const CoTDeviceBase& device
	, const CoTConfigBase& config ) 
	: _selectedDevice( device)
	, _cloudConfig( config)
	, _preferedCommunication( 
		PREFERED_COMMUNICATION_METHOD ( 
			device
			, config
			, PREFERED_AUTHENTICATION_METHOD( )
		)
	)
{

}

bool CoTCloud::init() { return false; }
 
bool publish( const char* varName, const char* varValue) { return false; }
bool publish( const char* varName, unsigned long varValue) { return false; }
bool publish( const char* varName, double varValue) { return false; }

void CoTCloud::errorHandler( const CoTHandlerParam error) {
	return false;
}

bool CoTCloud::process() { return false; }


