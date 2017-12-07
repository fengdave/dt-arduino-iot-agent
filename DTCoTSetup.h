#ifndef DTCoT_SETUP_HEADER_FILE
#define DTCoT_SETUP_HEADER_FILE

/* DTCoT Library Setup File
 * Intended audience - library maintainer, advanced library users
 *
 * To activate or deactivate certain feature of the library - 
 * uncomment or comment the definition of the feature respectively.
 */


/* Select the cloud communication method here */

#define COMMUNICATION_MQTT
// #define COMMUNICATION_MQTT_SN
// #define COMMUNICATION_REST
// #define COMMUNICATION_RAW_SOCKET

/* Select the MQTT Broker here */

/* io.adaafruit.com*/
#define MQTT_BROKER_ADAFRUIT
#define MQTT_BROKER_DT
/* https://docs.microsoft.com/en-us/azure/iot-hub/iot-hub-mqtt-support */
#define MQTT_BROKER_AZURE


/*Select the authentication method */
#define AUTHENTICATION_NONE
// #define AUTHENTICATION_TLS
// #define AUTHENTICATION_FINGERPRINT


#if defined(COMMUNICATION_MQTT)
	#define PREFERED_COMMUNICATION_METHOD CoTCommunicationMQTT
#elif defined(COMMUNICATION_MQTT_SN )
	#define PREFERED_COMMUNICATION_METHOD CoTCommunicationMQTTSN
#elif defined(COMMUNICATION_REST)
	#define PREFERED_COMMUNICATION_METHOD CoTCommunicationREST
#endif

#endif /* DTCoT_SETUP_HEADER_FILE */

