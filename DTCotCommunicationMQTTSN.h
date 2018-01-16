#ifndef MQTTSNCommunication_h_
#define MQTTSNCommunication_h_

#include "DTCoTPrivate.h"
#include "DTCoTCommunicationBase.h"

namespace DTCoT {
	
class CoTCommunicationMQTTSN: public CoTCommunicationBase {
public:
	CoTCommunicationMQTTSN(const CoTDeviceBase& device
		, const CoTConfigBase& config );
	
	void init();
	
	void publish(const char * key, const char * value);
	
private:
	void reconnect();
	
private:	
	NbiotClient _nbiotClient;
};

}

#endif // MQTTCommunication_h_

