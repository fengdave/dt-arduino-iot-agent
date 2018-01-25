/**
 * @file {{file}}
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

#ifndef MQTTCommunication_h_
#define MQTTCommunication_h_


#include <Adafruit_MQTT.h>
#include <Adafruit_MQTT_Client.h>

#include "DTCoTPrivate.h"
#include "base-classes/DTCoTCommunicationBase.h"

namespace DTCoT {
	
	/**
	 * Communication via MQTT
	 * This class allows connection to an MQTT broker on the internet. This uses a direct IP connection without a gateway. 
	 *
	 */
	class CoTCommunicationMQTT: public CoTCommunicationBase { 
	public:
		
		/**
		 * Constructor
		 * @param device interface to this hardware platform.
		 * @param config config settings matching this hardware paltform
		 * @param authentication login / auth details for this connection.
		 */
		CoTCommunicationMQTT(const CoTDeviceBase& device
			, const CoTConfigBase& config
			, const CoTAuthBase& authentication	);
	
	/**
	 * Startup the MQTT channel
	 */
	void init();
	
	/**
	 * Publish value on MQTT broker.
	 * Publishes a value to the remote broker. You should see the value change immediately.
	 * @param key the key/topic to publish to. For example /myproject/temperature
	 * @param value the value to publish to the given key/topic. For example: "123", "hello" 
	 */
	void publish(const char * key, const char * value);
	
	private:
	void reconnect();
	
	private:
	
	Adafruit_MQTT_Client mqtt;
	
	/*
	class MQTTCommunication : public CommunicationBase {
	public:
		MQTTCommunication(DeviceBase & device, const char * server, const char * username, const char * key);
		
		virtual void init();
		
		virtual void send(const char * key, const char * value);
		

		const char * username;
	
	};
	*/
};

}

#endif // MQTTCommunication_h_

