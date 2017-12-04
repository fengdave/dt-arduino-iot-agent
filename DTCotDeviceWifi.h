#ifndef CoTDeviceWiFi_h_
#define CoTDeviceWiFi_h_

#include <String.h>

#include <DTCoTDeviceBase.h>

namespace DTCoT {

class DeviceWiFi : public DeviceBase {
	
public:
	void connect(char * ssid, char * password);
};

}

#endif