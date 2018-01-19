#ifndef DT_COT_DEVICE_GIMASI_HEADER_FILE
#define DT_COT_DEVICE_GIMASI_HEADER_FILE

#include "DTCOTSetup.h"

#if CONN_TYPE == NB_IOT

#include "DTCoTPrivate.h"
#include "DTCoTDeviceNBIoT.h"

namespace DTCoT {

class CoTConfigDeviceGimasi: public CoTConfigDeviceNBIoT {
public:
	CoTConfigDeviceGimasi(const char* serverIP, const unsigned short serverPort, const char* imsi, const char* password  );
};


class CoTDeviceGimasi : public CoTDeviceNBIoT {
public:
	CoTDeviceGimasi(  CoTConfigDeviceGimasi& cfg );

public:
	bool init();	

	void errorHandler( const CoTHandlerParam& error );
};

} /* namespace DTCoT */

#endif

#endif /* DT_COT_DEVICE_GIMASI_HEADER_FILE */
