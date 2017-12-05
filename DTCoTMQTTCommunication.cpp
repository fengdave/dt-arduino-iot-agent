
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
		
		void DTCoT::MQTTCommunication::begin()
		{
			int8_t ret;
		    if (mqtt.connected()) {
		      return;
		    }

		    Serial.print("Connecting to MQTT... ");

		    uint8_t retries = 3;
		    while ((ret = mqtt.connect()) != 0) { // connect will return 0 for connected
		         DEBUG_PRINT(mqtt.connectErrorString(ret));
		         DEBUG_PRINT("Retrying MQTT connection in 5 seconds...");
		         mqtt.disconnect();
		         delay(5000);  // wait 5 seconds
		         retries--;
		         if (retries == 0) {
		           // basically die and wait for WDT to reset me
		           while (1);
		         }
		    }
		    DEBUG_PRINT("MQTT Connected!");
		}
		
		void DTCoT::MQTTCommunication::send(char * key, char * value) {
			
			// @todo error handling/reconnect!
			if (mqtt.connected() == false) {
				DEBUG_PRINT("ERROR - could not send MQTT, not connected.");
				return;
			}
			
			// @TODO - provide registerHandler, do not instantiate every time!
						
			char address[255]; // @todo bounds checking
			sprintf(address, mqtt_username "/feeds/%s", key);
			
			DEBUG_PRINT(address);
			
			Adafruit_MQTT_Publish topic = Adafruit_MQTT_Publish(&mqtt, address);
			topic.publish(value);
		}

