/**
 * @file DTCoTDebugOutput.h
 * @description Global debug defines. Change these to change the debug logging target.
 * @author Andreas Krause
 * @copyright (C) 2018 mm1 Technology GmbH - all rights reserved. 
 * @licence MIT licence
 * 
 * Find out more about mm1 Technology:
 * Company: http://mm1-technology.de/
 * GitHub:  https://github.com/mm1technology/
 */

#ifndef DEBUG_PRINT_h_
#define DEBUG_PRINT_h_

#ifndef DEBUG_PRINT

/**
 * Always print this.
 */
#define DEBUG_PRINT(x) Serial.println(x)


/**
 * Informational level debug info. Not critical - only informs the user what is going on.
 */
#define DEBUG_PRINT_INFO(x) Serial.println(x)
#endif /* DEBUG_PRINT */

#endif