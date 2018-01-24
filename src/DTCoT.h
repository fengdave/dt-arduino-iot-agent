#ifndef DT_COT_HEADER_FILE 
#define DT_COT_HEADER_FILE 

#include "DTCoTSetup.h"
#include "protocols/DTCoTMqttSn-config.h"

#include "DTCoTPrivate.h"
#include "DTCoTExtensionIface.h"

#include "base-classes/DTCoTDeviceBase.h"

#ifdef WIFI_ENABLED

	#include "devices/DTCoTDeviceWiFi.h"
	#include "devices/DTCoTDeviceGPRS.h"
	#include "devices/DTCoTDeviceEthernet.h"


#elif defined(NB_IOT_ENABLED)

	#include "devices/DTCoTDeviceNBioT.h"


#elif defined(GSM_ENABLED)

	#include "devices/DTCotDeviceGPRS.h"
	#include "devices/DTCoTDevice32uFONA.h"


#endif

#ifdef HUZZAH_ENABLED

	#include "devices/DTCoTDeviceHUZZAH.h"

#elif defined(TUINO1_ENABLED)
	#include "devices/DTCoTDeviceGimasi.h"

#elif defined(FEATHER_M0_NBIOT)
	#include "devices/DTCoTDeviceFeatherM0-NBIoT.h"

#elif defined(FEATHER_M0_WIFI)
	#include "devices/DTCoTDeviceFeatherM0-WiFi.h"

#endif

#include "utility/DTCoTDebugOutput.h"

/* Library Public Interface 
 * ----------------------------
 */

namespace DTCoT {


/* Since we have only one cloud - there is no need to abstract it
 * TODO: ask client if he wants to be able to have multiple 
 *		cloud access (Azzure, DT, Adafruit)
 * If so - provid the abstraction hierarchy for the cloud too,
 * with this class as a "leaf" of the inheritance tree
*/
class CoTCloud {
public:
	CoTCloud(const CoTDeviceBase& device, const CoTConfigBase& cloudConfig );

public:
	bool init();

public:

	#ifdef COMMUNICATION_MQTT
	
		bool publish( const char* varName, const char* varValue);
		bool publish( const char* varName, unsigned long varValue);
		bool publish( const char* varName, double varValue);
	


    #endif

		bool subscribe( const char* varName, CoTHandler handler);
	
	#ifdef COMMUNICATION_MQTTSN
	
		int Mqttsn_RegisterTopic(char* topic, char valueType);
		bool publish( int topicId, const char* varValue);
		bool publish( int topicId, unsigned long varValue);
		bool publish( int topicId, double varValue);
	
	
	#endif

public:
	bool errorHandler( const CoTHandlerParam error );

public:
	bool process( );

private:
	const CoTDeviceBase& _selectedDevice;					/* M0/HUZZAH/FONA */
	PREFERED_COMMUNICATION_METHOD _preferedCommunication; /* MQTT/MQTT-SN/REST/AZURE*/

private:
	CoTCloud( const CoTCloud& );

};

} /* namespace DTCoT */



#endif /* DT_COT_HEADER_FILE */
