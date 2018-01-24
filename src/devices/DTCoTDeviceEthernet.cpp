#include "DTCoTPrivate.h"
#include "DTCoTDeviceEthernet.h"

using namespace DTCoT;

CoTConfigDeviceEthernet::CoTConfigDeviceEthernet( )
	: CoTConfigDevice() 
{ }

CoTDeviceEthernet::CoTDeviceEthernet( 
	const CoTConfigDeviceEthernet& config)
	: CoTDeviceBase( config)
{ }

