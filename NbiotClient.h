/**
 * @file NbiotClient.h
 * @description Network interface of an NB-IoT Modem.
 * @author akrause
 * @copyright (C) 2017 mm1 Technology GmbH - all rights reserved.
 * @licence MIT licence
 * 
 * Find out more about mm1 Technology:
 * Company: http://mm1-technology.de/
 * GitHub:  https://github.com/mm1technology/
 * 
 * Code pieces based on Arduino WiFiClient.
 */

#ifndef _nbiotclient_h
#define _nbiotclient_h

#include "Arduino.h"	
#include "Print.h"
#include "Client.h"
#include "IPAddress.h"

class NbiotClient : public Client {

public:
  explicit NbiotClient( const String& ipAddress
	, Stream& dbgOutputStream = Serial
  );
	
  explicit NbiotClient( uint8_t sock);
  
  explicit NbiotClient(const String& serverIP
	, const String& serverPort
	, const String& imsi
	, const String& password);

  uint8_t status();
  virtual int connect( IPAddress ip, uint16_t port);
  virtual int connect( const char *host, uint16_t port);
  virtual size_t write( uint8_t);
  virtual size_t write( const uint8_t *buf, size_t size);
  virtual int available();
  virtual int read();
  virtual int read( uint8_t *buf, size_t size);
  virtual int peek();
  virtual void flush();
  virtual void stop();
  virtual uint8_t connected();
  virtual operator bool();

  // friend class NbiotServer;

  using Print::write;

private:
  static uint16_t _srcport;
  uint8_t _sock;   //not used
  uint16_t  _socket;
  String _ipaddrStr;
  int _dstport;
  String _ipAddress;
  String _serverPort;
  String _serverIP;
  String _imsi;
  String _password;
  
  

private:
	uint8_t getFirstSocket();
	bool initNBIoTModem();

private:
	Stream& _dbgOutputStream;
	bool _modemInitialized;
};

#endif /*_nbiotclient_h*/
