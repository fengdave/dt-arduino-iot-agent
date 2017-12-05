#ifndef MQTTCommunication_h_
#define MQTTCommunication_h_

#include <DTCoTCommunicationBase.h>

namespace DTCoT {
	class MQTTCommunication : public CommunicationBase {
	public:
		MQTTCommunication(DeviceBase & device)
			: CommunicationBase(device)
		{
			
		}
		
		void send(char * key, char * value) {}
	};

}

#endif // MQTTCommunication_h_

