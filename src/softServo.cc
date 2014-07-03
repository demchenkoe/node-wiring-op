#include "softServo.h"
#include <softServo.h>

DECLARE(softServoWrite);
DECLARE(softServoSetup);

// Func : void softServoWrite(int pin, int value)
// Description : Write a Servo value to the given pin

IMPLEMENT(softServoWrite) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, pin);
  SET_ARGUMENT_NAME(1, value);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(2);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  CHECK_ARGUMENT_TYPE_INT32(1);
  
  int pin = GET_ARGUMENT_AS_INT32(0);
  int value = GET_ARGUMENT_AS_INT32(1);
  
  ::softServoWrite(pin, value);
  
  SCOPE_CLOSE(UNDEFINED());
}

// Func : int softServoSetup(int p0, int p1, int p2, int p3, int p4, int p5, int p6, int p7)
// Description : Setup the software servo system

IMPLEMENT(softServoSetup) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, p0);
  SET_ARGUMENT_NAME(1, p1);
  SET_ARGUMENT_NAME(2, p2);
  SET_ARGUMENT_NAME(3, p3);
  SET_ARGUMENT_NAME(4, p4);
  SET_ARGUMENT_NAME(5, p5);
  SET_ARGUMENT_NAME(6, p6);
  SET_ARGUMENT_NAME(7, p7);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(8);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  CHECK_ARGUMENT_TYPE_INT32(1);
  CHECK_ARGUMENT_TYPE_INT32(2);
  CHECK_ARGUMENT_TYPE_INT32(3);
  CHECK_ARGUMENT_TYPE_INT32(4);
  CHECK_ARGUMENT_TYPE_INT32(5);
  CHECK_ARGUMENT_TYPE_INT32(6);
  CHECK_ARGUMENT_TYPE_INT32(7);
  
  int p0 = GET_ARGUMENT_AS_INT32(0);
  int p1 = GET_ARGUMENT_AS_INT32(1);
  int p2 = GET_ARGUMENT_AS_INT32(2);
  int p3 = GET_ARGUMENT_AS_INT32(3);
  int p4 = GET_ARGUMENT_AS_INT32(4);
  int p5 = GET_ARGUMENT_AS_INT32(5);
  int p6 = GET_ARGUMENT_AS_INT32(6);
  int p7 = GET_ARGUMENT_AS_INT32(7);
  
  int res = ::softServoSetup(p0, p1, p2, p3, p4, p5, p6, p7);
  
  SCOPE_CLOSE(INT32(res));
}

IMPLEMENT_EXPORT_INIT(softServo) {
  EXPORT_FUNCTION(softServoWrite);
  EXPORT_FUNCTION(softServoSetup);
}