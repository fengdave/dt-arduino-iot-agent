#ifndef DT_COT_DEVICE_FEATHER_M0_NBIOT_HEADER_FILE
#define DT_COT_DEVICE_FEATHER_M0_NBIOT_HEADER_FILE


#include "DTCOTSetup.h"

#if CONN_TYPE == NB_IOT

#include "DTCoTPrivate.h"
#include "devices/DTCoTDeviceNBIoT.h"

namespace DTCoT {

class CoTConfigDeviceFeatherM0_NBIoT: public CoTConfigDeviceNBIoT {
public:
	CoTConfigDeviceFeatherM0_NBIoT(const char* serverIP, const unsigned short serverPort, const char* imsi, const char* password  );
};


class CoTDeviceFeatherM0_NBIoT : public CoTDeviceNBIoT {
public:
	CoTDeviceFeatherM0_NBIoT(  CoTConfigDeviceFeatherM0_NBIoT& cfg );

public:
	bool init();	

	void errorHandler( const CoTHandlerParam& error );
};

} /* namespace DTCoT */

#endif

#endif /* DT_COT_DEVICE_FEATHER_M0_HEADER_NBIOT_FILE */
