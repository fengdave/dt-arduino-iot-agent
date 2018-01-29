/**
 * @file DTCoTDeviceNBIoT.h
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

#ifndef DT_COT_DEVICE_NBIOT_HEADER_FILE
#define DT_COT_DEVICE_NBIOT_HEADER_FILE

#include "DTCOTSetup.h"

#if CONN_TYPE == NB_IOT

#include "DTCoTPrivate.h"
#include "DTCoTExtensionIface.h"
#include "base-classes/DTCoTDeviceBase.h"

#include "protocols/NbIoTClient.h"

namespace DTCoT {

   /**
    * Config class for NBIoT capable device.
    */
class CoTConfigDeviceNBIoT: public CoTConfigDevice {
public:
   /**
    * Constructor
    * @param serverIP IP address of the NBIoT server
    * @param serverPort port of the NBIoT server
    * @param imsi IMSI UID of this device
    * @param cot_pwd matching password fo the connection
    */
	CoTConfigDeviceNBIoT( const char* serverIP, const unsigned short serverPort, const char* imsi, const char* cot_pwd, Stream& serial, int resetPin  );
	
	public:
	const char* getServerIP();
	const unsigned short getServerPort();
	const char* getIMSI();
	const char* getPassword();
	Stream & getSerial();
	int getResetPin();

private:
	const char* _serverIP;
	const unsigned short _serverPort;
	const char* _imsi;
	const char* _password;
	Stream& _serial;
	int _resetPin;
};

/**
 * Device class for NBIoT capable device.
 */
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
