#include "mcp3004.h"
#include <mcp3004.h>

DECLARE(mcp3004Setup);

// Func : int mcp3004Setup(int pinBase, int spiChannel)

IMPLEMENT(mcp3004Setup) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, pinBase);
  SET_ARGUMENT_NAME(1, spiChannel);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(2);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  CHECK_ARGUMENT_TYPE_INT32(1);
  
  int pinBase = GET_ARGUMENT_AS_INT32(0);
  int spiChannel = GET_ARGUMENT_AS_INT32(1);
  
  CHECK_ARGUMENT_IN_INTS(1, spiChannel, (0, 1));
  
  int res = ::mcp3004Setup(pinBase, spiChannel);
  
  SCOPE_CLOSE(INT32(res));
}

IMPLEMENT_EXPORT_INIT(mcp3004) {
  EXPORT_FUNCTION(mcp3004Setup);
}