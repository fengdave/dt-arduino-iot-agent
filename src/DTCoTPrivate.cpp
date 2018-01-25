/**
 * @file {{file}}
 * @description Basic setup and protocol to interact 
 * with the Deutsche Telekom Cloud of things MQTT-SN connector.
 * @author Andreas Krause
 * @copyright (C) 2018 mm1 Technology GmbH - all rights reserved. 
 * @licence MIT licence
 * 
 * Find out more about mm1 Technology:
 * Company: http://mm1-technology.de/
 * GitHub:  https://github.com/mm1technology/
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

