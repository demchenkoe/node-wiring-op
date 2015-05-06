#ifndef _WPI_WIRING_PI_H_
#define _WPI_WIRING_PI_H_

  #include "addon.h"

  #define	FSEL_INPT		0b000
  #define	FSEL_OUTP		0b001
  #define	FSEL_ALT0		0b100
  #define	FSEL_ALT1		0b101
  #define	FSEL_ALT2		0b110
  #define	FSEL_ALT3		0b111
  #define	FSEL_ALT4		0b011
  #define	FSEL_ALT5		0b010

  DECLARE_EXPORT_INIT(wiringPi);

#endif
