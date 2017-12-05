
#include <DTCoTMQTTCommunication.h>
#include <DTCoTDeviceBase.h>

#define DEBUG_PRINT(x) Serial.println(x) // @todo - make this universal?

#define mqtt_server "io.adafruit.com"
#define mqtt_username "jimmyio"
#define mqtt_key "eaa66e7fe19c41e9836bdeec82e1fca9"

		DTCoT::MQTTCommunication::MQTTCommunication(DTCoT::DeviceBase & device)
			: DTCoT::CommunicationBase(device)
			, mqtt(device.getClient(), mqtt_server, 1883, mqtt_username, mqtt_key)
		{
			DEBUG_PRINT("DTCoT::MQTTCommunication::MQTTCommunication");
		}
		
		void DTCoT::MQTTCommunication::send(char * key, char * value) {
			// @TODO - provide registerHandler, do not instantiate every time!
			
			DEBUG_PRINT(key);
			DEBUG_PRINT(value);
			Adafruit_MQTT_Publish topic = Adafruit_MQTT_Publish(&mqtt, "jimmyio/feeds/text");
			topic.publish(value);
		}

