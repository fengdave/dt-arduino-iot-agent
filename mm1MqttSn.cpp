#include <Arduino.h>

#include "mm1MqttSn.h"

/* MM1MqttSn Library Header File */
/* TODO: make sure platform-dependent WiFi header file is selected */

MM1MqttSn::MM1MqttSn( const char* clientId
  , unsigned short brokerPort
  , Client& ioStream ) 
  : _clientId( clientId)
  , _brokerPort( brokerPort)
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
	Serial.println( "DBG: MM1MqttSn::init()" );
	MQTTSN::searchgw( HOPS_TO_SEARCH_GATEWAY);
}


int MM1MqttSn::connect(const uint8_t flags, const uint16_t duration) {
		MQTTSN::connect(flags, duration, _clientId);
		return 0;
		
}
	
String MM1MqttSn::connectErrorString(int error){
	
	return "DBG: MM1MqttSn::connectErrorString() Error: " + String(error);
	
}

void MM1MqttSn::disconnect() {
	
}

bool MM1MqttSn::publish( const char* topic
  , unsigned short topicId
  , const void* value
  , unsigned char dataLen ) {
  const int tmpFlags = 0;
  MQTTSN::publish( tmpFlags, topicId, value, dataLen);
  return true;  
}

void MM1MqttSn::gwinfo_handler( const msg_gwinfo* msg) {
	Serial.println( "DBG: MM1MqttSn::gwinfo_handler(): GW ID: "
		+ String( msg->gw_id) );

	MQTTSN::gwinfo_handler( msg);

   MQTTSN::connect( FLAG_QOS_0 | FLAG_CLEAN | FLAG_WILL
     , MQTTSN_CONNECTION_DURATION_MS
     , CLIENT_ID );
}

void MM1MqttSn::advertise_handler(const msg_advertise* msg) {
	Serial.println( "DBG: MM1MqttSn::advertise_handler(): GW ID: "
		+ String( msg->gw_id) );

	MQTTSN::advertise_handler( msg);
}

void MM1MqttSn::disconnect_handler(const msg_disconnect* msg) {
	MQTTSN::disconnect_handler( msg);

	Serial.println( "DBG: MM1MqttSn::disconnect_handler()" );
}

void MM1MqttSn::willtopicreq_handler(const message_header* msg) { 
	Serial.println( "DBG: MM1MqttSn::willtopicreq_handler()" );
	MQTTSN::willtopicreq_handler( msg);

	const uint8_t WILL_TOPIC_FLAGS =  0;
   willtopic( WILL_TOPIC_FLAGS, "Will: " CLIENT_ID);
}

void MM1MqttSn::willmsgreq_handler(const message_header* msg) { 
	Serial.println( "DBG: MM1MqttSn::willtopicreq_handler()" );
	MQTTSN::willmsgreq_handler( msg);

	const char* millMsg = "See you next time";
	willmsg( millMsg, sizeof( millMsg) + 1);	
}


