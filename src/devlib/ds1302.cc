#include "ds1302.h"
#include <ds1302.h>

DECLARE(ds1302rtcRead);
DECLARE(ds1302rtcWrite);
DECLARE(ds1302ramRead);
DECLARE(ds1302ramWrite);
DECLARE(ds1302clockRead);
DECLARE(ds1302clockWrite);
DECLARE(ds1302trickleCharge);
DECLARE(ds1302setup);

// Func: unsigned int ds1302rtcRead (const int reg)
// Description: Reads the data to/from the RTC register

IMPLEMENT(ds1302rtcRead) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, reg);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(1);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  
  int reg = GET_ARGUMENT_AS_INT32(0);
  
  unsigned int res = ::ds1302rtcRead(reg);
  
  SCOPE_CLOSE(UINT32(res));
}

// Func: void ds1302rtcWrite (int reg, unsigned int data)
// Description: Writes the data to/from the RTC register

IMPLEMENT(ds1302rtcWrite) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, reg);
  SET_ARGUMENT_NAME(1, data);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(2);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  CHECK_ARGUMENT_TYPE_INT32(1);
  
  int reg = GET_ARGUMENT_AS_INT32(0);
  unsigned int data = GET_ARGUMENT_AS_UINT32(1);
  
  ::ds1302rtcWrite(reg, data);
  
  SCOPE_CLOSE(UNDEFINED());
}

IMPLEMENT(ds1302ramRead) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, address);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(1);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  
  int address = GET_ARGUMENT_AS_INT32(0);
  
  unsigned int res = ::ds1302ramRead(address);
  
  SCOPE_CLOSE(UINT32(res));
}

IMPLEMENT(ds1302ramWrite) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, address);
  SET_ARGUMENT_NAME(1, data);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(2);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  CHECK_ARGUMENT_TYPE_UINT32(1);
  
  int address = GET_ARGUMENT_AS_INT32(0);
  unsigned int data = GET_ARGUMENT_AS_UINT32(1);
  
  ::ds1302ramWrite(address, data);
  
  SCOPE_CLOSE(UNDEFINED());
}

IMPLEMENT(ds1302clockRead) {
  SCOPE_OPEN();
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(0);
  
  int clockData[8];
  ::ds1302clockRead(clockData);
  
  #if NODE_VERSION_AT_LEAST(0, 11, 0)
    v8::Local<v8::Array> res = v8::Array::New(isolate, 8);
  #else
    v8::Local<v8::Array> res = v8::Array::New(8);
  #endif
  for (int i = 0; i < 8; i++) {
    #if NODE_VERSION_AT_LEAST(0, 11, 0)
      res->Set(i, v8::Int32::New(isolate, clockData[i]));
    #else
      res->Set(i, v8::Int32::New(clockData[i]));
    #endif
  }
  
  SCOPE_CLOSE(res);
}

IMPLEMENT(ds1302clockWrite) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, clockData);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(1);
  
  CHECK_ARGUMENT_TYPE_ARRAY(0);
  CHECK_ARGUMENT_ARRAY_LENGTH(0, 8);
  
  v8::Local<v8::Array> clockData = v8::Local<v8::Array>::Cast(args[0]);
  
  int ar[8];
  for (int i = 0; i < 8; i++) {
    ar[i] = clockData->Get(i)->Int32Value();
  }
  
  ::ds1302clockWrite(ar);
  
  SCOPE_CLOSE(UNDEFINED());
}

IMPLEMENT(ds1302trickleCharge) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, diodes);
  SET_ARGUMENT_NAME(1, resistors);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(2);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  CHECK_ARGUMENT_TYPE_INT32(1);
  
  int diodes = GET_ARGUMENT_AS_INT32(0);
  int resistors = GET_ARGUMENT_AS_INT32(1);
  
  ::ds1302trickleCharge(diodes, resistors);
  
  SCOPE_CLOSE(UNDEFINED());
}

IMPLEMENT(ds1302setup) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, clockPin);
  SET_ARGUMENT_NAME(1, dataPin);
  SET_ARGUMENT_NAME(2, csPin);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(3);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  CHECK_ARGUMENT_TYPE_INT32(1);
  CHECK_ARGUMENT_TYPE_INT32(2);
  
  int clockPin = GET_ARGUMENT_AS_INT32(0);
  int dataPin = GET_ARGUMENT_AS_INT32(1);
  int csPin = GET_ARGUMENT_AS_INT32(2);
  
  ::ds1302setup(clockPin, dataPin, csPin);
  
  SCOPE_CLOSE(UNDEFINED());
}

IMPLEMENT_EXPORT_INIT(ds1302) {
  EXPORT_FUNCTION(ds1302rtcRead);
  EXPORT_FUNCTION(ds1302rtcWrite);
  EXPORT_FUNCTION(ds1302ramRead);
  EXPORT_FUNCTION(ds1302ramWrite);
  EXPORT_FUNCTION(ds1302clockRead);
  EXPORT_FUNCTION(ds1302clockWrite);
  EXPORT_FUNCTION(ds1302trickleCharge);
  EXPORT_FUNCTION(ds1302setup);
}