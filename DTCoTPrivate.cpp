#include "DTCoTPrivate.h"

using namespace DTCoT;

CoTCommunicationBase::CoTCommunicationBase( 
	const CoTDeviceBase& device
	, const CoTConfigBase& config
	, const CoTAuthBase& authentication )
	: _authentication( authentication)
	, _config( config)
	, _device( device)  {

} 
