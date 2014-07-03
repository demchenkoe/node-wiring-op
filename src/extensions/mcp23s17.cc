#include "mcp23s17.h"
#include <mcp23s17.h>

DECLARE(mcp23s17Setup);

// Func : int mcp23s17Setup(int pinBase, int spiPort, int devId)
// Description : Initialise libWiringPi to be used with MCP23S17
// pinBase is any number above 64 that doesn’t clash with any other wiringPi expansion module, 
// spiPort is 0 or 1 for one of the two SPI ports on the Pi and devId is the ID of that MCP23s17 on the SPI port.

IMPLEMENT(mcp23s17Setup) {
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
  
  //MCP23S17 3bits addressing
  CHECK_ARGUMENT_IN_RANGE(2, devId, 0, 7);
  
  int res = ::mcp23s17Setup(pinBase, spiChannel, devId);
  
  SCOPE_CLOSE(INT32(res));
}

IMPLEMENT_EXPORT_INIT(mcp23s17) {
  EXPORT_FUNCTION(mcp23s17Setup);
}