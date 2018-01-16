#ifndef DT_COT_DEVICE_NBIOT_HEADER_FILE
#define DT_COT_DEVICE_NBIOT_HEADER_FILE

#include "DTCoTPrivate.h"
#include "DTCoTExtensionIface.h"
#include "DTCoTDeviceBase.h"

#include "NbiotClient.h"

namespace DTCoT {

class CoTConfigDeviceNBIoT: public CoTConfigDevice {
public:
	CoTConfigDeviceNBIoT( const char* serverIP, const char* serverPort, const char* imsi, const char* cot_pwd  );
	
	public:
	const char* getServerIP();
	const char* getServerPort();
	const char* getIMSI();
	const char* getPassword();

private:
	const char* _serverIP;
	const char* _serverPort;
	const char* _imsi;
	const char* _password;
};


class CoTDeviceNBIoT : public CoTDeviceBase {
public:
	CoTDeviceNBIoT( const CoTConfigDeviceNBIoT& nbiotDeviceConfig);
	bool init();

	Client* getClient() const;

private:
	NbiotClient _nbiotClient;
};

} /* namespace DT_COT_DEVICE_NBIOT_HEADER_FILE */

#endif /* DT_COT_DEVICE_NBIOT_HEADER_FILE */
