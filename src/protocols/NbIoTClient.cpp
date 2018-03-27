/**
 * @file NbiotClient.cpp
 * @description Abstracted Network interface of an NB-IoT Modem.
 * @author mm1 Technology GmbH
 * @copyright (C) 2017-2018 Deutsche Telekom AG- all rights reserved. 
 * @licence MIT licence
 * 
 * Code pieces based on Arduino WiFiClient and GIMASI TUINO example project(s):
 * Company: http://www.tuino.io/
 * GitHub:  https://github.com/gimasi
 */


#include "DTCoTSetup.h"

#if CONN_TYPE == NB_IOT

//#include "DbgSerialInit.h"

extern "C" {
	// #include "utility/wl_definitions.h"
	// #include "utility/wl_types.h"
	#include "string.h"
	// #include "utility/debug.h"
}

// #include "WiFi.h"
// #include "WiFiClient.h"
// #include "WiFiServer.h"
// #include "utility/server_drv.h"

#include "utility/Regexp.h"
#include "gmx_nbiot.h"
#include "protocols/NbIoTClient.h"
#include "DTCoTSetup.h"
#include "utility/DTCoTDebugOutput.h"


#define MAX_SOCK_NUM  0xFF

uint16_t NbiotClient::_srcport = 1883;




NbiotClient::NbiotClient( const String& ipAddress, Stream& dbgOutputStream /* default = Serial */)
	: _sock( MAX_SOCK_NUM)
	, _dbgOutputStream( dbgOutputStream)
	, _modemInitialized( false)
	, _serverIP( ipAddress)
	, _serial(Serial)
	, _resetPin(10)
{
	//DEBUG_PRINT_INFO("NbiotClient::NbiotClient():");
}

/**
 * @brief Initialise / start modem here.
 */
	NbiotClient::NbiotClient(uint8_t sock, Stream& dbgOutputStream /* default = Serial */)
			:	 _sock(sock)
				, _serial(Serial)
				, _resetPin(10)
				,_dbgOutputStream( dbgOutputStream) {

}

NbiotClient::NbiotClient(const String& serverIP, const unsigned short& serverPort, const String& imsi
						, const String& password, Stream& serial
						, int resetPin, Stream& dbgOutputStream)
	
	: _serverIP(serverIP)
	, _serverPort(serverPort)
	, _imsi(imsi)
	, _password(password)
	, _serial(serial)
	, _resetPin(resetPin)
	, _dbgOutputStream( dbgOutputStream)
	
		
		
{
	//DEBUG_PRINT_INFO("NbiotClient::NbiotClient():");
	//Serial.println("NbiotClient::NbiotClient():");
	//delay(1000);
	
}

NbiotClient::NbiotClient(Stream& dbgOutputStream /* default = Serial */)
	: _dbgOutputStream( dbgOutputStream)
		, _serial(Serial)
		, _resetPin(10)
		
{
	//Serial.println("NbiotClient::NbiotClient():");
}


/**
 * @brief Dummy method which has to be there. Does nothing but return an error if called.
 * @note This function always returns an error, since NBIOT does not support host name resolution. Use IP addresses, instead.
 * @param host Host name
 * @param port Destination port.
 * @returns Returns always error code 0, since NBIOT cannot resolve host names. Use IP addresses, instead.
 */
int NbiotClient::connect(const char* host, uint16_t port) {

	// DEBUG_PRINT_INFO("NbiotClient::connect(const char* host, uint16_t port)");
	/*NOTE Do some stupid stuff to make the compiler happy. :-| */
	host = host;
	port = port;
	/*Error: no host name resolution with NB-IoT*/
	
	if( !_modemInitialized ) {
		_modemInitialized = initNBIoTModem();
		if( !_modemInitialized ) { 
			return 0;
		}
	}
	
	gmxNB_connect(_serverIP, _serverPort);
	_socket = gmxNB_SocketOpen();
	
	
	return 0;
}





/**
 * @brief All UDP packets will be delivered to the remote host which is configured here.
 * @param ip Host IP address.
 * @param port Destination port.
 * @returns 1 if connected successfully, 0 on failure.
 */
