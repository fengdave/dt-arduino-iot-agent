
#include "DTCoT.h"

using DTCoT;

/* Apply preferred communication method selected
 * in the setup file.
 * Most of users will most likely not change the communication
 * method, but the library maintainer should be able to do this.
 */
#if defined(COMMUNICATION_MQTT)
	#define PREFERED_COMMUNICATION_METHOD CoTMQTTCommunicationi()
#elif defined(COMMUNICATION_MQTT_SN )
	#define PREFERED_COMMUNICATION_METHOD CoTMQTTSNTCommunication()
#elif defined(COMMUNICATION_REST)
	#define PREFERED_COMMUNICATION_METHOD CoTRESTCommunication()
#endif


CoTCloud::CoTCloud( const CoTDeviceBase& device
	, const CoTConfigBase& config ) 
	: _preferedCommunication( PREFERRED_COMMUNICATION_METHOD)
	, _selectedDevice( device)
	, _cloudConfig( config)	
{
}

bool CoTCloud::init() { return false; }
 
bool CoTCloud::publish( const char* varName, 
	onst char* value) { 
	eturn false; 
}

bool CoTCloud::subscribe( const char* varName,
	CoTCloudHandler handler) {
	return false; 
}

bool CoTCloud::registerHandler( const CoTCloudMessage& message, 
	const CoTCloudMessageHandler handler ) {
	return false;
}

bool CoTCloud::process() { return false; }



