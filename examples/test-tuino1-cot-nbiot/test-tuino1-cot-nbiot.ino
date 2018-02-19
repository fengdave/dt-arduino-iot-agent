/**
 * @file test-tuino1-cot-nbiot.ino
 * @description Simple Demo
 * @description Simple Demo for CoT Library using NB-IoT
 * @author mm1 Technology GmbH
 * @copyright (C) 2017-2018 Deutsche Telekom AG- all rights reserved. 
 * @licence MIT licence
 * 
 */

/** Cloud-based blinker

   Objective:
   This project demonstrates how simple it is to build a DTCoT application

   This example also shows that DTCoT does not depend on device type,
   network and protocol libraies, and can be easily extended by adding more
   devices and underlaying protocols (as soon as the cloud starts supporting them).

   Application description:
   In this demo there is a counter that will be published as a named variable
   the cloud and the value of the variable will be sent to the
   subcriber (potentialy - another device)
   When the variable value reaches certain threshold - LED will blink several times

*/

#include <stdint.h>
#include "DTCoT.h"
/* NOTE: You need to create this secrets.h file with the following defines:
 #define NB_IOT_IMSI           "<IMSI, as found in the logs of your device>" 
 #define NB_IOT_MQTTSN_PWD        "<password for access to the server>"
*/
#include "secrets.h"

// Make sure we are using the correct hardware configuration for NB_IOT
#if CONN_TYPE != NB_IOT
#error("You need to enable NB_IOT in the config!")
#endif

/* Application-specific settings */
const uint8_t ON_BOARD_LED = 13;
/* The name of tthe variable on the server */
const char CLOUD_COUNTER_VAR_NAME[] = "cloud-counter";
/* Wrap after this number */
const uint8_t COUNTER_THRESHOLD = 0xFF;
/*MQTTSN topic ID for this example*/
uint16_t myMqttsnTopicId = MQTTSN_TOPIC_INVALID_ID;



using namespace DTCoT;

/********** DT CoT Library Initialisation **********/

/* Configure a Gimasi Tuino 1 device, connected to the CoT server */
CoTConfigDeviceGimasi devConfig = CoTConfigDeviceGimasi
    (
        NB_IOT_SERVER_IP,
        NB_IOT_SERVER_PORT, 
        NB_IOT_IMSI, 
        NB_IOT_MQTTSN_PWD,
        Serial1, 				// serial port to use for the NBIoT hardware
        GMX_RESET				// reset pin to use for the NBIoT hardware
    );

/* Create the device */
CoTDeviceGimasi device = CoTDeviceGimasi(devConfig);

/* Configure connection to the MQTT-SN backend */
CoTConfigCommunicationMQTTSN mqttsnConfig
    (
        NB_IOT_SERVER_IP,
        NB_IOT_SERVER_PORT,
        NB_IOT_IMSI,
        NB_IOT_MQTTSN_PWD
    );

CoTCloud cloud
    ( 
        /* Configure communcation settings of your DT Cloud-enabled device */
        device,
        /* Setup the cloud communication method */ 
        mqttsnConfig
    );




void onCounterValueChanged( void* newCounterValue) {
    /* TODO: 
     * parameter NULL check
     * casting outcome check
     * provide helper-macro for easy app-specific casting
     * figure out how to avoid casting for different payload types
    */
    unsigned long counterValue = *(static_cast< unsigned long*>(newCounterValue));

    if ( counterValue >= COUNTER_THRESHOLD) {
        digitalWrite( ON_BOARD_LED, HIGH);
    }
    else {
        digitalWrite( ON_BOARD_LED, LOW);
    }
}


void setup() {
    delay(100);
    Serial.begin(115200);
    delay(100);
    DEBUG_PRINT_INFO("Setup...");

    device.init();

    DEBUG_PRINT_INFO("Setup...");
    cloud.init();

    /* Subscribe to the change of a cloud variable of interest */
    cloud.subscribe( CLOUD_COUNTER_VAR_NAME, onCounterValueChanged); // @todo implement

    /* Register the topics that we want to publish to later */
    DEBUG_PRINT_INFO("connected, registering topic...");
    myMqttsnTopicId = cloud.Mqttsn_RegisterTopic(MQTTSN_TOPIC_MEASUREMENT, MQTTSN_MEAS_TYPE_TEMPERATURE);
    if(myMqttsnTopicId == MQTTSN_TOPIC_INVALID_ID)
    {
        /*TODO topic reg failed, disconnect / restart connect*/
        DEBUG_PRINT_INFO("INVALID MQTTSN_TOPIC_ID");
    }
    else {
        DEBUG_PRINT_INFO("topic registered, uploading data...");
        DEBUG_PRINT_INFO("myMqttsnTopicId: %s", myMqttsnTopicId);	
    }

}



/** 
 * @brief Simulation of temperature values going up and down.
 * 
 * Temperature value wobbles between 20..30°.
 */
float GetTemperature(void) {
    static float exampleTemp = 25.4;
    static bool tempRising = false;

    if(exampleTemp <= 20.0) {
    	tempRising = true;
    }
    else if(exampleTemp >= 30.0) {
    	tempRising = false;
    }

    if(tempRising) {
        exampleTemp += 0.5;
    }
    else {
        exampleTemp -= 0.5;
    }
    
    return exampleTemp;
}



void loop() {
    /** Simulation of temperature values **/
    float exampleTemp = GetTemperature();
    char examplTempStr[10];

    DEBUG_PRINT_INFO("Loop");

    /* Update/poll cloud infrastructure client */
    if ( !cloud.process() ) {
        /* TODO: process error here */
    }

    /* NOTE on workaround: 
     * Remote DT MQTT-SN connector accepts only ONE position after decimal point!
     */
    dtostrf(exampleTemp, 2, 1, examplTempStr);
    DEBUG_PRINT("### Sending Temperature: %s", examplTempStr);

    /* Publish our updated temperature value to the CoT server */
    if ( !cloud.publish(myMqttsnTopicId, examplTempStr) ) { 
        // @todo, send integers/reals
        /* TODO: process error here */
    }

    delay(5000);
}

