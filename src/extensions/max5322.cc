#include "max5322.h"
#include <max5322.h>

DECLARE(max5322Setup);

// Func : int max5233Setup(int pinBase, int spiChannel)

IMPLEMENT(max5322Setup) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, pinBase);
  SET_ARGUMENT_NAME(1, spiChannel);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(2);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  CHECK_ARGUMENT_TYPE_INT32(1);
  
  int pinBase = GET_ARGUMENT_AS_INT32(0);
  int spiChannel = GET_ARGUMENT_AS_INT32(1);
  
  CHECK_ARGUMENT_IN_INTS(1, spiChannel, (0, 1));
  
  int res = ::max5322Setup(pinBase, spiChannel);
  
  SCOPE_CLOSE(INT32(res));
}


IMPLEMENT_EXPORT_INIT(max5322) {
  EXPORT_FUNCTION(max5322Setup);
}