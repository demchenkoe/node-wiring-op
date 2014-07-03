#include "pcf8574.h"
#include <pcf8574.h>

DECLARE(pcf8574Setup);

// Func : int pcf8574Setup(const int pinBase, const int i2cAddress)

IMPLEMENT(pcf8574Setup) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, pinBase);
  SET_ARGUMENT_NAME(1, i2cAddress);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(2);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  CHECK_ARGUMENT_TYPE_INT32(1);
  
  int pinBase = GET_ARGUMENT_AS_INT32(0);
  int i2cAddress = GET_ARGUMENT_AS_INT32(1);
  
  int res = ::pcf8574Setup(pinBase, i2cAddress);
  
  SCOPE_CLOSE(INT32(res));
}

IMPLEMENT_EXPORT_INIT(pcf8574) {
  EXPORT_FUNCTION(pcf8574Setup);
}