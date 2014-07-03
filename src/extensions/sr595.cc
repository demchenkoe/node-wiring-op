#include "sr595.h"
#include <sr595.h>

DECLARE(sr595Setup);

// Func : int sr595Setup(const int pinBase, const int numPins, const int dataPin, const int clockPin, const int latchPin)

IMPLEMENT(sr595Setup) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, pinBase);
  SET_ARGUMENT_NAME(1, numPins);
  SET_ARGUMENT_NAME(2, dataPin);
  SET_ARGUMENT_NAME(3, clockPin);
  SET_ARGUMENT_NAME(4, latchPin);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(5);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  CHECK_ARGUMENT_TYPE_INT32(1);
  CHECK_ARGUMENT_TYPE_INT32(2);
  CHECK_ARGUMENT_TYPE_INT32(3);
  CHECK_ARGUMENT_TYPE_INT32(4);
  
  int pinBase = GET_ARGUMENT_AS_INT32(0);
  int numPins = GET_ARGUMENT_AS_INT32(1);
  int dataPin = GET_ARGUMENT_AS_INT32(2);
  int clockPin = GET_ARGUMENT_AS_INT32(3);
  int latchPin = GET_ARGUMENT_AS_INT32(4);
  
  int res = ::sr595Setup(pinBase, numPins, dataPin, clockPin, latchPin);
  
  SCOPE_CLOSE(INT32(res));
}

IMPLEMENT_EXPORT_INIT(sr595) {
  EXPORT_FUNCTION(sr595Setup);
}