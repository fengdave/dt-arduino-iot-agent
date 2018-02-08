/**
 * @file DTCoTPrivate.cpp
 * @description Base classes for Authentification and devices
 * @author mm1 Technology GmbH
 * @copyright (C) 2018 Deutsche Telekom AG- all rights reserved. 
 * @licence MIT licence
 */

#include "DTCoTPrivate.h"

using namespace DTCoT;


CoTCommunicationBase::CoTCommunicationBase( 
	const CoTDeviceBase& device
	, const CoTConfigBase& config
	, const CoTAuthBase& authentication )
	: _authentication( authentication)
	, _config( config)
	, _device( device) 
{ } 

CoTDeviceBase::CoTDeviceBase( 
	const CoTConfigBase& deviceConfig)
	: _deviceConfig( deviceConfig) 
{ } 

