/**
 * @file DTCoTNBIoTHardware.h
 * @description Abstraction of hardware specifics of an NBIoT interface
 * 
 * @author Andreas Krause
 * @copyright (C) 2018 mm1 Technology GmbH - all rights reserved. 
 * @licence MIT licence
 * 
 * Find out more about mm1 Technology:
 * Company: http://mm1-technology.de/
 * GitHub:  https://github.com/mm1technology/
 */
 
 #ifndef _DTCoTNBIoTHardware_h
 #define _DTCoTNBIoTHardware_h

#define GMXNB_KO                      -1 

#define GMXNB_OK                      0 

#define GMX_UART_SPEED                9600

#define GMX_BOOT_DELAY                4000

#define GMXNB_NOT_PRESENT             10
#define GMXNB_NO_SERIAL               20

#define GMXNB_AT_ERROR                30
#define GMXNB_AT_GENERIC_ERROR        99
#define GMXNB_AT_TIMEOUT              55

#define GMXNB_LED_ON                  1
#define GMXNB_LED_OFF                 0

#define GMX_UART_INTERFACE            1
#define GMX_SPI_INTERFACE             2

#define GMX_UART_TIMEOUT              10000

/**
 * @param callback callback for when data is available from the NBIoT buffer
 */
int DTCoTNBIoTHardware_init(void( *callback)()); 
void DTCoTNBIoTHardware_reset();

/**
 * Change LED state on the hardare
 * @param led_state 1 on 0 off
 * @param ledNumber 1,2, or 3. If it is out of bounds, the LED number will wrap
 */
void DTCoTNBIoTHardware_led(char led_state, char ledNumber);

#endif
