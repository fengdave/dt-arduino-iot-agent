#include "DTCOTSetup.h"

#if CONN_TYPE == NB_IOT

#include "DTCoTCommunicationMQTTSN.h"
#include "DTCoTCommunicationBase.h"
#include "DTCoTDeviceBase.h"
#include "DTCoTDeviceNBIoT.h"
#include "DTCoTExtensionIface.h"


using namespace DTCoT;

#define DEBUG_PRINT(x) Serial.println(x)

CoTCommunicationMQTTSN::CoTCommunicationMQTTSN(
	const CoTDeviceBase& device
	, const CoTConfigBase& config
	, const CoTAuthBase& authentication )
	: CoTCommunicationBase( device, config, authentication) // @todo - hardcoded 
		, mqttsn(
		  ((CoTConfigCommunicationMQTTSN&)config).getIMSI() /* at DT NB-IoT, the Client ID is the IMSI */  
		, ((CoTConfigCommunicationMQTTSN&)config).getServerPort()
		, ((CoTConfigCommunicationMQTTSN&)config).getPassword()
		, *device.getClient()
		)
{
}

void CoTCommunicationMQTTSN::init() {
	DEBUG_PRINT("CoTCommunicationMQTTSN::init");
	delay(1000);
	reconnect();
}

void CoTCommunicationMQTTSN::publish( int topicId, const char * value) {
	CoTConfigCommunicationMQTTSN & config = (CoTConfigCommunicationMQTTSN&)_config;
	// @todo error handling/reconnect!
	if ( mqttsn.connected() == false) {
		DEBUG_PRINT("CoTCommunicationMQTTSN::publish not connected - will reconnect...");
		reconnect();
	}
	else {
		/* TODO: Implement MQTTSN publish here */
		
		mqttsn.publish(topicId, value);
	}

	
}

int CoTCommunicationMQTTSN::Mqttsn_RegisterTopic(char* topic, char valueType) {
	
	if ( mqttsn.connected() == false) {
		DEBUG_PRINT("ERROR - could not send MQTTSN, not connected.");
		reconnect();
	}
	else {
		/* TODO: Implement Mqttsn_RegisterTopic here */
		
		
		return mqttsn.RegisterTopicDTCoT(topic, valueType);
		
		
		
	}
	
	
}



void CoTCommunicationMQTTSN::reconnect()
{
	CoTConfigCommunicationMQTTSN & config 
		= (CoTConfigCommunicationMQTTSN&)_config;

	int8_t ret;
    if (mqttsn.connected()) {
		
		DEBUG_PRINT("CoTCommunicationMQTTSN::reconnect() - mqttsn.connected() == true");
      return;
    }

    DEBUG_PRINT("Connecting to MQTTSN Gateway ... ");

    uint8_t retries = 3;
    while ((ret = mqttsn.connect(FLAG_CLEAN, 3)) != 0) { // connect will return 0 for connected
         DEBUG_PRINT(mqttsn.connectErrorString(ret));
         DEBUG_PRINT("Retrying MQTT connection in 5 seconds...");
         mqttsn.disconnect();
         delay(5000);
         retries--;
         if (retries == 0) {
           // basically die and wait for WDT to reset me
           while (1);
         }
    }
    DEBUG_PRINT("MQTT Connected!");
}


#endif