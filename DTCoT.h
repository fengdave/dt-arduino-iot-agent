#ifndef DTCoT_HEADER_FILE
#define DTCoT_HEADER_FILE	

/* Static compile-time library setup definitions */

#include "DTCoTSetup.h"

namespace DTCoT 
{

/* DTCoT Library Base Classes (will not be instantiated directly; 
 * to be used in platform/config/communication-independent code)
 * ----------------------------
 */
class CoTConfigBase { };

class CoTDeviceBase {
public:
	CoTDeviceBase( const CoTConfigBase& deviceConfig);

public:
	virtual bool init() = 0;
	virtual void registerHandler( const CoTCloudMessage& message
		, const CoTCloudMessaheHandler& handler ) = 0;

private:
	const CoTConfigBase& _deviceConfig;
};

/* Base class to distinguish between authentication details (like TLS/Fingerprint) */
class CoTAuthBase { };

class CoTCommunicationBase {
private:
	const CoTAuthBase& _authenticationConfig;
	const CoTConfigBase& _communicationConfig;
}; 


/* Library Extension Interface 
 * ----------------------------
 */

/* Configuration for every supported device */
class CoTDeviceConfig: public CoTConfigBase { };

/* Configuration for every communication method */
class CoTCommunicationConfig: public CoTConfigBase { };

/* Configurationf or any authentication */
class CoTAuthConfig: public CoTConfigBase { };

/* Types of devices we support (by connectivity criteria) */
class CoTDeviceGPRS: public CoTDeviceBase { 
};

class CoTDeviceWiFi: public CoTDeviceBase { 
public:
	CoTDeviceWiFi( const CoTDeviceConfig& deviceConfig);
};

class CoTDeviceEthernet: public CoTDeviceBase { 
};

/* Communication types we support */
/* Nothe: communication type does not belong to the Library public interface.
 * 	It should be hidden and selectable compile-time ( #define in DTCoTSetup.h? )
 */
class CoTMQTTCommunication: public CoTCommunicationBase { };
class CoTMQTTSNCommunication: public CoTCommunicatiobBase { };
class CoTRESTCommunication: public CoTCommunicatiobBase { };

/* Authentication mechanisms we support */
class CoTAuthFingerPrint: public CoTAuthBase { };
class CoTAuthTLS: public CoTAuthBase { };


/* Library Public Interface 
 * ----------------------------
 */

/* Concrete classes, instances will be used in the user code
 * preferred instanctiation methods - helper functions provided by the library (see below)
 */

/* Available Authentication mechanisms (TLS/Fingerprint) */
class CoTAuthTLS: public CoTAuthBase { };
class CoTAuthFingerprint: public CoTAuthBase { };


class CloudMessageHandlerParam { };

class CloudVar: public CloudMessageHandlerParam { 

public:
	CloudVar( CloudVarNameType name, const T& value) 
		: _name( name), _value( value) 
		{ }

public:
	CloudVarNameType name() { return _name; }
	T value() { return _value; }

private:
	CloudVarNameType _name;
	T _value;
};


/* Setings needed for accessing any cloud service (DT/AZURE/ADAFRUIT) */
class CoTCloudConfig: public CoTConfigBase {
public:
	CoTCloudConfig( const char* serverUrl
		, const char* password
		, unsigned long portNumber );
};


/* Since we have only one cloud - there is no need to abstract it
 * TODO: ask client if he wants to be able to have multiple 
 *		cloud access (Azzure, DT, Adafruit)
 * If so - provid the abstraction hierarchy for the cloud too,
 * with this class as a "leaf" of the inheritance tree
*/
class CoTCloud {
public:
	CoTCloud( const CoTDeviceBase& device );
	CoTCloud( const CoTDeviceBase& device,	const CoTConfigBase& cloudConfig );

public:
	bool init();

puplic:
	bool publish();
	bool subscribe();

public:
	bool registerHandler( const CoTCloudMessage& message, 
		const CoTCloudMessageHandler handler );

public:
	bool process();

private:
	const CoTCommunicationBase _preferedCommunication; /* MQTT/MQTT-SN/REST/AZURE*/
	const CoTDeviceBase& _selectedDevice;					/* M0/HUZZAH/FONA */
	const CoTConfigBase& _cloudConfig;						/* URL/User/PWD/ID */

private:
	CoTCloud( const CoTCloud& );

};

} /* namespace DTCoT */

#endif /* DTCoT_HEADER_FILE	 */

