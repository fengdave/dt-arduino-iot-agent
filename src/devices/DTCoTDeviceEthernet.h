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

