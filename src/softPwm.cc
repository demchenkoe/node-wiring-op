#include "softPwm.h"
#include <softPwm.h>

DECLARE(softPwmCreate);
DECLARE(softPwmWrite);
DECLARE(softPwmStop);

// Func : int softPwmCreate(int pin, int value, int range)
// Description : This creates a software controlled PWM pin. 
// You can use any GPIO pin and the pin numbering will be that of the wiringPiSetup() function you used. 
// Use 100 for the pwmRange, then the value can be anything from 0 (off) to 100 (fully on) for the given pin.
// The return value is 0 for success. Anything else and you should check the global errno variable to see what went wrong.
// NOTE : You must initialise wiringPi with one of wiringPiSetup(),  wiringPiSetupGpio() or wiringPiSetupPhys() functions. 
// wiringPiSetupSys() is not fast enough, so you must run your programs with sudo.
// NOTE2 : Each “cycle” of PWM output takes 10mS with the default range value of 100, 
// so trying to change the PWM value more than 100 times a second will be futile.
// NOTE3 : Each pin activated in softPWM mode uses approximately 0.5% of the CPU.
// NOTE4 : There is currently no way to disable softPWM on a pin while the program in running.
// NOTE5 : You need to keep your program running to maintain the PWM output!

IMPLEMENT(softPwmCreate) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, pin);
  SET_ARGUMENT_NAME(1, value);
  SET_ARGUMENT_NAME(2, range);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(3);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  CHECK_ARGUMENT_TYPE_INT32(1);
  CHECK_ARGUMENT_TYPE_INT32(2);
  
  int pin = GET_ARGUMENT_AS_INT32(0);
  int value = GET_ARGUMENT_AS_INT32(1);
  int range = GET_ARGUMENT_AS_INT32(2);
  
  int res = ::softPwmCreate(pin, value, range);
  
  SCOPE_CLOSE(INT32(res));
}

// Func void softPwmWrite(int pin, int value)
// Description : This updates the PWM value on the given pin. 
// The value is checked to be in-range and pins that haven’t previously been initialised via softPwmCreate will be silently ignored.

IMPLEMENT(softPwmWrite) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, pin);
  SET_ARGUMENT_NAME(1, value);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(2);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  CHECK_ARGUMENT_TYPE_INT32(1);
  
  int pin = GET_ARGUMENT_AS_INT32(0);
  int value = GET_ARGUMENT_AS_INT32(1);
  
  ::softPwmWrite(pin, value);
  
  SCOPE_CLOSE(UNDEFINED());
}

IMPLEMENT(softPwmStop) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, pin);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(1);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  
  int pin = GET_ARGUMENT_AS_INT32(0);
  
  ::softPwmStop(pin);
  
  SCOPE_CLOSE(UNDEFINED());
}

IMPLEMENT_EXPORT_INIT(softPwm) {
  EXPORT_FUNCTION(softPwmCreate);
  EXPORT_FUNCTION(softPwmWrite);
  EXPORT_FUNCTION(softPwmStop);
}