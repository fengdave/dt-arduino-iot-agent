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
#include "DTCoTDeviceWiFi.h"
#include "DTCoTDeviceHUZZAH.h"

/* Application-specific settings and definitions */
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

//DTCoT::CoTCloud cloud( blinkerDevice, cloudConfig);
DTCoT::CoTCloud cloud( blinkerDevice);


void OnConfigError( const DTCoT::CloudMessageHandlerParam& param) {
  
}
void setup() {

  /* Subscribe to device-specific messages */
  blinkerDevice.registerHandler( DTCoT::DeviceHandler::OnConfigError, OnConfigError);
  
  /* Subscribe to relevant */
  cloud.registerHandler( DTCoT::CloudHandler::OnLoginFailed, OnLoginFailed);
  cloud.registerHandler( DTCoT::CloudHandler::OnCloudVarChange, OnCloudVarChange);
  cloud.registerHandler( DTCoT::CloudHandler::OnConnectionEstablished, OnConnectionEstablished);
  cloud.registerHandler( DTCoT::CloudHandler::OnConnectionLost, OnConnectionLost);
  cloud.registerHandler( DTCoT::CloudHandler::OnConnectionTimeOut, OnConnectionTimeOut);
}

/* Check the counter value from the cloud-based variable */
void OnCloudVarChange( const DTCoT::CloudMessageHandlerParam& param) {
  /* Since we know the message - we can correctly cast the parameter */
  const DTCoT::CloudVar cloudVar( param); 
  
  if( cloudVar.name() == "led-blink-counter") {
    if( cloudVar.toInt() >= COUNTER_THRESHOLD) {
        blinkLed10Times();
    }
    else {
      turnLedOff();
    }
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

