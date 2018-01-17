#ifndef MM1_MQTTSN_HEADER_FILE
#define MM1_MQTTSN_HEADER_FILE

#include <Arduino.h>
#include <Client.h>

#include "mm1MqttSnClientSettings.h"
#include "mqttsn-messages.h"

class MM1MqttSn: public MQTTSN {
public:
  MM1MqttSn( const char* clientId
  , unsigned short brokerPort
  , Client& ioStream );

public:
  bool init();

  bool publish( const char* topic
    , unsigned short topicId
    , const void* value
    , unsigned char dataLen );
  
  int connect(const uint8_t flags, const uint16_t duration);
  String connectErrorString(int error);
  void disconnect();

public:
	void gwinfo_handler( const msg_gwinfo* msg);
	void advertise_handler(const msg_advertise* msg);
	void disconnect_handler(const msg_disconnect* msg);
	void willtopicreq_handler(const message_header* msg);
	void willmsgreq_handler(const message_header* msg);


private:
  const char* _clientId;
  uint16_t _brokerPort;
  
};


#endif /* MM1_MQTTSN_HEADER_FILE */
