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

void DTCoTNBIoTHardware_reset(int resetPin);

void(*_NBRing)();

// Register interrupt. Not every board supports every sort of interrupt.
ISR(PCINT1_vect) {
  if (digitalRead(GMX_INT) == 0) {
    if (_NBRing)
      _NBRing();
  }
}





int DTCoTNBIoTHardware_init(Stream & serial, int resetPin, void( *callback)()) {
	byte init_status = GMXNB_KO;
	
	pinMode(GMX_GPIO1, OUTPUT);
	pinMode(GMX_GPIO2, OUTPUT);
	pinMode(GMX_GPIO3, OUTPUT);
	digitalWrite(GMX_GPIO1, LOW);
	digitalWrite(GMX_GPIO2, LOW);
	digitalWrite(GMX_GPIO3, LOW);
	
	DTCoTNBIoTHardware_reset(resetPin);
	
	HardwareSerial * hwSerial = static_cast<HardwareSerial*>(&serial);
	
	hwSerial->begin(GMX_UART_SPEED);
	DEBUG_PRINT_INFO("GMX Serial Interface");
	init_status = GMXNB_OK;
	// _gmxNB_AtCommTest(response);


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

void DTCoTNBIoTHardware_reset(int resetPin) {
	pinMode(resetPin, OUTPUT);
	// Reset
	digitalWrite(resetPin, HIGH);
	delay(100);
	digitalWrite(resetPin, LOW);
	delay(100);
	delay(100);
	digitalWrite(resetPin, HIGH);
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




#else

// For Feather M0 with uBlox
// Note that standard Arduino doesn't let you set interrupts on UARTS without hacking the variants.cpp file.
// So we need to setup our own timer interrupts

void DTCoTNBIoTHardware_reset(int resetPin);



#define INTPIN 6
#define UBLOX_SARA_N2_DEFAULT_BAUD_RATE 9600

int DTCoTNBIoTHardware_init(Stream & serial, int resetPin, void( *callback)()) {
	byte init_status = GMXNB_KO;
	
	/*pinMode(GMX_GPIO1, OUTPUT);
	pinMode(GMX_GPIO2, OUTPUT);
	pinMode(GMX_GPIO3, OUTPUT);
	digitalWrite(GMX_GPIO1, LOW);
	digitalWrite(GMX_GPIO2, LOW);
	digitalWrite(GMX_GPIO3, LOW);*/
	
	HardwareSerial * hwSerial = static_cast<HardwareSerial*>(&serial);
	
	DTCoTNBIoTHardware_reset(resetPin);
	hwSerial->begin(UBLOX_SARA_N2_DEFAULT_BAUD_RATE);
	DEBUG_PRINT_INFO("uBlox N2 Serial Interface");
	init_status = GMXNB_OK;
	// _gmxNB_AtCommTest(response);

  // delay to wait BootUp of GMX-LR
  delay(GMX_BOOT_DELAY);
  
  return init_status;
}

void DTCoTNBIoTHardware_reset(int resetPin) {
	pinMode(resetPin, OUTPUT);
	// Reset
	digitalWrite(resetPin, HIGH);
	delay(100);
	digitalWrite(resetPin, LOW);
	delay(100);
	delay(100);
	digitalWrite(resetPin, HIGH);
}

void DTCoTNBIoTHardware_led(char led_state, char ledNumber) {
	
}




#endif

