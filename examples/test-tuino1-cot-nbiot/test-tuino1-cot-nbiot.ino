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

int myMqttsnTopicId = MQTTSN_TOPIC_INVALID_ID;

float exampleTemp = 25.4;
String tmpDirection = "up";
int tmpCounter = 0;
char examplTempStr[10];

using namespace DTCoT;

CoTConfigDeviceGimasi devConfig 
  = CoTConfigDeviceGimasi(NB_IOT_SERVER_IP
    , NB_IOT_SERVER_PORT, NB_IOT_IMSI, NB_IOT_COT_PWD);

CoTDeviceGimasi device = CoTDeviceGimasi(devConfig);

CoTConfigCommunicationMQTTSN mqttsnConfig(NB_IOT_SERVER_IP
    , NB_IOT_SERVER_PORT
    , NB_IOT_IMSI
    , NB_IOT_COT_PWD
    );

CoTCloud cloud( 
  /* Configure communcation settings of your DT Cloud-enabled device */
    device // @todo - why do these need to be instantiated individually? Is it creating them on the stack?
  
  /* Setup the cloud communication method */ 
  , mqttsnConfig
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

DEBUG_PRINT("Setup...");
  cloud.init();
  
  /* Subscribe to the change of a cloud variable of interest */
  cloud.subscribe( CLOUD_COUNTER_VAR_NAME, onCounterValueChanged); // @todo implement

  Serial.println("connected, registering topic...");
  myMqttsnTopicId = cloud.Mqttsn_RegisterTopic(MQTTSN_TOPIC_MEASUREMENT, MQTTSN_MEAS_TYPE_TEMPERATURE);
  if(myMqttsnTopicId == MQTTSN_TOPIC_INVALID_ID)
  {
    /*TODO topic reg failed, disconnect / restart connect*/
    Serial.println("INVALID MQTTSN_TOPIC_ID");
    
  }
  else {
    Serial.println("topic registered, uploading data...");
    Serial.print("myMqttsnTopicId: ");
    Serial.println(myMqttsnTopicId);
  //if(Mqttsn_PublishMeasurementData(myMqttsnTopicId, String(exampleFloat) == false)
  {
    /*TODO data upload failed, disconnect / restart connect*/
   
  }
  }

  
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
    
    if ( !cloud.publish(myMqttsnTopicId, examplTempStr) ) { // @todo, send integers/reals
      /* TODO: process error here */
    }
  }

  delay(1000);
}
}

