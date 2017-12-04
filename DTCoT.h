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
private:
	const CoTConfigBase& _deviceConfig;
};

class CoTAuthBase { };

class CoTCommunicationBase {
private:
	const CoTAuthBase& _authenticationConfig
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

/* Type of devices we support (only connectivity criteria?) */
class CoTDeviceGPRS: public CoTDeviceBase { };
class CoTDeviceWiFi: public CoTDeviceBase { };
class CoTDeviceEthernet: public CoTDeviceBase { };

/* Communication types we support */
/* Nothe: communication type does not belong to the Library public interface.
 * 	It should be hidden and selectable compile-time ( #define in DTCoTSetup.h? )
 */
class CoTMQTTCommunication: public CoTCommunicationBase { };
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
namespace config {
class CoTAuthMQTT: public CoTAuthConfig {};
class CoTAuthREST: public CoTAuthConfig {};
}

namespace devices {
class CoTDeviceFeatherM0: public CoTDeviceWiFi { };
class CoTDevice32u4FONA: public CoTDeviceGPRS { };
class CoTDeviceHUZZAH: public CoTDeviceWiFi { };
}


/* Since we have only one cloud - there is no need to abstract it
 * TODO: ask client if he wants to be able to have multiple cloud access (Azzure, DT, Adafruit)
 * If so - provid the abstraction hierarchy for the cloud too,
 * with this class as a "leaf" of the inheritance tree
*/
class CoTCloud{
private:
	const CoTCommunicationBase& _preferredCommunication;
	const CoTDeviceBase& _selectedDevice;
	const CoTConfigBase& _cloudConfig;
};



/* Helper functions (mostly factory functions to facilitate 
 * instantiation of library public interface objects) 
*/
template<typename T>
T CreateDeviceConfig<T>( const CoTConfigBase& devConfig){
	T d( devConfig);
	return d;
}


} /* namespace DTCoT */

#endif /* DTCoT_HEADER_FILE	 */

