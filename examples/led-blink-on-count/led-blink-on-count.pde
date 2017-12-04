/** Cloud-based blinker
 *  
 * Objective:
 * This project demonstrates how simple it is to build a DTCoT application
 * 
 * This example also shows that DTCoT does not depend on device type, 
 * network and protocol libraies, and can be easily extended by adding more 
 * devices and underlaying protocols (as soon as the cloud starts supporting them).
 * 
 * Application description:
 * In this demo there is a counter that will be published as a named variable
 * the cloud and the value of the variable will be sent to the 
 * subcriber (potentialy - another device)
 * When the variable value reaches certain threshold - LED will blink several times
 *
 */

#include "DTCoT.h"

/* Since each and every embedded device is different,
 *  every user is supposed to describe his device to conform 
 *  with DTCoT infrastructure
*/
#include "fona-based-blinker-device.h"

/* Application-specific settings and definitions */
const unsigned char COUNTER_THRESHOLD = 0xFF;

// If you want to use a different wifi library from the default, ie WifiMulti, or
// use an offboard module,etc. you can override this class. 
CoT::CoTDevice blinkerDevice = CoTDeviceAdafruitHUZZAH("mm1-wifi", "password"); 

/* Cloud-specific settings */
const unsigned short CLOUD_SERVER_PORT = 1883;
CoT::ClousConfig cloudConfig = 
  CoT::createCloudConfig( "io.adafruit.com",
    CLOUD_SERVER_PORT, "mqtt_enthusiast",
    "f53d3470b1b0430297a51b8b881587df" );

CoT::CoTCloud cloud = CoT::CreateCotColud( blinkerDevice, cloudConfig);

void setup() {

  /* Subscribe to device-specific messages */
  device.registerHandler( CoT::DeviceHandler::OnConfigError, OnConfigError);
  
  /* Subscribe to relevant */
  cloud.registerHandler( CoT::CloudHandler::OnLoginFailed, OnLoginFailed);
  cloud.registerHandler( CoT::CloudHandler::OnMessageReceived, OnMessageReceived);
  cloud.registerHandler( CoT::CloudHandler::OnConnectionEstablished, OnConnectionEstablished);
  cloud.registerHandler( CoT::CloudHandler::OnConnectionLost, OnConnectionLost);
  cloud.registerHandler( CoT::CloudHandler::OnConnectionTimeOut, OnConnectionTimeOut);
}

/* Check the counter value from the cloud-based variable */
void OnMessageReceived( const CoT::CloudValue& cloudValue) {
  if( cloudValue.toInt() >= COUNTER_THRESHOLD) {
      blinkLed10Times();
  }
  else {
    turnLedOff();
  }
}

void loop() {
  /* Update cloud infrastructure client */
  if( !cloud.process() ) {
    /* TODO: process error here */      
  }

  static unsigned char counter = 0;
  ++counter;
  
  if( counter ) 
  if( !cloud.publish( variable, value) ) {
    /* TODO: process error here */      
  }
}

