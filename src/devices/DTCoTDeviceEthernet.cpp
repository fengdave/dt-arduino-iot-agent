/**
 * @file DTCoTDeviceEthernet.cpp
 * @description Basic setup and protocol to interact 
 * with the Deutsche Telekom Cloud of things MQTT-SN connector.
 * @author mm1 Technology GmbH
 * @copyright (C) 2018 Deutsche Telekom AG- all rights reserved. 
 * @licence MIT licence
 */

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

