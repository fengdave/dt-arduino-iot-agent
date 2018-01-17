#ifndef DT_COT_HEADER_FILE 
#define DT_COT_HEADER_FILE 

#include "DTCoTSetup.h"

#include "DTCoTPrivate.h"
#include "DTCoTExtensionIface.h"

#include "DTCoTDeviceBase.h"

#ifdef WIFI_ENABLED

	#include "DTCoTDeviceWiFi.h"
	#include "DTCoTDeviceGPRS.h"
	#include "DTCoTDeviceEthernet.h"


#elif defined(NB_IOT_ENABLED)

	#include "DTCotDeviceGimasi.h"

#elif defined(GSM_ENABLED)

	#include "DTCotDeviceGPRS.h"
	#include "DTCoTDevice32uFONA.h"


#endif

#ifdef HUZZAH_ENABLED

	#include "DTCoTDeviceHUZZAH.h"

#elif defined(TUINO1_ENABLED)

	#include "DTCoTDeviceGimasi.h"

#endif

#include "DTCoTDebugOutput.h"

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
	bool publish( const char* varName, const char* varValue);
	bool publish( const char* varName, unsigned long varValue);
	bool publish( const char* varName, double varValue);
	
	bool subscribe( const char* varName, CoTHandler handler);

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
