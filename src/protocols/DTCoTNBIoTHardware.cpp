#include "DTCoTNBIoTHardware.h"

#include "utility/DTCoTDebugOutput.h"

// Takes the board-specific pinouts and defines, so we know which board we are compiling for
#include <Arduino.h>

/*
 Notes for adding further hardware implementations.
 The parent GMX-NBIoT library is classless C++, so we won't use class heirarchies. Add hardware variants here.
 Put your hardware variant within an ifdef block for that specific hardware type (ie Tuino, other 3rd party board).
 Fill in the required functions, with correct pins, init sequence, and reset procedure for the hardware.
 
 DTCoTNBIoTHardware_init takes a callback as a parameter. This should be called whenever there is new data in the
 NBIoT buffer. This interrupt will be hardware dependent.
 
 @todo move this to the DTCotDevice class, if the gmx_nbiot or equivalent is brought into the DTCoT class hierarchy.
*/

#ifdef TUINO_VARIANT

void(*_NBRing)();

// Register interrupt. Not every board supports every sort of interrupt.
ISR(PCINT1_vect) {
  if (digitalRead(GMX_INT) == 0) {
    if (_NBRing)
      _NBRing();
  }
}





int DTCoTNBIoTHardware_init(void( *callback)()) {
	byte init_status = GMXNB_KO;
	
	pinMode(GMX_GPIO1, OUTPUT);
	pinMode(GMX_GPIO2, OUTPUT);
	pinMode(GMX_GPIO3, OUTPUT);
	digitalWrite(GMX_GPIO1, LOW);
	digitalWrite(GMX_GPIO2, LOW);
	digitalWrite(GMX_GPIO3, LOW);
	
    if (Serial1) {
		DTCoTNBIoTHardware_reset();
		Serial1.begin(GMX_UART_SPEED);
		DEBUG_PRINT_INFO("GMX Serial Interface");
		init_status = GMXNB_OK;
		// _gmxNB_AtCommTest(response);
	}


  /*FIXME GMX_INT doesn't do anything at all. Can we configure the BC95 to do otherwise?*/
  // Setup Interrupt PIN for Rx
  *digitalPinToPCICR(GMX_INT) |= (1 << digitalPinToPCICRbit(GMX_INT));
  *digitalPinToPCMSK(GMX_INT) |= (1 << digitalPinToPCMSKbit(GMX_INT));

  // set RX callback
  _NBRing = callback;

  // delay to wait BootUp of GMX-LR
  delay(GMX_BOOT_DELAY);
  
  return init_status;
}

void DTCoTNBIoTHardware_reset() {
	pinMode(GMX_RESET, OUTPUT);
	// Reset
	digitalWrite(GMX_RESET, HIGH);
	delay(100);
	digitalWrite(GMX_RESET, LOW);
	delay(100);
	delay(100);
	digitalWrite(GMX_RESET, HIGH);
}

void DTCoTNBIoTHardware_led(char led_state, char ledNumber) {
	int pin = GMX_GPIO1;
	switch((ledNumber+1)%3) {
		case 0: pin = GMX_GPIO1; break;
		case 1: pin = GMX_GPIO2; break;
		case 2: pin = GMX_GPIO3; break;
	}

	 digitalWrite(pin, led_state);
}





#endif

