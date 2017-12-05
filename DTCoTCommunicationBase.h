#ifndef CommunicationBase_h_
#define CommunicationBase_h_


namespace DTCoT {

	class DeviceBase;

	class CommunicationBase {
	
	public:
		CommunicationBase(DeviceBase & device)
			: device(device)
		{

		}


	private:
		DeviceBase & device; // the Communication class always has a device to communicate over
	};

}

#endif
