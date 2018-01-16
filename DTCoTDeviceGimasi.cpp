#include "DTCoTDeviceGimasi.h"

#include "DTCoTDebugOutput.h"

using namespace DTCoT;

#define DEBUG_PRINT(x) Serial.println(x) 

CoTConfigDeviceGimasi::CoTConfigDeviceGimasi ( )
	: CoTConfigDeviceNBIoT( )
{
}

CoTDeviceGimasi::CoTDeviceGimasi( const CoTConfigDeviceNBIoT& config)
	: CoTDeviceNBIoT( config)
 {
 }

bool CoTDeviceGimasi::init() {
	CoTDeviceNBIoT::init();
		 DEBUG_PRINT("CoTDeviceGimasi::CoTDeviceGimasi");
	return false;
}

void CoTDeviceGimasi::errorHandler( const CoTHandlerParam& error )
{ }


