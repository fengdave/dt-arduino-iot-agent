#ifndef DT_COT_DEVICE_FEATHER_M0_HEADER_FILE
#define DT_COT_DEVICE_FEATHER_M0_HEADER_FILE

#include "DTCoT.h"

namespace DTCoT {

class CoTConfigDeviceFeatherM0: public CoTConfigBase {
public:
	CoTConfigDeviceFeatherM0( /* TODO: Any FeatherM0-specific params here */);
};

class CoTDeviceFeatherM0: public CoTDeviceWiFi {
public:
	CoTDeviceFeatherM0( const CoTConfigDeviceFeatherM0& cfg );
};

} /* namespace DTCoT */

#endif /* DT_COT_DEVICE_FEATHER_M0_HEADER_FILE */
