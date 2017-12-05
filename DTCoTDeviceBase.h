#ifndef DeviceBase_h_
#define DeviceBase_h_

#include <Client.h>

namespace DTCoT 
{

	class DeviceBase {
		public:
			virtual Client * getClient();
			//@TODO - Via an Arduino Client interface? Or we abstract this further - can do later https://www.arduino.cc/en/Reference/ClientConstructor
	};

}

#endif 
