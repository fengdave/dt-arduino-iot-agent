/**
 * @file DTCoTMqttSn.cpp
 * @description DT CoT specific MQTT-SN layer
 * @author mm1 Technology GmbH
 * @copyright (C) 2017-2018 Deutsche Telekom AG- all rights reserved. 
 * @licence MIT licence
 */

#include "DTCOTSetup.h"

#if CONN_TYPE == NB_IOT

#include <Arduino.h>

#include "DTCoTMqttSn.h"
#include "utility/DTCoTDebugOutput.h"

/* DTCoTMqttSn Library Header File */
/* TODO: make sure platform-dependent WiFi header file is selected */

DTCoTMqttSn::DTCoTMqttSn( const char* imsi
  , unsigned short brokerPort, const char* password
  , Client& ioStream ) 
  : _clientId( String(String(imsi) + String(password)))
  , _brokerPort( brokerPort)
  ,_imsi(imsi)
  ,_password(password)
  , MQTTSN( ioStream)
  { }

/**
 * \brief bool DTCoTMqttSn::init()
 * 
 * Add more sophisticated error handling ( getLastError()? )
 * 
 * \return false on error and true if init was successful
*/
bool DTCoTMqttSn::init() {
	DEBUG_PRINT_INFO("DBG: DTCoTMqttSn::init()" );
	//MQTTSN::searchgw( HOPS_TO_SEARCH_GATEWAY);
}


int DTCoTMqttSn::connect(const uint8_t flags, const uint16_t duration) {
		
	DEBUG_PRINT_INFO("BG: DTCoTMqttSn::connect() with clientId: ");
	DEBUG_PRINT_INFO(_clientId);
	
	_ioStream.connect("",0); /* FIXME: Dummy values because of virtual definition of function */
	
	MQTTSN::connect(flags, duration, _clientId.c_str());
	
	while(waiting_for_response) {
		DEBUG_PRINT_INFO("DTCoTMqttSn::connect() - calling parse_stream()");
		parse_stream();
    }
	
	DEBUG_PRINT_INFO("BG: DTCoTMqttSn::connect() Response: ");
	DEBUG_PRINT_INFO((char*)response_buffer);
	
		return 0;
		
}
	
String DTCoTMqttSn::connectErrorString(int error){
	
	return "DBG: DTCoTMqttSn::connectErrorString() Error: " + String(error);
	
}

void DTCoTMqttSn::disconnect() {
	
}

bool DTCoTMqttSn::publish(
  int topicId
  , const void* value
  ) {
  const int tmpFlags = 0x20;
  
  int dataLen = strlen((char *)value);
  int trialCounter = 0;

  
  MQTTSN::publish( tmpFlags, topicId, value, dataLen);
  
  while(waiting_for_response) {
		DEBUG_PRINT_INFO("DTCoTMqttSn::publish() - calling parse_stream()");
		trialCounter++;
		parse_stream();
		DEBUG_PRINT_INFO("DTCoTMqttSn::publish() - trialCounter: %d", trialCounter);
		if(trialCounter > 2) {
			waiting_for_response = false;
		}
    }
	
	DEBUG_PRINT_INFO("BG: DTCoTMqttSn::publish() Response: ");
	DEBUG_PRINT_INFO((char*)response_buffer);
	
  return true;  
}


int DTCoTMqttSn::RegisterTopicDTCoT(String topic, char valueType) {
	
	DEBUG_PRINT_INFO("DTCoTMqttSn::RegisterTopicDTCoT: topic: " + topic);
	DEBUG_PRINT_INFO(" - valueType: %c", valueType);
	
	/*                               len   type  topicId     msgId*/
	char myPayload[255] = {/*FIXME:*/0x00, 0x0A, 0x00, 0x00, (char)(_message_id / 256), (char)(_message_id % 256)};
	int myStrLen;
	byte readChars;
	
	int mqttsnTopicId = 0;
	
	/*protocol header*/
    _message_id++;
  	myStrLen = 6;
  	/*IMSI of the SIM card + topic selection*/
  	myStrLen += sprintf(&(myPayload[myStrLen]), ("NBIoT/" + String(_imsi) + "/" + topic + "/").c_str());
  	myPayload[myStrLen] = valueType;
  	myStrLen++;
  	/*FIXME this payload length treatment doesn't work for sizes (>127)!*/
  	myPayload[0] = (char)myStrLen;
	
	DEBUG_PRINT_INFO("DTCoTMqttSn::RegisterTopicDTCoT(): Payload: NBIoT/{_imsi}%s/{topic}"+topic+"/{valueType}%c ",_imsi, valueType);
	
	
	_ioStream.write((uint8_t*)myPayload, myStrLen); /* TODO: add error handling */
    //_ioStream.flush();

    readChars = _ioStream.read((byte*)myPayload, myStrLen);
	if( readChars <= 0 )
  {
    DEBUG_PRINT_INFO("DTCoTMqttSn::RegisterTopicDTCoT(): Err CoT connection failed.");
  }
  else
  {
	  DEBUG_PRINT_INFO("myStrLen: %d", myStrLen);
	  DEBUG_PRINT_INFO("myPayload: ");
	  DEBUG_PRINT_INFO(myPayload);
	  DEBUG_PRINT_INFO("readChars: %d", readChars);
	  
	  
	  
    if(readChars == 7)
    {
      /*TODO detailled check of content!*/
      mqttsnTopicId = myPayload[2] * 256;
      mqttsnTopicId += myPayload[3];
      DEBUG_PRINT_INFO("Got topic id: " + String(mqttsnTopicId));
      return mqttsnTopicId;
    }
    else
    {
      DEBUG_PRINT_INFO("Err unknown topic reg response.");
    }
  }
  return mqttsnTopicId;
	
	

	
	
}

void DTCoTMqttSn::gwinfo_handler( const msg_gwinfo* msg) {
	DEBUG_PRINT_INFO( "DBG: DTCoTMqttSn::gwinfo_handler(): GW ID: "
		+ String( msg->gw_id) );

	MQTTSN::gwinfo_handler( msg);

   MQTTSN::connect( FLAG_QOS_0 | FLAG_CLEAN | FLAG_WILL
     , MQTTSN_CONNECTION_DURATION_MS
     , CLIENT_ID );
}

void DTCoTMqttSn::advertise_handler(const msg_advertise* msg) {
	DEBUG_PRINT_INFO( "DBG: DTCoTMqttSn::advertise_handler(): GW ID: "
		+ String( msg->gw_id) );

	MQTTSN::advertise_handler( msg);
}

void DTCoTMqttSn::disconnect_handler(const msg_disconnect* msg) {
	MQTTSN::disconnect_handler( msg);

	DEBUG_PRINT_INFO("DBG: DTCoTMqttSn::disconnect_handler()" );
}

void DTCoTMqttSn::willtopicreq_handler(const message_header* msg) {
	DEBUG_PRINT_INFO("DBG: DTCoTMqttSn::willtopicreq_handler()" );
	MQTTSN::willtopicreq_handler( msg);

	const uint8_t WILL_TOPIC_FLAGS =  0;
   willtopic( WILL_TOPIC_FLAGS, "Will: " CLIENT_ID);
}

void DTCoTMqttSn::willmsgreq_handler(const message_header* msg) {
	DEBUG_PRINT_INFO("DBG: DTCoTMqttSn::willtopicreq_handler()" );
	MQTTSN::willmsgreq_handler( msg);

	const char* millMsg = "See you next time";
	willmsg( millMsg, sizeof( millMsg) + 1);	
}


#endif
