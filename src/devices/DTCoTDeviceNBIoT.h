#ifndef DT_COT_DEVICE_NBIOT_HEADER_FILE
#define DT_COT_DEVICE_NBIOT_HEADER_FILE

#include "DTCOTSetup.h"

#if CONN_TYPE == NB_IOT

#include "DTCoTPrivate.h"
#include "DTCoTExtensionIface.h"
#include "base-classes/DTCoTDeviceBase.h"

#include "protocols/NbIoTClient.h"

namespace DTCoT {

class CoTConfigDeviceNBIoT: public CoTConfigDevice {
public:
	CoTConfigDeviceNBIoT( const char* serverIP, const unsigned short serverPort, const char* imsi, const char* cot_pwd  );
	
	public:
	const char* getServerIP();
	const unsigned short getServerPort();
	const char* getIMSI();
	const char* getPassword();

private:
	const char* _serverIP;
	const unsigned short _serverPort;
	const char* _imsi;
	const char* _password;
};


class CoTDeviceNBIoT : public CoTDeviceBase {
public:
	CoTDeviceNBIoT(  CoTConfigDeviceNBIoT& nbiotDeviceConfig);
	bool init();


	Client* getClient() const;

private:
	NbiotClient _nbiotClient;
};

} /* namespace DT_COT_DEVICE_NBIOT_HEADER_FILE */

#endif

#endif /* DT_COT_DEVICE_NBIOT_HEADER_FILE */
