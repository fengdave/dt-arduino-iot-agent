/**
 * @file NbiotClient.cpp
 * @description Network interface of an NB-IoT Modem.
 * @author akrause
 * @copyright (C) 2017 mm1 Technology GmbH - all rights reserved.
 * @licence MIT licence
 * 
 * Find out more about mm1 Technology:
 * Company: http://mm1-technology.de/
 * GitHub:  https://github.com/mm1technology/
 * 
 * Code pieces based on Arduino WiFiClient and GIMASI TUINO example project(s):
 * Company: http://www.tuino.io/
 * GitHub:  https://github.com/gimasi
 */

 
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

#include "Regexp.h"
#include "gmx_nbiot.h"
#include "NbiotClient.h"


#define MAX_SOCK_NUM  0xFF

uint16_t NbiotClient::_srcport = 1883;




NbiotClient::NbiotClient( const String& ipAddress, Stream& dbgOutputStream)
	: _sock( MAX_SOCK_NUM)
	, _dbgOutputStream( dbgOutputStream)
	, _modemInitialized( false)
	, _ipAddress( ipAddress)
{
	//_dbgOutputStream.println("NbiotClient::NbiotClient():");
}

/**
 * @brief Initialise / start modem here.
 */
	NbiotClient::NbiotClient(uint8_t sock) : _sock(sock) {
}

NbiotClient::NbiotClient(const String& serverIP, const String& serverPort, const String& imsi, const String& password)  
	
	: _serverIP(serverIP)
	, _serverPort(serverPort)
	, _imsi(imsi)
	, _password(password)
	, _dbgOutputStream(Serial)
	//,_dbgOutputStream( dbgOutputStream)
	
		
		
{
	//_dbgOutputStream.println("NbiotClient::NbiotClient():");
	//Serial.println("NbiotClient::NbiotClient():");
	//delay(1000);
	
}

NbiotClient::NbiotClient()  
		
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

	_dbgOutputStream.println("NbiotClient::connect(const char* host, uint16_t port)");
  /*NOTE Do some stupid stuff to make the compiler happy. :-| */
  host = host;
  port = port;
	/*Error: no host name resolution with NB-IoT*/

	return 0;
}





/**
 * @brief All UDP packets will be delivered to the remote host which is configured here.
 * @param ip Host IP address.
 * @param port Destination port.
 * @returns 1 if connected successfully, 0 on failure.
 */
int NbiotClient::connect( IPAddress ip, uint16_t port) {
	_dbgOutputStream.println( "NbiotClient::connect( ip=" + String( ip) 
		+ ", port=" + String( port) + ")" );

  // String ipAddrStr = ip().toString();
  _ipaddrStr = String( ip);
  _dstport = port;
  
  gmxNB_connect(_ipaddrStr, _dstport);
  gmxNB_SocketOpen();

	if( !_modemInitialized ) {
		_modemInitialized = initNBIoTModem();
		if( !_modemInitialized ) { 
			return 0;
		}
	}

  return 1;
}



/**
 * @brief Bytewise data transmission.
 * @note Will not be implemented (yet?).
 * @param b Byte to be transmitted.
 * @returns Always 0, because no data transmission is executed.
 */
size_t NbiotClient::write(uint8_t b) {
	_dbgOutputStream.println("NbiotClient::write(uint8_t b)");

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
			_dbgOutputStream.println( "NbiotClient::write(const uint8_t *buf, size_t size): ERROR: Failed to initialize the modem");
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
	_dbgOutputStream.println("NbiotClient::available()");
  return gmxNB_Available();
}



/**
 * @brief Byte-wise read.
 * @note Will not be implemented (yet?).
 * @brief Always returns an error.
 */
int NbiotClient::read() {
	_dbgOutputStream.println("NbiotClient::read()");
  /*TODO Implement byte-wise read operation. (not recommended though!)*/
  return -1;
}


