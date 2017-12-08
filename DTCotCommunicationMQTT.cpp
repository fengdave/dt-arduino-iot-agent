
#include "DTCoTCommunicationMQTT.h"
#include "DTCoTCommunicationBase.h"
#include "DTCoTDeviceBase.h"

#include "DTCoTExtensionIface.h"


using namespace DTCoT;

#define DEBUG_PRINT(x) Serial.println(x) 


CoTCommunicationMQTT::CoTCommunicationMQTT(
	const CoTDeviceBase& device
	, const CoTConfigBase& config
	, const CoTAuthBase& authentication )
	: CoTCommunicationBase( device, config, authentication) 
{
}

void CoTCommunicationMQTT::init()
{
	DEBUG_PRINT("CoTCommunicationMQTT::init");
	CoTConfigCommunicationMQTT & config = (CoTConfigCommunicationMQTT&)_config;
	

	((CoTDeviceBase*)&_device)->init(); // @todo why is a device const?
	
	DEBUG_PRINT("CoTCommunicationMQTT::initted device");
	
	/*Adafruit_MQTT_Client mqtt(_device.getClient(), config.getUrl(),
				config.getPortNumber(),
				config.getUserId(), 
				config.getPassword());
	
	
	
	int8_t ret;
    if (mqtt.connected()) {
      return;
    }

    DEBUG_PRINT("Connecting to MQTT... ");

    uint8_t retries = 3;
    while ((ret = mqtt.connect()) != 0) { // connect will return 0 for connected
         DEBUG_PRINT(mqtt.connectErrorString(ret));
         DEBUG_PRINT("Retrying MQTT connection in 5 seconds...");
         mqtt.disconnect();
         delay(5000);
         retries--;
         if (retries == 0) {
           // basically die and wait for WDT to reset me
           while (1);
         }
    }*/
    DEBUG_PRINT("MQTT Connected!");
}

/*
DTCoT::MQTTCommunication::MQTTCommunication(DTCoT::DeviceBase & device, CoTConfigCommunicationMQTT & config)
	: DTCoT::CommunicationBase(device)
	, mqtt(device.getClient(), server, MQTT_SERVER_PORT, username, key)
	, username(username)
{
	DEBUG_PRINT("DTCoT::MQTTCommunication::MQTTCommunication");
}

void DTCoT::MQTTCommunication::init()
{
	int8_t ret;
    if (mqtt.connected()) {
      return;
    }

    DEBUG_PRINT("Connecting to MQTT... ");

    uint8_t retries = 3;
    while ((ret = mqtt.connect()) != 0) { // connect will return 0 for connected
         DEBUG_PRINT(mqtt.connectErrorString(ret));
         DEBUG_PRINT("Retrying MQTT connection in 5 seconds...");
         mqtt.disconnect();
         delay(5000);
         retries--;
         if (retries == 0) {
           // basically die and wait for WDT to reset me
           while (1);
         }
    }
    DEBUG_PRINT("MQTT Connected!");
}

void DTCoT::MQTTCommunication::send(const char * key, const char * value) {
	
	// @todo error handling/reconnect!
	if (mqtt.connected() == false) {
		DEBUG_PRINT("ERROR - could not send MQTT, not connected.");
		return;
	}
	
	// @TODO - provide registerHandler, do not instantiate every time!
				
	char address[255]; // @todo bounds checking
	sprintf(address, "%s/feeds/%s", username, key);
	
	DEBUG_PRINT(address);
	DEBUG_PRINT(value);
	
	Adafruit_MQTT_Publish topic = Adafruit_MQTT_Publish(&mqtt, address);
	topic.publish(value);
}*/

