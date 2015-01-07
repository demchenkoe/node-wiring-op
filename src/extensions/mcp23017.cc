#include "mcp23017.h"
#include <mcp23017.h>

DECLARE(mcp23017Setup);

// Func : int mcp23017Setup(int pinBase, int i2cAddress)

IMPLEMENT(mcp23017Setup) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, pinBase);
  SET_ARGUMENT_NAME(1, i2cAddress);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(2);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  CHECK_ARGUMENT_TYPE_INT32(1);
  
  int pinBase = GET_ARGUMENT_AS_INT32(0);
  int i2cAddress = GET_ARGUMENT_AS_INT32(1);
  
  int res = ::mcp23017Setup(pinBase, i2cAddress);
  
  SCOPE_CLOSE(INT32(res));
}

IMPLEMENT_EXPORT_INIT(mcp23017) {
  EXPORT_FUNCTION(mcp23017Setup);
}