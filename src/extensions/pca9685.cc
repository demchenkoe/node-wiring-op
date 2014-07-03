#include "pca9685.h"
#include <pca9685.h>

DECLARE(pca9685Setup);

IMPLEMENT(pca9685Setup) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, pinBase);
  SET_ARGUMENT_NAME(1, i2cAddress);
  SET_ARGUMENT_NAME(2, frequency);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(3);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  CHECK_ARGUMENT_TYPE_INT32(1);
  CHECK_ARGUMENT_TYPE_INT32(2);
  
  int pinBase = GET_ARGUMENT_AS_INT32(0);
  int i2cAddress = GET_ARGUMENT_AS_INT32(1);
  int freq = GET_ARGUMENT_AS_INT32(2);
  
  int res = ::pca9685Setup(pinBase, i2cAddress, freq);
  
  SCOPE_CLOSE(INT32(res));
}

IMPLEMENT_EXPORT_INIT(pca9685) {
  EXPORT_FUNCTION(pca9685Setup);
}