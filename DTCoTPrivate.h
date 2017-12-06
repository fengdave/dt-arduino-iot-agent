#ifndef DT_COT_PRIVATE_HEADER_FILE 
#define DT_COT_PRIVATE_HEADER_FILE 

/* DTCoT Private abstraction interface */

namespace DTCoT 
{

/* Handler and payload-related infrastructure */
typedef void* CoTHandlerParam;
typedef void (*CoTHandler)(CoTHandlerParam);


/* DTCoT Library Base Classes (will not be instantiated directly; 
 * to be used in platform/config/communication-independent code)
 * ----------------------------
 */
class CoTConfigBase { };

class CoTDeviceBase {
public:
	CoTDeviceBase( const CoTConfigBase& deviceConfig);

public:
	virtual bool init() = 0;

	/* Overload to get the device-specific error handler */
	virtual void errorHandler( const CoTHandlerParam handler ) { };

private:
	const CoTConfigBase& _deviceConfig;
};

/* Base class to distinguish between authentication details (like TLS/Fingerprint) */
class CoTAuthBase { };

class CoTCommunicationBase {
	CoTCommunicationBase( const CoTDeviceBase& device
		, const CoTConfigBase& config
		, const CoTAuthBase& authentication ); 

private:
	const CoTAuthBase& _authentication;
	const CoTConfigBase& _config;
	const CoTDeviceBase& _device;
}; 


} /* namespace DTCoT */

#endif /* DT_COT_PRIVATE_HEADER_FILE */

