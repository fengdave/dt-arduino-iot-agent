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

	protected:
		const CoTConfigBase& _config;
		const CoTDeviceBase& _device;

	private:
		const CoTAuthBase& _authentication;
	}; 

}




#endif
