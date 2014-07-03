#include "mcp23008.h"
#include <mcp23008.h>

DECLARE(mcp23008Setup);

// Func : int mcp23008Setup(int pinBase, int i2cAddress)

IMPLEMENT(mcp23008Setup) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, pinBase);
  SET_ARGUMENT_NAME(1, i2cAddress);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(2);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  CHECK_ARGUMENT_TYPE_INT32(1);
  
  int pinBase = GET_ARGUMENT_AS_INT32(0);
  int i2cAddress = GET_ARGUMENT_AS_INT32(1);
  
  int res = ::mcp23008Setup(pinBase, i2cAddress);
  
  SCOPE_CLOSE(INT32(res));
}

IMPLEMENT_EXPORT_INIT(mcp23008) {
  EXPORT_FUNCTION(mcp23008Setup);
}