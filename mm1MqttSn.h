#ifndef MM1_MQTTSN_HEADER_FILE
#define MM1_MQTTSN_HEADER_FILE

#include "DTCOTSetup.h"

#if CONN_TYPE == NB_IOT

#include <Arduino.h>
#include <Client.h>

#include "mm1MqttSnClientSettings.h"
#include "mqttsn-messages.h"

class MM1MqttSn: public MQTTSN {
public:
  MM1MqttSn( const char* clientId
	, unsigned short brokerPort
	, const char* password
	, Client& ioStream );

public:
  bool init();

  bool publish(
    int topicId
    , const void* value
    );
  
  int connect(const uint8_t flags, const uint16_t duration);
  String connectErrorString(int error);
  void disconnect();
  int RegisterTopicDTCoT(String topic, char valueType);

public:
	void gwinfo_handler( const msg_gwinfo* msg);
	void advertise_handler(const msg_advertise* msg);
	void disconnect_handler(const msg_disconnect* msg);
	void willtopicreq_handler(const message_header* msg);
	void willmsgreq_handler(const message_header* msg);


private:
  String _clientId;
  uint16_t _brokerPort;
  const char* _imsi;
  const char* _password;
  
};

#endif

#endif /* MM1_MQTTSN_HEADER_FILE */