int NbiotClient::connect(IPAddress ip, uint16_t port) {
	DEBUG_PRINT_INFO( "NbiotClient::connect( ip=" + String( _serverIP)
		+ ", port=" + String( _serverPort) + ")" );

	
	
	if( !_modemInitialized ) {
		_modemInitialized = initNBIoTModem();
		if( !_modemInitialized ) { 
			return 0;
		}
	}
	
	gmxNB_connect(_serverIP, _serverPort);
  	_socket = gmxNB_SocketOpen();
  

  return 1;
}



/**
 * @brief Bytewise data transmission.
 * @note Will not be implemented (yet?).
 * @param b Byte to be transmitted.
 * @returns Always 0, because no data transmission is executed.
 */
size_t NbiotClient::write(uint8_t b) {
	DEBUG_PRINT_INFO("NbiotClient::write(uint8_t b)");

	if( !_modemInitialized ) {
		_modemInitialized = initNBIoTModem();
		if( !_modemInitialized ) { 
			return 0;
		}
	}

	/* TODO: Implement byte sending */

  return 0;
}



/**
 * @brief Packet-wise data transmission.
 * @param buf Payload buffer to be sent.
 * @param size Number of bytes to be sent.
 * @returns Number of bytes that were sent.
 */
size_t NbiotClient::write(const uint8_t *buf, size_t size) {
	if( !_modemInitialized ) {
		_modemInitialized = initNBIoTModem();
		if( !_modemInitialized ) {
			DEBUG_PRINT( "NbiotClient::write(const uint8_t *buf, size_t size): ERROR: Failed to initialize the modem");
			return 0;
		}
	}

	byte retval;
	
	/*TODO test if socket is already open!*/
	
	retval = gmxNB_TXData((const char*)buf, size);
	
	if(retval == GMXNB_OK)
	{
		return size;
	}
	
	return 0;
}



/**
 * @brief Returns a value > 0 for a received / pending packet.
 * @fixme This implementation only counts characters received from the modem. It should 
 * return the number of bytes pending to be read.
 * @returns 0 for no pending packet, >0 otherwise.
 */
int NbiotClient::available() {
	DEBUG_PRINT_INFO("NbiotClient::available()");
  return gmxNB_Available();
}



/**
 * @brief Byte-wise read.
 * @note Will not be implemented (yet?).
 * @brief Always returns an error.
 */
int NbiotClient::read() {
	DEBUG_PRINT_INFO("NbiotClient::read()");
  /*TODO Implement byte-wise read operation. (not recommended though!)*/
  return -1;
}


int NbiotClient::read(uint8_t* buf, size_t size) {

	DEBUG_PRINT_INFO("NbiotClient::read(uint8_t* buf, size_t size)");

  byte status;
  int _size = size;
  String remoteIp;
  int myUdpPort;

  /*TODO check if socket is active*/
  status = gmxNB_RXData(_serverIP, _serverPort, (byte*)buf, _size);
  
  if( status != GMXNB_OK )
  {
    DEBUG_PRINT_INFO("NbiotClient::read(): Err CoT connection failed.");
    return -1;
  }
  else
  {
    return _size;
  }


#if 0
  // sizeof(size_t) is architecture dependent
  // but we need a 16 bit data type here
  uint16_t _size = size;

  gmxNB_RXData();
  if (!ServerDrv::getDataBuf(_sock, buf, &_size))
      return -1;
  return 0;
#endif /*0*/
}

int NbiotClient::peek() {

	DEBUG_PRINT_INFO("NbiotClient::peek()");

  return -1;
  
#if 0
	  uint8_t b;
	  if (!available())
	    return -1;

	  NbiotClient::getData(_sock, &b, 1);
	  return b;
#endif /*0*/
}



void NbiotClient::flush() {
	DEBUG_PRINT_INFO("NbiotClient::flush()");
  // TODO: a real check to ensure transmission has been completed
}



/**
 * @brief Stops the device.
 * @note Not yet implemented. Restart the system, instead.
 */
void NbiotClient::stop() {
	DEBUG_PRINT_INFO("NbiotClient::stop()");
  if (_sock == MAX_SOCK_NUM)
    return;

  _sock = MAX_SOCK_NUM;
}



uint8_t NbiotClient::connected() {
	DEBUG_PRINT_INFO("NbiotClient::connected()");
	if( !_modemInitialized) {
		return 0;
	}
/*
	if (_sock == MAX_SOCK_NUM) {
		return 0;
	}
*/
	return 1;

  
#if 0
    /*TODO encode connection state like this*/
    
    uint8_t s = status();

    return !(s == LISTEN || s == CLOSED || s == FIN_WAIT_1 ||
    		s == FIN_WAIT_2 || s == TIME_WAIT ||
    		s == SYN_SENT || s== SYN_RCVD ||
    		(s == CLOSE_WAIT));
  }
