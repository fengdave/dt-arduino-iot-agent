/**
 * @file DTCotDebugOutput.cpp
 * @description Central debug output file
 * @author mm1 Technology GmbH
 * @copyright (C) 2017-2018 Deutsche Telekom AG- all rights reserved. 
 * @licence MIT licence
 */
#include <stdarg.h>

#include "DTCoTDebugOutput.h"

#define PRINTF_BUF 256 // define the tmp buffer size (change if desired)
void debug_printf(String format, ...)
{
	char bufIn[PRINTF_BUF];
	char buf[PRINTF_BUF];
	va_list ap;
	format.toCharArray(bufIn, PRINTF_BUF);
    va_start(ap, bufIn);
    vsnprintf(buf, sizeof(buf), bufIn, ap);
	Serial.println(buf);
   /* for(char *p = &buf[0]; *p; p++) // emulate cooked mode for newlines
    {
            if(*p == '\n')
                    write('\r');
            write(*p);
    }*/
    va_end(ap);
}