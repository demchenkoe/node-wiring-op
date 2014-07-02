#include "wpi.h"

NODE_MODULE_INIT() {
  INIT(wiringPi);
  INIT(softPwm);
  INIT(softServo);
  INIT(softTone);
  INIT(wiringPiI2C);
  INIT(wiringPiSPI);
  INIT(wiringSerial);
  INIT(wiringShift);
  INIT(wiringPiISR);
}

NODE_MODULE_DECLARE(wiringPi);