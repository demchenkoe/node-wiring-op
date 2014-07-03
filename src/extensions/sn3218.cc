#include "sn3218.h"
#include <sn3218.h>

DECLARE(sn3218Setup);

// Func : int sn3128Setup(int pinBase)

IMPLEMENT(sn3218Setup) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, pinBase);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(1);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  
  int pinBase = GET_ARGUMENT_AS_INT32(0);
  
  int res = ::sn3218Setup(pinBase);
  
  SCOPE_CLOSE(INT32(res));
}

IMPLEMENT_EXPORT_INIT(sn3218) {
  EXPORT_FUNCTION(sn3218Setup);
}