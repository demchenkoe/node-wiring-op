#include "mcp4802.h"
#include <mcp4802.h>

DECLARE(mcp4802Setup);

// Func : int mcp4802Setup(int pinBase, int spiChannel)

IMPLEMENT(mcp4802Setup) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, pinBase);
  SET_ARGUMENT_NAME(1, spiChannel);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(2);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  CHECK_ARGUMENT_TYPE_INT32(1);
  
  int pinBase = GET_ARGUMENT_AS_INT32(0);
  int spiChannel = GET_ARGUMENT_AS_INT32(1);
  
  CHECK_ARGUMENT_IN_INTS(1, spiChannel, (0, 1));
  
  int res = ::mcp4802Setup(pinBase, spiChannel);
  
  SCOPE_CLOSE(INT32(res));
}

IMPLEMENT_EXPORT_INIT(mcp4802) {
  EXPORT_FUNCTION(mcp4802Setup);
}