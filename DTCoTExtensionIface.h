#ifndef DT_COT_EXTENSION_IFACE_HEADER_FILE 
#define DT_COT_EXTENSION_IFACE_HEADER_FILE

/* DTCoT Library Extension Interface 
 * ----------------------------
 */

#include "DTCoTPrivate.h"

namespace DTCoT 
{

/* Configuration for every supported device */
class CoTConfigDevice: public CoTConfigBase { 
public:
	CoTConfigDevice();
};

/* Configuration for every communication method */
class CoTConfigCommunication: public CoTConfigBase { };

/* Configurationf or any authentication */
class CoTConfigAuth: public CoTConfigBase { };

/* Communication types we support */
/* Nothe: communication type does not belong to the Library public interface.
 * 	It should be hidden and selectable compile-time ( #define in DTCoTSetup.h? )
 */

class CoTConfigCommunicationMQTT: public CoTConfigBase {
public:
	CoTConfigCommunicationMQTT( const char* serverUrl
		, unsigned long portNumber 
		, const char* password
		, const char* userID );

public:
	const char* getUrl();
	unsigned long getPortNumber();
	const char* getPassword();
	const char* getUserId();

private:
	const char* _serverUrl;
	unsigned long _portNumber;
	const char* _password;
	const char* _userId;
};

class CoTConfigCommunicationMQTTSN: public CoTConfigBase {
public:
	CoTConfigCommunicationMQTTSN( const char* serverIP
		, const char* serverPort
		, const char* imsi
		, const char* password 
		);

public:
	const char* getServerIP();
	const char* getServerPort();
	const char* getIMSI();
	const char* getPassword();
	const char* getClientId();


private:
	const char* _serverIP;
	const char* _serverPort;
	const char* _imsi;
	const char* _password;
	String _clientId;

};


class CoTCommunicationREST: public CoTCommunicationBase { };

/* Authentication mechanisms we support */
class CoTAuthFingerPrint: public CoTAuthBase { };
class CoTAuthTLS: public CoTAuthBase { };
class CoTAuthNone: public CoTAuthBase { };

} /* namespace DTCoT */

#endif /* DT_COT_EXTENSION_IFACE_HEADER_FILE */
