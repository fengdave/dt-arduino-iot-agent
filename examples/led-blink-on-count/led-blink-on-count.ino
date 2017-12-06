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

/* Application-specific settings and definitions */
#define CLOUD_COUNTER_VAR_NAME "cloud-counter"
#define ON_BOARD_LED 13
const unsigned char COUNTER_THRESHOLD = 0xFF;



DTCoT::CoTConfigDeviceHUZZAH blinkerDeviceConfig( "mm1-wifi", "password");

DTCoT::CoTDeviceHUZZAH blinkerDevice( blinkerDeviceConfig);

/* Cloud-specific settings */
const unsigned short CLOUD_SERVER_PORT = 1883;
DTCoT::CoTCloudConfig cloudConfig ( "io.adafruit.com"
                                    , "mqtt_enthusiast"
                                    , CLOUD_SERVER_PORT
                                  );

/* Adafruit UserID: "f53d3470b1b0430297a51b8b881587df"  - Adafruit-specific setting */

DTCoT::CoTCloud cloud( blinkerDevice, cloudConfig);

void OnConfigError( void* error) {
  /* TODO: check delivered param
     TODO: cast to the known error type
     TODO: process the error accordingly
  */
}

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
  /* Subscribe to device-specific messages */
  //  blinkerDevice.registerHandler( DTCoT::DeviceHandler::OnConfigError, OnConfigError);

  /* Subscribe to relevant */
  //  cloud.registerHandler( DTCoT::CloudHandler::OnLoginFailed, OnLoginFailed);
  //  cloud.registerHandler( DTCoT::CloudHandler::OnCloudVarChange, OnCloudVarChange);
  //  cloud.registerHandler( DTCoT::CloudHandler::OnConnectionEstablished, OnConnectionEstablished);
  //  cloud.registerHandler( DTCoT::CloudHandler::OnConnectionLost, OnConnectionLost);
  //  cloud.registerHandler( DTCoT::CloudHandler::OnConnectionTimeOut, OnConnectionTimeOut);

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

  if ( counter )
    if ( !cloud.publish( "cloud-counter", counter) ) {
      /* TODO: process error here */
    }
}

