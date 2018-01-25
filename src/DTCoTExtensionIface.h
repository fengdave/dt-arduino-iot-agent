/**
 * @file DTCoTExtensionIface.h
 * @description Basic setup and protocol to interact 
 * with the Deutsche Telekom Cloud of things MQTT-SN connector.
 * @author Andreas Krause
 * @copyright (C) 2018 mm1 Technology GmbH - all rights reserved. 
 * @licence MIT licence
 * 
 * Find out more about mm1 Technology:
 * Company: http://mm1-technology.de/
 * GitHub:  https://github.com/mm1technology/
 */

#ifndef DT_COT_EXTENSION_IFACE_HEADER_FILE 
#define DT_COT_EXTENSION_IFACE_HEADER_FILE

/* DTCoT Library Extension Interface 
 * ----------------------------
 */

#include "DTCoTPrivate.h"

namespace DTCoT 
{

/**
 * Configuration for every supported device.
 * This contains any configuration info that is common to all devices.
 */
class CoTConfigDevice: public CoTConfigBase { 
public:
	CoTConfigDevice();
};

/**
 * Configuration for every communication method.
 * This contains any configuration info that is common to all communication methods.
 */
class CoTConfigCommunication: public CoTConfigBase { };

/**
 * Configuration for any authentication method.
 */
class CoTConfigAuth: public CoTConfigBase { };

/* Communication types we support */
/* Note: communication type does not belong to the Library public interface.
 * 	It should be hidden and selectable compile-time ( #define in DTCoTSetup.h? )
 */

/**
 * Configuration for MQTT.
 * This class is used to configure an MQTT communications channel.
 * There are standard parameters for connecting to an MQTT broker,
 * and this class encapsulates them.
 * 
 */
class CoTConfigCommunicationMQTT: public CoTConfigBase {
public:
	/**
	 * Constructor
	 * @param serverUrl whare to find the mqtt broker
	 * @param portNumber port to connect to MQTT broker on.
	 * @param password password for the broker account
	 * @param userId user ID/name for the MQTT broker
	 */
	CoTConfigCommunicationMQTT( const char* serverUrl
		, unsigned long portNumber 
		, const char* password
		, const char* userID );

public:
	/**
	 * Getter for URL of the MQTT broker
	 */
	const char* getUrl();
	
/**
 * Getter for URL of the MQTT port
 */	
	unsigned long getPortNumber();
	
/**
 * Getter for password for the MQTT account
 */
	const char* getPassword();
	
   /**
    * Getter for username / id for the MQTT account
    */
	const char* getUserId();

private:
	const char* _serverUrl;
	unsigned long _portNumber;
	const char* _password;
	const char* _userId;
};

/**
 * Configuration for MQTT - SN.
 * This class is used to configure an MQTT-SN communications channel.
 * MQTT-SN is a cutdown version of MQTT, designed for small IoT devices.
 * There are standard parameters for connecting to an MQTT-SN broker,
 * and this class encapsulates them.
 * Typically, it conneccts to a local gateway, which converts MQTT-SN
 * traffic to MQTT and relays this to a broker on the internet.
 * 
 */
class CoTConfigCommunicationMQTTSN: public CoTConfigBase {
public:
	
/**
 * Constructor
 * @param serverIP whare to find the mqtt-sn gateway
 * @param serverPort port to connect to MQTT gateway on.
 * @param password password for the gateway account
 * @param imsi user ID for the MQTT gateway
 */
	CoTConfigCommunicationMQTTSN( const char* serverIP
		, const unsigned short serverPort
		, const char* imsi
		, const char* password 
		);

public:
	const char* getServerIP();
	const unsigned short getServerPort();
	const char* getIMSI();
	const char* getPassword();
	const char* getClientId();


private:
	const char* _serverIP;
	const unsigned short _serverPort;
	const char* _imsi;
	const char* _password;
	String _clientId;

};

/**
 * REST interface (not implemented)
 */
class CoTCommunicationREST: public CoTCommunicationBase { };

/* Authentication mechanisms we support */

/**
 * Fingerprint authentication
 */
class CoTAuthFingerPrint: public CoTAuthBase { };

/**
 * TLS authentication
 */
class CoTAuthTLS: public CoTAuthBase { };

/**
 * No authentication
 */
class CoTAuthNone: public CoTAuthBase { };

} /* namespace DTCoT */

#endif /* DT_COT_EXTENSION_IFACE_HEADER_FILE */