#endif /*0*/
}



uint8_t NbiotClient::status() {

	DEBUG_PRINT_INFO("NbiotClient::status()");

  if (_sock == MAX_SOCK_NUM) {
    return 0;
  } else {
    return 1;
  }
}



NbiotClient::operator bool() {
	DEBUG_PRINT_INFO("NbiotClient::operator bool()");
  return _sock != MAX_SOCK_NUM;
}



// Private Methods
uint8_t NbiotClient::getFirstSocket()
{
	DEBUG_PRINT_INFO("NbiotClient::getFirstSocket()");
  return 0;
}


bool NbiotClient::initNBIoTModem() {
	// Init NB IoT board
	DEBUG_PRINT_INFO("NbiotClient::initNBIoTModem(): Initializing modem ... ");
	
	byte initStatus = gmxNB_init(
			/*forceReset:*/ false,
			_serverIP,
			_serverPort,
			_serial,
			_resetPin,
			NULL
		);

	if( ( initStatus != NB_NETWORK_JOINED) && ( initStatus != GMXNB_OK) ) {
		DEBUG_PRINT_INFO("");
		DEBUG_PRINT("NbiotClient::initNBIoTModem(): ERROR: Failed to initialize modem");
		return false;
	}
	DEBUG_PRINT("NbiotClient::initNBIoTModem(): Modem initialized");

	// DEBUG_PRINT_INFO("NbiotClient::initNBIoTModem(): Collecting modem IMEI ... " );
	String imeiInfo;
	if( gmxNB_getIMEI( imeiInfo) != GMXNB_OK ) {
		DEBUG_PRINT_INFO("");
		DEBUG_PRINT("NbiotClient::initNBIoTModem(): ERROR: Failed to aquire modem IMEI");
		return false;
	}
	DEBUG_PRINT("NbiotClient::initNBIoTModem(): IMEI:" + imeiInfo);

	if (initStatus != NB_NETWORK_JOINED) {
		/* TODO: check for return code after it is implemented in the driver! */
		DEBUG_PRINT_INFO("NbiotClient::initNBIoTModem(): Configuring for DT network ... " );
		gmxNB_startDT();
		DEBUG_PRINT_INFO("NbiotClient::initNBIoTModem(): Configured for DT network" );
	}

	// DEBUG_PRINT_INFO("NbiotClient::initNBIoTModem(): Aquiring IMSI ..." );

	String testImsi;
	gmxNB_getIMSI(testImsi);
	/* TODO:
	 * 1) check for return code after it is implemented in the driver!
	 * 2) IMSI should also be used for athentication.
	 */
	DEBUG_PRINT("NbiotClient::initNBIoTModem(): IMSI: " + testImsi);

	DEBUG_PRINT("NbiotClient::initNBIoTModem(): Attempting to join the network ..." );
	unsigned long netJoinRetryCounter = 0;
	for( ; netJoinRetryCounter < MAX_NETWORK_JOIN_RETRIES; netJoinRetryCounter++ ) {

		if( gmxNB_isNetworkJoined() == NB_NETWORK_JOINED) {
			break;
		}

		DTCoTNBIoTHardware_led(GMXNB_LED_ON, 2);
		delay(500);
		DTCoTNBIoTHardware_led(GMXNB_LED_OFF, 2);
		DEBUG_PRINT(".");

		delay(2500);
	}
	DEBUG_PRINT("\n");

	if( netJoinRetryCounter >= MAX_NETWORK_JOIN_RETRIES) {
		DEBUG_PRINT("NbiotClient::initNBIoTModem(): Failed to join network");
		return false;
	}
	
	DTCoTNBIoTHardware_led(GMXNB_LED_ON, 2);
	DEBUG_PRINT("NbiotClient::initNBIoTModem(): Successfuly joined the network");

	_modemInitialized = true;
	return true;
}


int NbiotClient::init() {
	
	/*
	
	if( !_modemInitialized ) {
		_modemInitialized = initNBIoTModem();
		if( !_modemInitialized ) {
			DEBUG_PRINT_INFO( "NbiotClient::init(): ERROR: Failed to initialize the modem");
			return 0;
		}
	}
	
	*/
	
	
}

#endif
