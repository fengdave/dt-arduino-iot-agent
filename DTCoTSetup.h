#ifndef DTCoT_SETUP_HEADER_FILE
#define DTCoT_SETUP_HEADER_FILE

/* Select the cloud communication method here 
 * (Uncomment the desired cloud communication method)
 * --------------------
 */

#define COMMUNICATION_MQTT
// #define COMMUNICATION_MQTT_SN
// #define COMMUNICATION_REST
// #define COMMUNICATION_RAW_SOCKET

/* Select the MQTT Broker here 
 * (Uncomment the desired MQTT broker)
 * --------------------
 */

/* io.adaafruit.com*/
#define MQTT_BROKER_ADAFRUIT
#define MQTT_BROKER_DT

/* https://docs.microsoft.com/en-us/azure/iot-hub/iot-hub-mqtt-support */
#define MQTT_BROKER_AZURE

#endif /* DTCoT_SETUP_HEADER_FILE */

