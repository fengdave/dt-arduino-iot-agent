#ifndef DT_COT_DEVICE_ETHERNET_HEADER_FILE
#define DT_COT_DEVICE_ETHERNET_HEADER_FILE

#include "DTCoTPrivate.h"

namespace DTCoT {

class CoTDeviceEthernet: public CoTDeviceBase { 
public:
	CoTDeviceEthernet( const CoTDeviceConfig& deviceConfig);

};

} /* namespace DTCoT */

#endif /* DT_COT_DEVICE_ETHERNET_HEADER_FILE */

