/**
 * @file DTCoTMqttSn-config.h
 * @description Basic setup and protocol to interact 
 * with the Deutsche Telekom Cloud of things MQTT-SN connector.
 * @author Lyn Matten
 * @copyright (C) 2018 mm1 Technology GmbH - all rights reserved. 
 * @licence MIT licence
 * 
 * Find out more about mm1 Technology:
 * Company: http://mm1-technology.de/
 * GitHub:  https://github.com/mm1technology/
 */
 


#define MQTTSN_TOPIC_INVALID_ID         0

/*Available topics (use with Mqttsn_RegisterTopic())*/
#define MQTTSN_TOPIC_MEASUREMENT        "MES"
#define MQTTSN_TOPIC_ALARM				"ALM" /* not supported by CoT at 01/2018 */
#define MQTTSN_TOPIC_EVENT				"EVT" /* not supported by CoT at 01/2018 */

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
