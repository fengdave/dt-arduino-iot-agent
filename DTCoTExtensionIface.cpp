#include "DTCoTExtensionIface.h"

using namespace DTCoT;

CoTMQTTCommunication::CoTMQTTCommunication(
	const CoTDeviceBase& device
	, const CoTConfigBase& config
	, const CoTAuthBase& authentication )
	: CoTCommunicationBase( device, config, authentication) 
{
}

CoTConfigDevice::CoTConfigDevice(): CoTConfigBase() { }

