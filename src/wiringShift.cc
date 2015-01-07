#include "wiringShift.h"
#include <wiringShift.h>

DECLARE(shiftIn);
DECLARE(shiftOut);

// Func : uint8_t shiftIn(uint8_t dPin, uint8_t cPin, uint8_t order)
// Description : This shifts an 8-bit data value in with the data appearing on the dPin and the clock being sent out on the cPin.
// Order is either LSBFIRST or MSBFIRST.
// The data is sampled after the cPin goes high.
// (So cPin high, sample data, cPin low, repeat for 8 bits) The 8-bit value is returned by the function.

IMPLEMENT(shiftIn) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, dPin);
  SET_ARGUMENT_NAME(1, cPin);
  SET_ARGUMENT_NAME(2, order);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(3);
  
  CHECK_ARGUMENT_TYPE_UINT32(0);
  CHECK_ARGUMENT_TYPE_UINT32(1);
  CHECK_ARGUMENT_TYPE_UINT32(2);
  
  uint8_t dPin = GET_ARGUMENT_AS_UINT32(0);
  uint8_t cPin = GET_ARGUMENT_AS_UINT32(1);
  uint8_t order = GET_ARGUMENT_AS_UINT32(2);
  
  CHECK_ARGUMENT_IN_INTS(2, order, (LSBFIRST, MSBFIRST));
  
  uint8_t res = ::shiftIn(dPin, cPin, order);
  
  SCOPE_CLOSE(UINT32(res));
}

// Func : void shiftOut(uint8_t dPin, uint8_t cPin, uint8_t order, uint8_t val) ;
// Description : The shifts an 8-bit data value val out with the data being sent out on dPin and the clock being sent out on the cPin.
// order is as above. 
// Data is clocked out on the rising or falling edge – ie. dPin is set, then cPin is taken high then low – repeated for the 8 bits.

IMPLEMENT(shiftOut) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, dPin);
  SET_ARGUMENT_NAME(1, cPin);
  SET_ARGUMENT_NAME(2, order);
  SET_ARGUMENT_NAME(3, value);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(4);
  
  CHECK_ARGUMENT_TYPE_UINT32(0);
  CHECK_ARGUMENT_TYPE_UINT32(1);
  CHECK_ARGUMENT_TYPE_UINT32(2);
  CHECK_ARGUMENT_TYPE_UINT32(3);
  
  uint8_t dPin = GET_ARGUMENT_AS_UINT32(0);
  uint8_t cPin = GET_ARGUMENT_AS_UINT32(1);
  uint8_t order = GET_ARGUMENT_AS_UINT32(2);
  uint8_t value = GET_ARGUMENT_AS_UINT32(3);
  
  CHECK_ARGUMENT_IN_INTS(2, order, (LSBFIRST, MSBFIRST));
  
  ::shiftOut(dPin, cPin, order, value);
  
  SCOPE_CLOSE(UNDEFINED());
}

IMPLEMENT_EXPORT_INIT(wiringShift) {
  EXPORT_FUNCTION(shiftIn);
  EXPORT_FUNCTION(shiftOut);
  
  EXPORT_CONSTANT_INT(LSBFIRST);
  EXPORT_CONSTANT_INT(MSBFIRST);
}