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

#ifndef DeviceBase_h_
#define DeviceBase_h_

#include <Client.h>

namespace DTCoT 
{
	/**
	 * Base class for each device.
	 * A device is a specific piece of hardware (i.e, Tuino, HUZZAH).
	 * This class abstracts away the hardware details of the platform. It should not be used directly.*/
	class CoTDeviceBase {
	public:
		/**
		 * Constructor with config for a device.
		 * @param deviceConfig The config file class should match the physical device's class.
		 */
		CoTDeviceBase( const CoTConfigBase& deviceConfig);

	public:
		/**
		 * Begin using device
		 */
		virtual bool init() = 0;

		/**
		 * Error occurred.
		 * Overload to get the device-specific error handling
		 */
		//virtual void errorHandler( const CoTHandlerParam handler ) { };

		/**
		 * Get client for this device.
		 * Every Arduino platform should have a Client implementation. This is a standard communication channel
		 * such as WiFi or Ethernet, which we can use for communication with our CoT server.
		 *
		 * @TODO this may be abstracted further in the future - https://www.arduino.cc/en/Reference/ClientConstructor
		 */
		virtual Client * getClient() const = 0;


	protected:
		const CoTConfigBase& _deviceConfig;
	};
}

#endif 
