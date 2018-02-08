/**
 * @file DTCoTMqttSn-config.h
 * @description Defines for supported message types for DT CoT via MQTT-SN
 * State of January 2018
 * @author mm1 Technology GmbH
 * @copyright (C) 2017-2018 Deutsche Telekom AG- all rights reserved. 
 * @licence MIT licence
 */
 


#define MQTTSN_TOPIC_INVALID_ID         0

/*Available topics (use with Mqttsn_RegisterTopic())*/
#define MQTTSN_TOPIC_MEASUREMENT        "MES"
#define MQTTSN_TOPIC_ALARM				"ALM" 
#define MQTTSN_TOPIC_EVENT				"EVT" 

/*Avialable measurement types (use with Mqttsn_RegisterTopic())*/
#define MQTTSN_MEAS_TYPE_TEMPERATURE    '1'
#define MQTTSN_MEAS_TYPE_VOLTAGE        '2'
#define MQTTSN_MEAS_TYPE_ACCELERATION   '3'
#define MQTTSN_MEAS_TYPE_LIGHT          '4'
#define MQTTSN_MEAS_TYPE_HUMIDITY       '5'
#define MQTTSN_MEAS_TYPE_MOISTURE       '6'
#define MQTTSN_MEAS_TYPE_DISTANCE       '7'
#define MQTTSN_MEAS_TYPE_CURRENT        '8'
#define MQTTSN_MEAS_TYPE_SIGNALSTRENGTH '9'
#define MQTTSN_MEAS_TYPE_PRESSURE       'A'
#define MQTTSN_MEAS_TYPE_VOLUME         'B'
#define MQTTSN_MEAS_TYPE_WEIGHT         'C'
#define MQTTSN_MEAS_TYPE_FREQUENCY      'D'
