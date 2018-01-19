
#include "DTCOTSetup.h"

#if CONN_TYPE == NB_IOT

#include "DTCoTDeviceGimasi.h"

#include "DTCoTDebugOutput.h"

using namespace DTCoT;

#define DEBUG_PRINT(x) Serial.println(x) 

CoTConfigDeviceGimasi::CoTConfigDeviceGimasi ( 
	const char* serverIP
	, const unsigned short serverPort
	, const char* imsi
	, const char* password)
	: CoTConfigDeviceNBIoT( serverIP, serverPort, 
		imsi, password)
{
	
   
}

CoTDeviceGimasi::CoTDeviceGimasi(  CoTConfigDeviceGimasi& config)
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


#endif