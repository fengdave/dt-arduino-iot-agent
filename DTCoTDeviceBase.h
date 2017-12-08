#ifndef DeviceBase_h_
#define DeviceBase_h_

#include <Client.h>

namespace DTCoT 
{
	/* Base class for each device library is capable of working with */
	class CoTDeviceBase {
	public:
		CoTDeviceBase( const CoTConfigBase& deviceConfig);

	public:
		virtual bool init() = 0;

		/* Overload to get the device-specific error handling */
		//virtual void errorHandler( const CoTHandlerParam handler ) { };

		virtual Client * getClient() const = 0; // Every device provides a client
		//@TODO - Via an Arduino Client interface? Or we abstract this further - can do later https://www.arduino.cc/en/Reference/ClientConstructor


	protected:
		const CoTConfigBase& _deviceConfig;
	};
}

#endif 
