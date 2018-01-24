#ifndef DT_COT_PRIVATE_HEADER_FILE 
#define DT_COT_PRIVATE_HEADER_FILE 

#include "base-classes/DTCoTConfigBase.h"
#include "base-classes/DTCoTDeviceBase.h"
#include "base-classes/DTCoTCommunicationBase.h"

/* DTCoT Private abstraction interface */

namespace DTCoT 
{

/* Handler and payload-related infrastructure */
typedef void* CoTHandlerParam;
typedef void (*CoTHandler)(CoTHandlerParam);


class CoTAuthBase { };


} /* namespace DTCoT */

#endif /* DT_COT_PRIVATE_HEADER_FILE */

