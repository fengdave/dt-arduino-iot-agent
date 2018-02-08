/**
 * @file DTCoTDeviceEthernet.cpp
 * @description Base class for management and operations for all ethernet devices
 * @author mm1 Technology GmbH
 * @copyright (C) 2017-2018 Deutsche Telekom AG- all rights reserved. 
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

