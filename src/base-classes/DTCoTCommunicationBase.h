#ifndef CommunicationBase_h_
#define CommunicationBase_h_


namespace DTCoT {

	class CoTAuthBase;
	class CoTConfigBase;
	class CoTDeviceBase;

	/**
	 * Communications base class.
	 * This is an abstract channel of communiction: it requires a device, and
	 * any authentication parameters, such as  passwords or credentials for the CoT service.
	 */
	class CoTCommunicationBase {
	public:
		/**
		 * Constructor for communication classes
		 * @param config configuration for this communications channel
		 * @param authentication auth details for this communication channel
		 */
		CoTCommunicationBase( const CoTDeviceBase& device
			, const CoTConfigBase& config
			, const CoTAuthBase& authentication ); 

	protected:
		const CoTConfigBase& _config;
		const CoTDeviceBase& _device;

	private:
		const CoTAuthBase& _authentication;
	}; 

}




#endif
