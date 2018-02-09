/**
 * @file gmx_nbiot.h
 * @description Header file for AT command based Driver für NB-IoT modules
 * @author mm1 Technology GmbH
 * @copyright (C) 2017-2018 Deutsche Telekom AG- all rights reserved. 
 * @licence MIT licence
 * Based on the GIMASI Drivers Version 1.1 from July 27, 2017 from https://github.com/gimasi/GMX-NBIOT
 */
 

#include "DTCoTSetup.h"

#if CONN_TYPE == NB_IOT


#ifndef _GMX_NBIOT_H
#define _GMX_NBIOT_H

#include <Arduino.h>

#include "DTCoTNBIoTHardware.h"


#define NB_NETWORK_JOINED             1
#define NB_NETWORK_NOT_JOINED         0



/*
 * GMX-LR1 Init function
 *  the only parameter is the function for the RxData callback
 */
 
byte gmxNB_init(bool forceReset, String ipAddress, int udpPort, Stream & serial, int resetPin, void( *callback)());
byte gmxNB_connect(String ipAddress, int udpPort);
byte gmxNB_getVersion(String& version);
byte gmxNB_getIMEI(String& imei);

byte gmxNB_getIMSI(String& imsi);
byte gmxNB_radioON(String& param);
byte gmxNB_radioOFF(String& param);
byte gmxNB_setAPN(String APN);
byte gmxNB_isNetworkJoined(void);
byte gmxNB_ping(String hostIp);
byte gmxNB_getCSQ(String& csq);


void gmxNB_startDT();


// TX & RX Data
int gmxNB_SocketOpen(void);
byte gmxNB_SocketClose(int sock);
byte gmxNB_SocketClose(void);
int gmxNB_Available(void);
byte gmxNB_TXData(const char *binaryData, int len);
byte gmxNB_RXData(String &remoteIp, int udpPortNr, byte *binaryData, int &len);

/*data conversion binary <-> hex */
String AtResponseTokenize(String atResponse, String delimiter, int &indexStart);
String gmxNB_BinaryToHex(const char *binaryData, int binaryLen );
byte gmxNB_HexToBinary(String hexStr, byte *binaryData);

void gmxNB_Reset(void);


#endif

#endif /*_GMX_NBIOT_H*/

