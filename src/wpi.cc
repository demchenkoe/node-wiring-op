#include "wpi.h"
#include <node.h>

NODE_MODULE_INIT() {
  #if NODE_VERSION_AT_LEAST(0, 11, 0)
    v8::Isolate* isolate = v8::Isolate::GetCurrent();
  #endif
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