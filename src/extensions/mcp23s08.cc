#include "mcp23s08.h"
#include <mcp23s08.h>

DECLARE(mcp23s08Setup);

// Func int mcp23s08Setup(const int pinBase, const int spiChannel, const int devId)

IMPLEMENT(mcp23s08Setup) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, pinBase);
  SET_ARGUMENT_NAME(1, spiChannel);
  SET_ARGUMENT_NAME(2, devId);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(3);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  CHECK_ARGUMENT_TYPE_INT32(1);
  CHECK_ARGUMENT_TYPE_INT32(2);
  
  int pinBase = GET_ARGUMENT_AS_INT32(0);
  int spiChannel = GET_ARGUMENT_AS_INT32(1);
  int devId = GET_ARGUMENT_AS_INT32(2);
  
  CHECK_ARGUMENT_IN_INTS(1, spiChannel, (0, 1));
  
  //MCP23S08 3bits addressing
  CHECK_ARGUMENT_IN_RANGE(2, devId, 0, 7);
  
  int res = ::mcp23s08Setup(pinBase, spiChannel, devId);
  
  SCOPE_CLOSE(INT32(res));
}

IMPLEMENT_EXPORT_INIT(mcp23s08) {
  EXPORT_FUNCTION(mcp23s08Setup);
}