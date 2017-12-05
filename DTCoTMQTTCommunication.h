#ifndef MQTTCommunication_h_
#define MQTTCommunication_h_

#include <DTCoTCommunicationBase.h>

#include <Adafruit_MQTT.h>
#include <Adafruit_MQTT_Client.h>

namespace DTCoT {
	class MQTTCommunication : public CommunicationBase {
	public:
		MQTTCommunication(DeviceBase & device);
		
		void send(char * key, char * value);
		
	private:
		class Adafruit_MQTT_Client mqtt;
	};

}

#endif // MQTTCommunication_h_

