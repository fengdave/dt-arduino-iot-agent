#ifndef CommunicationBase_h_
#define CommunicationBase_h_


namespace DTCoT {

	class CoTAuthBase;
	class CoTConfigBase;
	class CoTDeviceBase;


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

}




#endif
