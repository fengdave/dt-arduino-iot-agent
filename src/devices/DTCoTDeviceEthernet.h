/**
 * @file DTCoTDeviceEthernet.h
 * @description header file for base class for management and operations for all ethernet devices
 * @author mm1 Technology GmbH
 * @copyright (C) 2017-2018 Deutsche Telekom AG- all rights reserved. 
 * @licence MIT licence
 */

#ifndef DT_COT_DEVICE_ETHERNET_HEADER_FILE
#define DT_COT_DEVICE_ETHERNET_HEADER_FILE

#include "DTCoTPrivate.h"
#include "DTCoTExtensionIface.h"

namespace DTCoT {

   /**
    * Config class for generic Ethernet device.
    */
class CoTConfigDeviceEthernet: public CoTConfigDevice {
public:
	CoTConfigDeviceEthernet();
};


/**
 * Config class for generic Ethernet-capable device.
 */
class CoTDeviceEthernet: public CoTDeviceBase { 
public:
	CoTDeviceEthernet( const CoTConfigDeviceEthernet& config);
};


} /* namespace DTCoT */

#endif /* DT_COT_DEVICE_ETHERNET_HEADER_FILE */

