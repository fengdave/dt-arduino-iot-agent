/**
 * @file {{file}}
 * @description Basic setup and protocol to interact 
 * with the Deutsche Telekom Cloud of things MQTT-SN connector.
 * @author Andreas Krause
 * @copyright (C) 2018 mm1 Technology GmbH - all rights reserved. 
 * @licence MIT licence
 * 
 * Find out more about mm1 Technology:
 * Company: http://mm1-technology.de/
 * GitHub:  https://github.com/mm1technology/
 */

#ifndef MM1_MQTTSN_CLIENT_SETTINGS_HEADER_FILE
#define MM1_MQTTSN_CLIENT_SETTINGS_HEADER_FILE

#define WIFI_SSID ""
#define WIFI_PASSWORD ""

#define WIFI_CONNECTION_RETRY_DELAY_MS 100

#define BROADCAST_IP_ADDRESS "255.255.255.255"
#define CLIENT_ID "mm1-test-client"
#define MQTTSN_BROKER_PORT 1883
#define MQTTSN_CLIENT_LOCAL_PORT 1055
#define MQTTSN_CONNECTION_DURATION_MS 10000
#define HOPS_TO_SEARCH_GATEWAY 1

/* Select one of network interfaces */
#define USE_NETWORK_INTERFACE_NBIOT 1
// #define USE_NETWORK_INTERFACE_WIFI 1
// #define USE_NETWORK_INTERFACE_GPRS 1

#endif /* MM1_MQTTSN_CLIENT_SETTINGS_HEADER_FILE */
