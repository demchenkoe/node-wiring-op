#include "mcp3002.h"
#include <mcp3002.h>

DECLARE(mcp3002Setup);

// Func : int mcp3002Setup(int pinBase, int spiChannel)

IMPLEMENT(mcp3002Setup) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, pinBase);
  SET_ARGUMENT_NAME(1, spiChannel);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(2);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  CHECK_ARGUMENT_TYPE_INT32(1);
  
  int pinBase = GET_ARGUMENT_AS_INT32(0);
  int spiChannel = GET_ARGUMENT_AS_INT32(1);
  
  CHECK_ARGUMENT_IN_INTS(1, spiChannel, (0, 1));
  
  int res = ::mcp3002Setup(pinBase, spiChannel);
  
  SCOPE_CLOSE(INT32(res));
}

IMPLEMENT_EXPORT_INIT(mcp3002) {
  EXPORT_FUNCTION(mcp3002Setup);
}