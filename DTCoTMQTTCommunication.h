#ifndef MQTTCommunication_h_
#define MQTTCommunication_h_

#include <DTCoTCommunicationBase.h>

#include <Adafruit_MQTT.h>
#include <Adafruit_MQTT_Client.h>

namespace DTCoT {
	class MQTTCommunication : public CommunicationBase {
	public:
		MQTTCommunication(DeviceBase & device, const char * server, const char * username, const char * key);
		
		virtual void begin();
		
		virtual void send(const char * key, const char * value);
		
	private:
		class Adafruit_MQTT_Client mqtt;
		const char * username;
	};

}

#endif // MQTTCommunication_h_

