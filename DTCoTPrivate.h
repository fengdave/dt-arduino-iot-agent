#ifndef DT_COT_PRIVATE_HEADER_FILE 
#define DT_COT_PRIVATE_HEADER_FILE 

#include "DTCoTConfigBase.h"
#include "DTCoTDeviceBase.h"
#include "DTCoTCommunicationBase.h"

/* DTCoT Private abstraction interface */

namespace DTCoT 
{

/* Handler and payload-related infrastructure */
typedef void* CoTHandlerParam;
typedef void (*CoTHandler)(CoTHandlerParam);


class CoTAuthBase { };


} /* namespace DTCoT */

#endif /* DT_COT_PRIVATE_HEADER_FILE */

