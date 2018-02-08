/**
 * @file DTCoTMqttSnClientSettings.h
 * @description Basic setup and protocol to interact 
 * with the Deutsche Telekom Cloud of things MQTT-SN connector.
 * @author mm1 Technology GmbH
 * @copyright (C) 2017-2018 Deutsche Telekom AG- all rights reserved. 
 * @licence MIT licence
 */
 
 /**
 * CHECK IF THIS FILE IS STILL NEEDED!!
 **/
#ifndef DTCOT_MQTTSN_CLIENT_SETTINGS_HEADER_FILE
#define DTCOT_MQTTSN_CLIENT_SETTINGS_HEADER_FILE

#define WIFI_SSID ""
#define WIFI_PASSWORD ""

#define WIFI_CONNECTION_RETRY_DELAY_MS 100

#define BROADCAST_IP_ADDRESS "255.255.255.255"
#define CLIENT_ID "dtcot-test-client"
#define MQTTSN_BROKER_PORT 1883
#define MQTTSN_CLIENT_LOCAL_PORT 1055
#define MQTTSN_CONNECTION_DURATION_MS 10000
#define HOPS_TO_SEARCH_GATEWAY 1

/* Select one of network interfaces */
#define USE_NETWORK_INTERFACE_NBIOT 1
// #define USE_NETWORK_INTERFACE_WIFI 1
// #define USE_NETWORK_INTERFACE_GPRS 1

#endif /* DTCOT_MQTTSN_CLIENT_SETTINGS_HEADER_FILE */
