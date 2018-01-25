/**
 * @file dt-cot-feather-m0-mqtt-test.ino
 * @description Simple Demo for CoT Library using MQTT
 * PLEASE NOTE: Because MQTT endpoint at CoT is not available at the moment this example can be used e.g. with adafruit mqtt broker
 *  @author Lyn Matten
 * @copyright (C) 2018 mm1 Technology GmbH - all rights reserved. 
 * @licence MIT licence
 * 
 * Find out more about mm1 Technology:
 * Company: http://mm1-technology.de/
 * GitHub:  https://github.com/mm1technology/
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

#include <avr/dtostrf.h>
#include "DTCoT.h"
// NOTE: You need to create this file with  SECRET_WIFI_SSID and SECRET_WIFI_PASSWORD defined
#include "secrets.h"

/* Application-specific settings */
const unsigned char ON_BOARD_LED = 13;
const char* CLOUD_COUNTER_VAR_NAME = "cloud-counter";

const unsigned char COUNTER_THRESHOLD = 0xFF;

const unsigned short CLOUD_SERVER_PORT = 1883;

/** Simulation of temperature values **/
float exampleTemp = 25.4;
String tmpDirection = "up";
int tmpCounter = 0;
char examplTempStr[10];



#if !defined(CLOUD_SERVER_PASSWORD) || !defined(ADAFRUIT_USER_ID)
#error "Can't find Cloud credentials: Create secrets.h file and place it next to this example (see readme for details)"
#endif /* CLOUD_SERVER_PASSWORD */

using namespace DTCoT;

/* Setup the Cloud access and the device to communicate to cloud 
 */


CoTConfigDeviceFeatherM0_WiFi devConfig = CoTConfigDeviceFeatherM0_WiFi(SECRET_WIFI_SSID, SECRET_WIFI_PASSWORD );
CoTDeviceFeatherM0_WiFi device = CoTDeviceFeatherM0_WiFi(devConfig);

CoTConfigCommunicationMQTT mqttConfig = CoTConfigCommunicationMQTT( "io.adafruit.com"
    , CLOUD_SERVER_PORT
    , CLOUD_SERVER_PASSWORD
    , ADAFRUIT_USER_ID
  );

CoTCloud cloud( 
  /* Configure communcation settings of your DT Cloud-enabled device */
    device 
  
  /* Setup the cloud communication method */ 
  , mqttConfig
);


/* Back channel not implemented yet */
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
   DEBUG_PRINT("Setup...");

   //Configure pins for Adafruit ATWINC1500 Feather
  WiFi.setPins(8,7,4,2);

  
  device.init();
  cloud.init();
  
  /* Subscribe to the change of a cloud variable of interest */
  cloud.subscribe( CLOUD_COUNTER_VAR_NAME, onCounterValueChanged); // @todo implement
}


void loop() {
     DEBUG_PRINT("Loop");

	
  /* Update cloud infrastructure client */
  if ( !cloud.process() ) {
    /* TODO: process error here */


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
     Serial.print("### Sending Temperature: ");
     Serial.println(examplTempStr);
    
    if ( !cloud.publish( "{feed_name}", examplTempStr) ) { 
      /* TODO: process error here */
    }
  }

  delay(30000);
}
}

