#ifndef DT_COT_EXTENSION_IFACE_HEADER_FILE 
#define DT_COT_EXTENSION_IFACE_HEADER_FILE

/* DTCoT Library Extension Interface 
 * ----------------------------
 */

#include "DTCoTPrivate.h"

namespace DTCoT 
{

/* Configuration for every supported device */
class CoTDeviceConfig: public CoTConfigBase { };

/* Configuration for every communication method */
class CoTCommunicationConfig: public CoTConfigBase { };

/* Configurationf or any authentication */
class CoTAuthConfig: public CoTConfigBase { };

/* Communication types we support */
/* Nothe: communication type does not belong to the Library public interface.
 * 	It should be hidden and selectable compile-time ( #define in DTCoTSetup.h? )
 */
class CoTMQTTCommunication: public CoTCommunicationBase { 
public:
	CoTMWTTCommunication( const CoTDeviceBase& device
		, const CoTConfigBase& config
		, const CoTAuthBase& authentication );
};
class CoTMQTTSNCommunication: public CoTCommunicationBase { };
class CoTRESTCommunication: public CoTCommunicationBase { };

/* Authentication mechanisms we support */
class CoTAuthFingerPrint: public CoTAuthBase { };
class CoTAuthTLS: public CoTAuthBase { };
class CoTAuthNone: public CoTAuthBase { };

} /* namespace DTCoT */

#endif /* DT_COT_EXTENSION_IFACE_HEADER_FILE */
