#include "max31855.h"
#include <max31855.h>

DECLARE(max31855Setup);

// Func : int max31855Setup(int pinBase, int spiChannel)

IMPLEMENT(max31855Setup) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, pinBase);
  SET_ARGUMENT_NAME(1, spiChannel);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(2);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  CHECK_ARGUMENT_TYPE_INT32(1);
  
  int pinBase = GET_ARGUMENT_AS_INT32(0);
  int spiChannel = GET_ARGUMENT_AS_INT32(1);
  
  CHECK_ARGUMENT_IN_INTS(1, spiChannel, (0, 1));
  
  int res = ::max31855Setup(pinBase, spiChannel);
  
  SCOPE_CLOSE(INT32(res));
}

IMPLEMENT_EXPORT_INIT(max31855) {
  EXPORT_FUNCTION(max31855Setup);
}