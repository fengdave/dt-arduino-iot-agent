/**
 * @file test-tuino1-cot-nbiot.ino
 * @description Simple Demo
 * @description Simple Demo for CoT Library using NB-IoT
 * @author mm1 Technology GmbH
 * @copyright (C) 2018 Deutsche Telekom AG- all rights reserved. 
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


#include "DTCoT.h"
/* NOTE: You need to create this secrets.h file with the following defines:
 #define NB_IOT_IMSI           "<IMSI, as found in the logs of your device>" 
 #define NB_IOT_COT_PWD        "<password for access to the server>"
*/
#include "secrets.h"

// Make sure we are using the correct hardware configuration for NB_IOT
#if CONN_TYPE != NB_IOT
#error("You need to enable NB_IOT in the config!")
#endif

/* Application-specific settings */
const unsigned char ON_BOARD_LED = 13;

/* The name of tthe variable on the server */
const char* CLOUD_COUNTER_VAR_NAME = "cloud-counter";

/* Wrap after this number */
const unsigned char COUNTER_THRESHOLD = 0xFF;

int myMqttsnTopicId = MQTTSN_TOPIC_INVALID_ID;

/** Simulation of temperature values **/
float exampleTemp = 25.4;
String tmpDirection = "up";
int tmpCounter = 0;
char examplTempStr[10];

using namespace DTCoT;

/* Configure a Gimasi Tuino 1 device, connected to the CoT server */
CoTConfigDeviceGimasi devConfig 
  = CoTConfigDeviceGimasi(NB_IOT_SERVER_IP
    , NB_IOT_SERVER_PORT, NB_IOT_IMSI, NB_IOT_COT_PWD
	, Serial1 				// serial port to use for the NBIoT hardware
	, GMX_RESET);			// reset pin to use for the NBIoT hardware

/* Create the device */
CoTDeviceGimasi device = CoTDeviceGimasi(devConfig);

/* Configure connection to the MQTT-SN backend */
CoTConfigCommunicationMQTTSN mqttsnConfig(NB_IOT_SERVER_IP
    , NB_IOT_SERVER_PORT
    , NB_IOT_IMSI
    , NB_IOT_COT_PWD
    );

CoTCloud cloud( 
  /* Configure communcation settings of your DT Cloud-enabled device */
    device 
  
  /* Setup the cloud communication method */ 
  , mqttsnConfig
);


/** Back channel is not supported yet **/
void onCounterValueChanged( void* newCounterValue) {
  /* TODO: parameter NULL check
     TODO: casting outcome check
     TODO: provide helper-macro for easy app-specific casting
     TODO: figure out how to avoid casting for different payload types
  */
  unsigned long counterValue = *(static_cast< unsigned long*>(newCounterValue) );

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


void loop() {
  DEBUG_PRINT("Loop");


  /* Update cloud infrastructure client */
  if ( !cloud.process() ) {
    /* TODO: process error here */
  }

  static unsigned long counter = 0;
  ++counter;

  if ( counter ) {

      if (tmpDirection == "up") {
          if(tmpCounter < 10) {
            exampleTemp += 0.5;
            tmpCounter++;
          }
          else {
            tmpCounter = 0;
            tmpDirection = "down";
            exampleTemp -= 0.5;
          }
      }
      else {
        if(tmpCounter < 10) {
            exampleTemp -= 0.5;
            tmpCounter++;
          }
          else {
            tmpCounter = 0;
            tmpDirection = "up";
            exampleTemp += 0.5;
          }
      }

     dtostrf(exampleTemp, 2, 2, examplTempStr);
     DEBUG_PRINT("### Sending Temperature: %s", examplTempStr);

    /* Publish our updated temperature value to the CoT server */
    if ( !cloud.publish(myMqttsnTopicId, examplTempStr) ) { // @todo, send integers/reals
      /* TODO: process error here */
    }
  }

  delay(1000);
}

