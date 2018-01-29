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
 * Debug levels.
 * 0 - never print anything
 * 1 - only print critical logs
 * 2 - print debug logs also
 * 3 - print informational logs also
 */
#define DEBUG_LEVEL 2

#if DEBUG_LEVEL == 0
	#define DEBUG_PRINT(x) //
	#define DEBUG_PRINT_INFO(x) //
#elif DEBUG_LEVEL > 0 // 
	#define DEBUG_PRINT(x) Serial.println(x)
	#define DEBUG_PRINT_INFO(x) //
#elif DEBUG_LEVEL > 1 // 
	#define DEBUG_PRINT(x) Serial.println(x)
	#define DEBUG_PRINT_INFO(x) Serial.println(x)
#endif

#endif /* DEBUG_PRINT */

#endif