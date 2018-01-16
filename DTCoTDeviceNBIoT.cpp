#include "DTCoTPrivate.h"
#include "DTCoTDeviceNBIoT.h"

#include "DTCoTDebugOutput.h"

using namespace DTCoT;

#define DEBUG_PRINT(x) Serial.println(x)

CoTConfigDeviceNBIoT::CoTConfigDeviceNBIoT()
	: CoTConfigDevice( )
{
}

CoTDeviceNBIoT::CoTDeviceNBIoT(	const CoTConfigDeviceNBIoT& nbiotConfig)
	: CoTDeviceBase( nbiotConfig)
{
}

bool CoTDeviceNBIoT::init() {
		DEBUG_PRINT("CoTDeviceNBIoT::init");

	/* TODO: Initialize Gimasi modem here */
	
	return false;
}

Client * DTCoT::CoTDeviceNBIoT::getClient() const {
	return (Client*)(&_nbiotClient);
}
