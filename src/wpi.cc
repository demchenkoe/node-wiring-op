#include "wpi.h"
#include <node.h>

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
  
  INIT(extensions);
  INIT(devlib);
}

NODE_MODULE_DECLARE(wiringPi);