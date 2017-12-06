#ifndef DT_COT_PRIVATE_HEADER_FILE 
#define DT_COT_PRIVATE_HEADER_FILE 

/* DTCoT Private abstraction interface */

namespace DTCoT 
{

/* Handler and payload-related infrastructure */
typedef void* CoTHandlerParam;
typedef void (*CoTHandler)(CoTHandlerParam);

/* Base class for all kind of configurations used 
 * in the library ( it covers Devicem, Cloud, 
 * Communication, Authentication configs). 
 * Everything that has to be configured and 
 * configs - stored: passwords, IP, Port, URL, etc.
 */
class CoTConfigBase { };

/* Base class for each device library is capable of working with */
class CoTDeviceBase {
public:
	CoTDeviceBase( const CoTConfigBase& deviceConfig);

public:
	virtual bool init() = 0;

	/* Overload to get the device-specific error handling */
	virtual void errorHandler( const CoTHandlerParam handler ) { };

private:
	const CoTConfigBase& _deviceConfig;
};

class CoTAuthBase { };

class CoTCommunicationBase {
public:
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

