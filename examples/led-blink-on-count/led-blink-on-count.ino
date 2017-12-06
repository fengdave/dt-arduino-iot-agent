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

/* Application-specific settings */
const unsigned char ON_BOARD_LED = 13;
const char* CLOUD_COUNTER_VAR_NAME = "cloud-counter";

const unsigned char COUNTER_THRESHOLD = 0xFF;

const unsigned short CLOUD_SERVER_PORT = 1883;
const char* CLOUD_SERVER_PASSWORD = "mqtt_enthusiast";
const char* ADAFRUIT_USER_ID = "f53d3470b1b0430297a51b8b881587df";

using namespace DTCoT;

/* Setup the Cloud access and the device to communicate to cloud 
 */
CoTCloud cloud( 
  /* Configure communcation settings of your DT Cloud-enabled device */
  CoTDeviceHUZZAH( 
    CoTConfigDeviceHUZZAH( "mm1-wifi", "password" )
  )
  
  /* Setup the cloud communication method */ 
  , CoTConfigCommunicationMQTT( "io.adafruit.com"
    , CLOUD_SERVER_PORT
    , CLOUD_SERVER_PASSWORD
    , ADAFRUIT_USER_ID
  )
);


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
  /* Subscribe to the change of a cloud variable of interest */
  cloud.subscribe( CLOUD_COUNTER_VAR_NAME, onCounterValueChanged);
}


void loop() {
  /* Update cloud infrastructure client */
  if ( !cloud.process() ) {
    /* TODO: process error here */
  }

  static unsigned long counter = 0;
  ++counter;

  if ( counter ) {
    if ( !cloud.publish( "cloud-counter", counter) ) {
      /* TODO: process error here */
    }
  }
}

