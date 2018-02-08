/**
 * @file DTCoT.h
 * @description Header file for entral class for interaction with Telekom Cloud of Things
 * @author mm1 Technology GmbH
 * @copyright (C) 2017-2018 Deutsche Telekom AG- all rights reserved. 
 * @licence MIT licence
 */

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
 *		cloud access (Azure, DT, Adafruit)
 * If so - provid the abstraction hierarchy for the cloud too,
 * with this class as a "leaf" of the inheritance tree
*/
	
/**
* High-level object for accessing the service.
* To use the CoT service, you should instantiate this object. It allows you to publish and subscribe variables
* hosted on the CoT service.
*
*/
class CoTCloud {
public:
	/**
	* Instantiate the CoT system
	* This will prepare the system using the given device and configuration parameters.
	* @param device the device to connect uisng. This should match the hardware platform you are compiling for
	* @param cloudConfig configuration settings for the connection.
	*/
	CoTCloud(const CoTDeviceBase& device, const CoTConfigBase& cloudConfig );

public:
	/**
	* Initialise the CoT system
	* Begin interacting with the CoT service.
	*/
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