int NbiotClient::read(uint8_t* buf, size_t size) {

	_dbgOutputStream.println("NbiotClient::read(uint8_t* buf, size_t size)");

  byte status;
  int _size = size;
  String remoteIp;
  int myUdpPort;

  /*TODO check if socket is active*/
  status = gmxNB_RXData(remoteIp, myUdpPort, (byte*)buf, _size);
  
  if( status != GMXNB_OK )
  {
    _dbgOutputStream.println("Err CoT connection failed.");
    return -1;
  }
  else
  {
    return 0;
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

	_dbgOutputStream.println("NbiotClient::peek()");

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
	_dbgOutputStream.println("NbiotClient::flush()");
  // TODO: a real check to ensure transmission has been completed
}



/**
 * @brief Stops the device.
 * @note Not yet implemented. Restart the system, instead.
 */
void NbiotClient::stop() {
	_dbgOutputStream.println("NbiotClient::stop()");
  if (_sock == MAX_SOCK_NUM)
    return;

  _sock = MAX_SOCK_NUM;
}



uint8_t NbiotClient::connected() {
	_dbgOutputStream.println("NbiotClient::connected()");
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

	_dbgOutputStream.println("NbiotClient::status()");

  if (_sock == MAX_SOCK_NUM) {
    return 0;
  } else {
    return 1;
  }
}



NbiotClient::operator bool() {
	_dbgOutputStream.println("NbiotClient::operator bool()");
  return _sock != MAX_SOCK_NUM;
}



// Private Methods
uint8_t NbiotClient::getFirstSocket()
{
	_dbgOutputStream.println("NbiotClient::getFirstSocket()");
  return 0;
}


bool NbiotClient::initNBIoTModem() {
	// Init NB IoT board
	_dbgOutputStream.println("NbiotClient::initNBIoTModem(): Initialyzing modem ... ");
	byte initStatus = gmxNB_init( /*forceReset:*/ false
		, String( _ipAddress)
		, NbiotClient::_srcport
		, NULL );

	if( ( initStatus != NB_NETWORK_JOINED) && ( initStatus != GMXNB_OK) ) {
		_dbgOutputStream.println( "");
		_dbgOutputStream.println( "NbiotClient::initNBIoTModem(): ERROR: Failed to initialize modem");
		return false;
	}
	_dbgOutputStream.println("NbiotClient::initNBIoTModem(): Modem initialized");

	_dbgOutputStream.println("NbiotClient::initNBIoTModem(): Collecting modem IMEI ... " );
	String imeiInfo;
	if( gmxNB_getIMEI( imeiInfo) != GMXNB_OK ) {
		_dbgOutputStream.println( "");
		_dbgOutputStream.println( "NbiotClient::initNBIoTModem(): ERROR: Failed to aquire modem IMEI");
		return false;
	}
	_dbgOutputStream.println( "NbiotClient::initNBIoTModem(): IMEI:" + imeiInfo);

	if (initStatus != NB_NETWORK_JOINED) {
		/* TODO: check for return code after it is implemented in the driver! */
		_dbgOutputStream.println("NbiotClient::initNBIoTModem(): Connecting to DT network ... " );
		gmxNB_startDT();
		_dbgOutputStream.println("NbiotClient::initNBIoTModem(): Connected to DT network" );
	}

	_dbgOutputStream.println("NbiotClient::initNBIoTModem(): Attempting to join the network ..." );
	unsigned long netJoinRetryCounter = 0;
	const unsigned long MAX_NETWORK_JOIN_RETRIES = 100;
	for( ; netJoinRetryCounter < MAX_NETWORK_JOIN_RETRIES
		; ++netJoinRetryCounter ) {

		if( gmxNB_isNetworkJoined() == NB_NETWORK_JOINED) {
			break;
		}

		gmxNB_Led2(GMXNB_LED_ON);
		delay(500);
		gmxNB_Led2(GMXNB_LED_OFF);
		_dbgOutputStream.print(".");

		delay(2500);
	}

	if( netJoinRetryCounter >= MAX_NETWORK_JOIN_RETRIES) {
		_dbgOutputStream.println( "Fail");
		return false;
	}
	
	gmxNB_Led2(GMXNB_LED_ON);
	_dbgOutputStream.println( 
		"NbiotClient::initNBIoTModem(): Successfuly joined the network");

	_dbgOutputStream.println(
		"NbiotClient::initNBIoTModem(): Aquiring IMSI ..." );

	String testImsi;
	gmxNB_getIMSI(testImsi); /* TODO: check for return code after it is implemented in the driver! */
	_dbgOutputStream.print(
		"NbiotClient::initNBIoTModem(): IMSI: " + testImsi);

	_modemInitialized = true;
	
	return true;
}

