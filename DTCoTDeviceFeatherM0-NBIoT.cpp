
#include "DTCOTSetup.h"

#if CONN_TYPE == NB_IOT

#include "DTCoTDeviceFeatherM0-NBIoT.h"

#include "DTCoTDebugOutput.h"

using namespace DTCoT;

#define DEBUG_PRINT(x) Serial.println(x) 

CoTConfigDeviceFeatherM0_NBIoT::CoTConfigDeviceFeatherM0_NBIoT ( 
	const char* serverIP
	, const unsigned short serverPort
	, const char* imsi
	, const char* password)
	: CoTConfigDeviceNBIoT( serverIP, serverPort, 
		imsi, password)
{
	
   
}

CoTDeviceFeatherM0_NBIoT::CoTDeviceFeatherM0_NBIoT(  CoTConfigDeviceFeatherM0_NBIoT& config)
	: CoTDeviceNBIoT( config)
 {
 }

bool CoTDeviceFeatherM0_NBIoT::init() {
	CoTDeviceNBIoT::init();
	DEBUG_PRINT("CoTDeviceFeatherM0_NBIoT::CoTDeviceFeatherM0_NBIoT");
	
	return false;
}

void CoTDeviceFeatherM0_NBIoT::errorHandler( const CoTHandlerParam& error )
{ }


#endif