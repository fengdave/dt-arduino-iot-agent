/**
 * @file DTCotCommunicationMQTTSN.h
 * @description header file for Class for management and operations for all MQTT-SN communication
 * @author mm1 Technology GmbH
 * @copyright (C) 2017-2018 Deutsche Telekom AG- all rights reserved. 
 * @licence MIT licence
 */

#ifndef MQTTSNCommunication_h_
#define MQTTSNCommunication_h_

#include "DTCoTSetup.h"

#ifdef COMMUNICATION_MQTTSN

#include "DTCoTPrivate.h"
#include "base-classes/DTCoTCommunicationBase.h"
#include "protocols/NbIoTClient.h"
#include "protocols/DTCoTMqttSn.h"


namespace DTCoT {

/**
 * Communication via MQTT-SN.
 * MQTT-SN is a cutdown version of MQTT designed for IoT.
 * This class allows connection to an MQTT-SN gateway, usually running on a LAN. 
 *
 */
class CoTCommunicationMQTTSN: public CoTCommunicationBase {
public:
	
/**
 * Constructor
 * @param device interface to this hardware platform.
 * @param config config settings matching this hardware platform
 * @param authentication login / auth details for this connection.
 */
	CoTCommunicationMQTTSN(
		const CoTDeviceBase& device
		, const CoTConfigBase& config 	
		, const CoTAuthBase& authentication);
	
/**
 * Startup the MQTT-SN channel
 */
	void init();

/**
 * Publish value on MQTT-SN gateway/broker.
 * Publishes a value to the remote gateway/broker. You should see the value change immediately.
 * @param topicId the topic to publish to. 
 * @param value the value to publish to the given key/topic. For example: "123", "hello" 
 */
	void publish(int topicId, const char * value);
	/**
	 * Registers a topic after connecting to the cloud of things.
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
	DTCoTMqttSn mqttsn;
};

}

#endif /*COMMUNICATION_MQTTSN*/

#endif /*MQTTCommunication_h_*/

