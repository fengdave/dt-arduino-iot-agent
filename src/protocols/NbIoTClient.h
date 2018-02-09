/**
 * @file NbIoTClient.h
 * @description Header file for Abstracted Network interface of an NB-IoT Modem. 
 * @author mm1 Technology GmbH
 * @copyright (C) 2017-2018 Deutsche Telekom AG- all rights reserved. 
 * @licence MIT licence
 * 
 * Code pieces based on Arduino WiFiClient and GIMASI TUINO example project(s):
 * Company: http://www.tuino.io/
 * GitHub:  https://github.com/gimasi
 */

#ifndef _nbiotclient_h
#define _nbiotclient_h

#include "DTCoTSetup.h"

#if CONN_TYPE == NB_IOT

#include "Arduino.h"	
#include "Print.h"
#include "Client.h"
#include "IPAddress.h"

/**
 * Arduino Client interface for accessing NbIOT networks.
 */
class NbiotClient : public Client {

public:
	/**
	 * Constructor
	 * @param ipAddress connect to IP address
	 * @param dbgOutputStream where to write debug info. Default to Serial.
	 */
  explicit NbiotClient( const String& ipAddress
	, Stream& dbgOutputStream = Serial
  );
	
/**
 * Constructor
 * @param ipAddress connect to socket ID
 * @param dbgOutputStream where to write debug info. Default to Serial.
 */
  explicit NbiotClient( uint8_t sock,  Stream& dbgOutputStream = Serial);
  
  explicit NbiotClient( Stream& dbgOutputStream = Serial);
  
   /**
    * Constructor
    * @param serverIP IP address of the NBIoT server
    * @param serverPort port of the NBIoT server
    * @param imsi IMSI UID of this device
    * @param password matching password fo the connection
  ` * @param serial the serial port with which to communicate with the NBIoT hardware.
    * @param the reset pin which the NBIoT hardware is connected to. The actual reset procedure will depend on the hardware.
    * @param dbgOutputStream where to write debug info. Default to Serial.
    */
  explicit NbiotClient(const String& serverIP
	, const unsigned short& serverPort
	, const String& imsi
	, const String& password
	, Stream& serial
	, int resetPin 
	, Stream& dbgOutputStream = Serial
	);

  /**
   * Get the status of this connection. See standard Arduino Client class docs.
   */
  uint8_t status();
  
  /**
   * Connect to address
   * @param ip ip address
   * @param port port
   */
  virtual int connect( IPAddress ip, uint16_t port);
  
 /**
  * Connect to address
  * @param host hostname
  * @param port port
  */
  virtual int connect( const char *host, uint16_t port);
  
 /**
  * Write single byte
  * @param byte to write
  * @return 1 on success
  */
  virtual size_t write( uint8_t);
  
 /**
  * Write bytes
  * @param bytes to write
  * @param size num of bytes to write
  * @return 1 on success
  */
  virtual size_t write( const uint8_t *buf, size_t size);
  
 /**
  * Bytes available
  * @return num of bytes available to read
  */
  virtual int available();
  
 /**
  * Read a byte (NOT IMPLEMETED)
  * @return byte
  */
  virtual int read();
  
 /**
  * Read bytes
  * @param buffer to read to
  * @param size max num of bytes to read
  * @return num of bytes read
  */
  virtual int read( uint8_t *buf, size_t size);
  
  virtual int peek();
  
  /**
   * Send all data
   */
  virtual void flush();
  
  /**
   * End connection
   */
  virtual void stop();
  
  /**
   * Is connected
   * @return 1 if connected
   */
  virtual uint8_t connected();
  
  /**
   * Operator true if sockets available
  */
  virtual operator bool();
  
  /**
   * Setup the NBIoTClient interface
   */
  int init();

  using Print::write;

private:
	static uint16_t _srcport;
	uint8_t _sock;   //not used
	uint16_t  _socket;
	String _ipaddrStr;
	int _dstport;
	String _ipAddress;
	unsigned short _serverPort;
	String _serverIP;
	String _imsi;
	String _password;
	Stream& _serial;
	int _resetPin;
  
  

private:
	uint8_t getFirstSocket();
	bool initNBIoTModem();

private:
	Stream& _dbgOutputStream;
	bool _modemInitialized;
};

#endif

#endif /*_nbiotclient_h*/
