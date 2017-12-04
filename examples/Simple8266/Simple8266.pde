#include <TelekomCoT.h>


#ifdef USE_2G
  #include <Adafruit_MQTT_FONA.h>

	Adafruit_FONA fona = Adafruit_FONA(FONA_RST);
	fona.setPins(5, 6, 7); // May need to do hardware-specific config

	// CotLib::CotLib(Adafruit_MQTT * mqttInterface, String mqttUsername, String mqttPassword);
	TelekomCoT cotlib(&fona, "mqtt.telekom.de", "mm1person", "4hkewhkjdhdsjro4");
#else
  #include <Adafruit_MQTT_Client.h>
	Adafruit_MQTT_Client wifiClient = Adafruit_MQTT_Client();
	wifiClient.addAP("wifi_ssid", "wifi_password"); // May need to do hardware and netowrk-specific config

	// CotLib::CotLib(Adafruit_MQTT * mqttInterface, String mqttUsername, String mqttPassword);
	TelekomCoT cotlib(&wifiClient, "mqtt.telekom.de", "mm1person", "4hkewhkjdhdsjro4");

#endif

	// MUST ALSO SUPPORT NBIOT HERE IN NEXT PHASE - separate stack for MQTT


void setup() {
	cotlib.onMessageReceived(cotMessageHandler);
	    cot.onError([](ErrorCode error)
	    {
	    	// note lambda functions can be used as handlers
	        Serial.print("Got error");
	    });
	cot.start();
	}
	
		cotlib.connect();
}

void loop() {
	cotlib.update();
	

	cotlib.publish("temperature", 25.0);
}


bool cotMessageHandler(CoTMessage * msg) {
	if (msg.key == "something") {
		doSomething();
		return true;
	}
}