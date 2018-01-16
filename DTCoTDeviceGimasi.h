#ifndef DT_COT_DEVICE_GIMASI_HEADER_FILE
#define DT_COT_DEVICE_GIMASI_HEADER_FILE

#include "DTCoTPrivate.h"
#include "DTCoTDeviceNBIoT.h"

namespace DTCoT {

class CoTConfigDeviceGimasi: public CoTConfigDeviceNBIoT {
public:
	CoTConfigDeviceGimasi( );
};


class CoTDeviceGimasi : public CoTDeviceNBIoT {
public:
	CoTDeviceGimasi( const CoTConfigDeviceGimasi& cfg );

public:
	bool init();	

	void errorHandler( const CoTHandlerParam& error );
};

} /* namespace DTCoT */

#endif /* DT_COT_DEVICE_GIMASI_HEADER_FILE */
