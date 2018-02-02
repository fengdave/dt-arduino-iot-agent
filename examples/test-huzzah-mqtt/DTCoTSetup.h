/**
 * @file DTCoTSetup.h
 * @description Basic setup and protocol to interact 
 * with the Deutsche Telekom Cloud of things MQTT-SN connector.
 * @author mm1 Technology GmbH
 * @copyright (C) 2018 Deutsche Telekom AG- all rights reserved. 
 * @licence MIT licence
 * 
 */

#ifndef DTCoT_SETUP_HEADER_FILE
#define DTCoT_SETUP_HEADER_FILE

/**
 * DTCoT Library Setup File.
 *
 * Edit this file to change which hardware and protocols will be used.
 *
 * Intended audience - library maintainer, advanced library users
 *
 * To activate or deactivate certain features of the library, 
 * uncomment or comment the definition of the feature respectively.
 */


/**
* Define which hardware
*/

#define HUZZAH                0
#define GIMASI_TUINO1         1
#define FEATHER_M0			  2
/**********************************/

/**
* Define which communication path
*/
#define WIFI                  0
#define NB_IOT                1
#define GSM                   2
/**********************************/


/************************************************************************************************/
/************************  CONFIGURATION / ONLY CHANGE HERE        ******************************/
/************************************************************************************************/

/**********************************/
/* Select the cloud communication method here */
#define COMMUNICATION_MQTT
// #define COMMUNICATION_MQTTSN
// #define COMMUNICATION_REST
// #define COMMUNICATION_RAW_SOCKET
/**********************************/

/**********************************/
/* io.adaafruit.com*/
#define MQTT_BROKER_ADAFRUIT
//#define MQTT_BROKER_DT
/* https://docs.microsoft.com/en-us/azure/iot-hub/iot-hub-mqtt-support */
//#define MQTT_BROKER_AZURE
/**********************************/

/**********************************/
/*Select the authentication method */
#define AUTHENTICATION_NONE
// #define AUTHENTICATION_TLS
// #define AUTHENTICATION_FINGERPRINT
/**********************************/

/**********************************/
/* Select the connection type here */
//#define CONN_TYPE             NB_IOT
#define CONN_TYPE             WIFI
//#define CONN_TYPE             GSM
/**********************************/

/**********************************/
/* Select the Hardware platform here */
//#define HW_PLATFORM          GIMASI_TUINO1
#define HW_PLATFORM          HUZZAH
//#define HW_PLATFORM          FEATHER_M0
/**********************************/

/************************************************************************************************/
/************************************************************************************************/

/**
* Hardware Platform specific includes
*/
 

 

#if HW_PLATFORM == HUZZAH
   	#define HUZZAH_ENABLED     	1
 

#elif HW_PLATFORM == GIMASI_TUINO1
  	#define TUINO1_ENABLED      1

#elif HW_PLATFORM == FEATHER_M0 && CONN_TYPE == NB_IOT
	#define FEATHER_M0_NBIOT	1

#elif HW_PLATFORM == FEATHER_M0 && CONN_TYPE == WIFI
	#define FEATHER_M0_WIFI		1

#endif
 /**********************************/
 




/**
 * communication path specific includes
 */

#if CONN_TYPE == WIFI

	#define WIFI_ENABLED      1


#elif CONN_TYPE == NB_IOT

	#define NB_IOT_ENABLED    1


#elif CONN_TYPE == GSM

	#define GSM_ENABLED       1 


#endif
/**********************************/


#if defined(COMMUNICATION_MQTT)
#include "communication/DTCotCommunicationMQTT.h"
	#define PREFERED_COMMUNICATION_METHOD CoTCommunicationMQTT
#elif defined(COMMUNICATION_MQTTSN )
#include "communication/DTCotCommunicationMQTTSN.h"
#define PREFERED_COMMUNICATION_METHOD CoTCommunicationMQTTSN
#elif defined(COMMUNICATION_REST)
#define PREFERED_COMMUNICATION_METHOD CoTCommunicationREST
#endif



#define MAX_NETWORK_JOIN_RETRIES 100

#endif /* DTCoT_SETUP_HEADER_FILE */

