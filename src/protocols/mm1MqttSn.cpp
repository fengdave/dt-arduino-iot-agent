/**
 * @file mm1MqttSn.cpp
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

#include "DTCOTSetup.h"

#if CONN_TYPE == NB_IOT

#include <Arduino.h>

#include "mm1MqttSn.h"
#include "utility/DTCoTDebugOutput.h"

/* MM1MqttSn Library Header File */
/* TODO: make sure platform-dependent WiFi header file is selected */

MM1MqttSn::MM1MqttSn( const char* imsi
  , unsigned short brokerPort, const char* password
  , Client& ioStream ) 
  : _clientId( String(String(imsi) + String(password)))
  , _brokerPort( brokerPort)
  ,_imsi(imsi)
  ,_password(password)
  , MQTTSN( ioStream)
  { }

/**
 * \brief bool MM1MqttSn::init()
 * 
 * Add more sophisticated error handling ( getLastError()? )
 * 
 * \return false on error and true if init was successful
*/
bool MM1MqttSn::init() {
	DEBUG_PRINT_INFO("DBG: MM1MqttSn::init()" );
	//MQTTSN::searchgw( HOPS_TO_SEARCH_GATEWAY);
}


int MM1MqttSn::connect(const uint8_t flags, const uint16_t duration) {
		
	DEBUG_PRINT_INFO("BG: MM1MqttSn::connect() with clientId: ");
	DEBUG_PRINT_INFO(_clientId);
	
	_ioStream.connect("",0); /* FIXME: Dummy values because of virtual definition of function */
	
	MQTTSN::connect(flags, duration, _clientId.c_str());
	
	while(waiting_for_response) {
		DEBUG_PRINT_INFO("MM1MqttSn::connect() - calling parse_stream()");
		parse_stream();
    }
	
	DEBUG_PRINT_INFO("BG: MM1MqttSn::connect() Response: ");
	DEBUG_PRINT_INFO((char*)response_buffer);
	
		return 0;
		
}
	
String MM1MqttSn::connectErrorString(int error){
	
	return "DBG: MM1MqttSn::connectErrorString() Error: " + String(error);
	
}

void MM1MqttSn::disconnect() {
	
}

bool MM1MqttSn::publish( 
  int topicId
  , const void* value
  ) {
  const int tmpFlags = 0x20;
  
  int dataLen = strlen((char *)value);
  int trialCounter = 0;

  
  MQTTSN::publish( tmpFlags, topicId, value, dataLen);
  
  while(waiting_for_response) {
		DEBUG_PRINT_INFO("MM1MqttSn::publish() - calling parse_stream()");
		trialCounter++;
		parse_stream();
		DEBUG_PRINT_INFO("MM1MqttSn::publish() - trialCounter: %d", trialCounter);
		if(trialCounter > 2) {
			waiting_for_response = false;
		}
    }
	
	DEBUG_PRINT_INFO("BG: MM1MqttSn::publish() Response: ");
	DEBUG_PRINT_INFO((char*)response_buffer);
	
  return true;  
}


int MM1MqttSn::RegisterTopicDTCoT(String topic, char valueType) {
	
	DEBUG_PRINT_INFO("MM1MqttSn::RegisterTopicDTCoT: topic: " + topic);
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
	
	DEBUG_PRINT_INFO("MM1MqttSn::RegisterTopicDTCoT(): Payload: ");
	DEBUG_PRINT_INFO("NBIoT/");
	DEBUG_PRINT_INFO("{_imsi}");
	DEBUG_PRINT_INFO(_imsi);
	DEBUG_PRINT_INFO("/{topic}");
	DEBUG_PRINT_INFO(topic);
	DEBUG_PRINT_INFO("/{valueType} %dsn-", valueType);
	
	_ioStream.write((uint8_t*)myPayload, myStrLen); /* TODO: add error handling */
    //_ioStream.flush();

    readChars = _ioStream.read((byte*)myPayload, myStrLen);
	if( readChars <= 0 )
  {
    DEBUG_PRINT_INFO("MM1MqttSn::RegisterTopicDTCoT(): Err CoT connection failed.");
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

void MM1MqttSn::gwinfo_handler( const msg_gwinfo* msg) {
	DEBUG_PRINT_INFO( "DBG: MM1MqttSn::gwinfo_handler(): GW ID: "
		+ String( msg->gw_id) );

	MQTTSN::gwinfo_handler( msg);

   MQTTSN::connect( FLAG_QOS_0 | FLAG_CLEAN | FLAG_WILL
     , MQTTSN_CONNECTION_DURATION_MS
     , CLIENT_ID );
}

void MM1MqttSn::advertise_handler(const msg_advertise* msg) {
	DEBUG_PRINT_INFO( "DBG: MM1MqttSn::advertise_handler(): GW ID: "
		+ String( msg->gw_id) );

	MQTTSN::advertise_handler( msg);
}

void MM1MqttSn::disconnect_handler(const msg_disconnect* msg) {
	MQTTSN::disconnect_handler( msg);

	DEBUG_PRINT_INFO("DBG: MM1MqttSn::disconnect_handler()" );
}

void MM1MqttSn::willtopicreq_handler(const message_header* msg) { 
	DEBUG_PRINT_INFO("DBG: MM1MqttSn::willtopicreq_handler()" );
	MQTTSN::willtopicreq_handler( msg);

	const uint8_t WILL_TOPIC_FLAGS =  0;
   willtopic( WILL_TOPIC_FLAGS, "Will: " CLIENT_ID);
}

void MM1MqttSn::willmsgreq_handler(const message_header* msg) { 
	DEBUG_PRINT_INFO("DBG: MM1MqttSn::willtopicreq_handler()" );
	MQTTSN::willmsgreq_handler( msg);

	const char* millMsg = "See you next time";
	willmsg( millMsg, sizeof( millMsg) + 1);	
}


#endif
