#ifndef MQTTSNCommunication_h_
#define MQTTSNCommunication_h_

#include "DTCoTPrivate.h"
#include "DTCoTCommunicationBase.h"
#include "NbIoTClient.h"
#include "mm1MqttSn.h"


namespace DTCoT {
	
class CoTCommunicationMQTTSN: public CoTCommunicationBase {
public:
	CoTCommunicationMQTTSN(
		const CoTDeviceBase& device
		, const CoTConfigBase& config 	
		, const CoTAuthBase& authentication);
	
	void init();
	
	void publish(int topicId, const char * value);
	/**
	 * @brief Registers a topic after connecting to the cloud of things.
	 * @param topic A topic string.
	 * @returns The assigned topic id; @ref MQTTSN_TOPIC_INVALID_ID if 
	 * topic registration failed.
	 * @note At the moment, only topic "MEAS" is supported.
	 */
	 int Mqttsn_RegisterTopic(char* topic, char valueType);
	 
	 
	 
private:
	void reconnect();
	
private:	
	//NbiotClient nbiotClient;
	MM1MqttSn mqttsn;
};

}

#endif // MQTTCommunication_h_

