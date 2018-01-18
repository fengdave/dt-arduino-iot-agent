#include <Arduino.h>

#include "mm1MqttSn.h"

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
	Serial.println( "DBG: MM1MqttSn::init()" );
	//MQTTSN::searchgw( HOPS_TO_SEARCH_GATEWAY);
}


int MM1MqttSn::connect(const uint8_t flags, const uint16_t duration) {
		
	Serial.print("BG: MM1MqttSn::connect() with clientId: ");
	Serial.println(_clientId);
	
	_ioStream.connect("",""); /* FIXME: Dummy values because of virtual definition of function */
	
	MQTTSN::connect(flags, duration, _clientId.c_str());
	
	while(waiting_for_response) {
		Serial.println("MM1MqttSn::connect() - calling parse_stream()");
		parse_stream();
    }
	
	Serial.print("BG: MM1MqttSn::connect() Response: ");
	Serial.println((char*)response_buffer);
	
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


int MM1MqttSn::RegisterTopicDTCoT(String topic, char valueType) {
	
	Serial.print("MM1MqttSn::RegisterTopicDTCoT: topic: ");
	Serial.print(topic);
	Serial.print(" - valueType: ");
	Serial.println(valueType);
	
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
	
	Serial.print("MM1MqttSn::RegisterTopicDTCoT(): Payload: ");
	Serial.print("NBIoT/");
	Serial.print("{_imsi}");
	Serial.print(_imsi);
	Serial.print("/{topic}");
	Serial.print(topic);
	Serial.print("/{valueType}");
	Serial.println(valueType);
	
	_ioStream.write(myPayload, myStrLen); /* TODO: add error handling */
    //_ioStream.flush();

    readChars = _ioStream.read((byte*)myPayload, myStrLen);
	if( readChars <= 0 )
  {
    Serial.println("MM1MqttSn::RegisterTopicDTCoT(): Err CoT connection failed.");
  }
  else
  {
	  Serial.print("myStrLen: ");
	  Serial.println(myStrLen);
	  Serial.print("myPayload: ");
	  Serial.println(myPayload);
	  Serial.print("readChars: ");
	  Serial.println(readChars);
	  
	  
	  
    if(readChars == 7)
    {
      /*TODO detailled check of content!*/
      mqttsnTopicId = myPayload[2] * 256;
      mqttsnTopicId += myPayload[3];
      Serial.println("Got topic id: " + String(mqttsnTopicId));
      return mqttsnTopicId;
    }
    else
    {
      Serial.println("Err unknown topic reg response.");
    }
  }
  return mqttsnTopicId;
	
	

	
	
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


