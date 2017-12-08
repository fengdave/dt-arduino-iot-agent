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

// NOTE: You need to create this file with  SECRET_WIFI_SSID and SECRET_WIFI_PASSWORD defined
#include "secrets.h"

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


CoTConfigDeviceHUZZAH devConfig = CoTConfigDeviceHUZZAH(SECRET_WIFI_SSID, SECRET_WIFI_PASSWORD );
CoTDeviceHUZZAH device = CoTDeviceHUZZAH(devConfig);

CoTCloud cloud( 
  /* Configure communcation settings of your DT Cloud-enabled device */
    device
  
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
  delay(100);
  Serial.begin(115200);
    delay(100);
   DEBUG_PRINT("Setup...");

// @todo - why is device const? Can't call it ffrom with CoTCloud
device.init();
  cloud.init();
  
  /* Subscribe to the change of a cloud variable of interest */
  cloud.subscribe( CLOUD_COUNTER_VAR_NAME, onCounterValueChanged);
}


void loop() {
     DEBUG_PRINT("Loop");

    //DEBUG_PRINT(device.getWiFiSSID());

  /* Update cloud infrastructure client */
  if ( !cloud.process() ) {
    /* TODO: process error here */


  static unsigned long counter = 0;
  ++counter;

  if ( counter ) {
    if ( !cloud.publish( "cloud-counter", counter) ) {
      /* TODO: process error here */
    }
  }

  delay(1000);
}
}
