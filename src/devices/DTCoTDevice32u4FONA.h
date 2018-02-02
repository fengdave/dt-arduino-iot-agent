/**
 * @file DTCoTDevice32u4FONA.h
 * @description Basic setup and protocol to interact 
 * with the Deutsche Telekom Cloud of things MQTT-SN connector.
 * @author mm1 Technology GmbH
 * @copyright (C) 2018 Deutsche Telekom AG- all rights reserved. 
 * @licence MIT licence
 */

#ifndef DT_COT_DEVICE_ADAFRUIT_FONA_HEADER_FILE
#define DT_COT_DEVICE_ADAFRUIT_FONA_HEADER_FILE

#include "DTCoT.h"

namespace DTCoT {
 
 
/**
 * Config class for 32U4 FONA board
 */
class CoTConfigDevice32u4FONA: public CoTConfigBase {
public:
	CoTConfigDevice32u4FONA( /* TODO: Any FONA-specific params here */);
};

/**
 * Device class for 32U4 FONA board
 */
class CoTDevice32u4FONA: public CoTDeviceGPRS {
public:
	CoTDevice32u4FONA( const CoTConfigDevice32u4FONA& cfg );
};

} /* namespace DTCoT */

#endif /* DT_COT_DEVICE_ADAFRUIT_FONA_HEADER_FILE */
