#include "piFace.h"
#include <piFace.h>

DECLARE(piFaceSetup);

IMPLEMENT(piFaceSetup) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, pinBase);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(1);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  
  int pinBase = GET_ARGUMENT_AS_INT32(0);
  
  int res = ::piFaceSetup(pinBase);
  
  SCOPE_CLOSE(INT32(res));
}

IMPLEMENT_EXPORT_INIT(piFace) {
  EXPORT_FUNCTION(piFaceSetup);
}