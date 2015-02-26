#include <tcs34725.h>
#include "tcs34725.h"

DECLARE(tcs34725ReadRGBC);
DECLARE(tcs34725ReadHSV);
DECLARE(tcs34725GetCorrelatedColorTemperature);
DECLARE(tcs34725GetIlluminance);
DECLARE(tcs34725SetInterrupt);
DECLARE(tcs34725ClearInterrupt);
DECLARE(tcs34725SetInterruptLimits);
DECLARE(tcs34725Enable);
DECLARE(tcs34725Disable);
DECLARE(tcs34725Setup);

IMPLEMENT(tcs34725ReadRGBC) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, id);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(1);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  
  int id = GET_ARGUMENT_AS_INT32(0);
  unsigned char r, g, b, c;
  
  ::tcs34725ReadRGBC(id, &r, &g, &b, &c);
  
  #if NODE_VERSION_AT_LEAST(0, 11, 0)
    Local<Object> obj = Object::New(isolate);
    obj->Set(String::NewFromUtf8(isolate, "r", v8::String::kInternalizedString), UINT32(r));
    obj->Set(String::NewFromUtf8(isolate, "g", v8::String::kInternalizedString), UINT32(g));
    obj->Set(String::NewFromUtf8(isolate, "b", v8::String::kInternalizedString), UINT32(b));
    obj->Set(String::NewFromUtf8(isolate, "c", v8::String::kInternalizedString), UINT32(c));
  #else
    Local<Object> obj = Object::New();
    obj->Set(String::NewSymbol("r"), UINT32(r));
    obj->Set(String::NewSymbol("g"), UINT32(g));
    obj->Set(String::NewSymbol("b"), UINT32(b));
    obj->Set(String::NewSymbol("c"), UINT32(c));
  #endif
  
  SCOPE_CLOSE(obj);
}

IMPLEMENT(tcs34725ReadHSV) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, id);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(1);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  
  int id = GET_ARGUMENT_AS_INT32(0);
  unsigned short h;
  unsigned char s, v;
  
  ::tcs34725ReadHSV(id, &h, &s, &v);
  
  #if NODE_VERSION_AT_LEAST(0, 11, 0)
    Local<Object> obj = Object::New(isolate);
    obj->Set(String::NewFromUtf8(isolate, "h", v8::String::kInternalizedString), UINT32(h));
    obj->Set(String::NewFromUtf8(isolate, "s", v8::String::kInternalizedString), UINT32(s));
    obj->Set(String::NewFromUtf8(isolate, "v", v8::String::kInternalizedString), UINT32(v));
  #else
    Local<Object> obj = Object::New();
    obj->Set(String::NewSymbol("h"), UINT32(h));
    obj->Set(String::NewSymbol("s"), UINT32(s));
    obj->Set(String::NewSymbol("v"), UINT32(v));
  #endif
  
  SCOPE_CLOSE(obj);
}

IMPLEMENT(tcs34725GetCorrelatedColorTemperature) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, r);
  SET_ARGUMENT_NAME(1, g);
  SET_ARGUMENT_NAME(2, b);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(3);
  
  CHECK_ARGUMENT_TYPE_UINT32(0);
  CHECK_ARGUMENT_TYPE_UINT32(1);
  CHECK_ARGUMENT_TYPE_UINT32(2);
  
  unsigned short r = GET_ARGUMENT_AS_UINT32(0);
  unsigned short g = GET_ARGUMENT_AS_UINT32(1);
  unsigned short b = GET_ARGUMENT_AS_UINT32(2);
  
  unsigned short k = ::tcs34725GetCorrelatedColorTemperature(r, g, b);
  
  SCOPE_CLOSE(UINT32(k));
}

IMPLEMENT(tcs34725GetIlluminance) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, r);
  SET_ARGUMENT_NAME(1, g);
  SET_ARGUMENT_NAME(2, b);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(3);
  
  CHECK_ARGUMENT_TYPE_UINT32(0);
  CHECK_ARGUMENT_TYPE_UINT32(1);
  CHECK_ARGUMENT_TYPE_UINT32(2);
  
  unsigned short r = GET_ARGUMENT_AS_UINT32(0);
  unsigned short g = GET_ARGUMENT_AS_UINT32(1);
  unsigned short b = GET_ARGUMENT_AS_UINT32(2);
  
  unsigned short i = ::tcs34725GetIlluminance(r, g, b);
  
  SCOPE_CLOSE(UINT32(i));
}

IMPLEMENT(tcs34725SetInterrupt) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, id);
  SET_ARGUMENT_NAME(1, aien);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(2);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  CHECK_ARGUMENT_TYPE_INT32(1);
  
  int id = GET_ARGUMENT_AS_INT32(0);
  int aien = GET_ARGUMENT_AS_INT32(1);
  
  ::tcs34725SetInterrupt(id, aien);
  
  SCOPE_CLOSE(UNDEFINED());
}

IMPLEMENT(tcs34725ClearInterrupt) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, id);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(1);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  
  int id = GET_ARGUMENT_AS_INT32(0);
  
  ::tcs34725ClearInterrupt(id);
  
  SCOPE_CLOSE(UNDEFINED());
}

IMPLEMENT(tcs34725SetInterruptLimits) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, id);
  SET_ARGUMENT_NAME(1, low);
  SET_ARGUMENT_NAME(2, high);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(3);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  CHECK_ARGUMENT_TYPE_UINT32(1);
  CHECK_ARGUMENT_TYPE_UINT32(2);
  
  int id = GET_ARGUMENT_AS_INT32(0);
  int low = GET_ARGUMENT_AS_UINT32(1) & 0xFFFF;
  int high = GET_ARGUMENT_AS_UINT32(2) & 0xFFFF;
  
  ::tcs34725SetInterruptLimits(id, low, high);
  
  SCOPE_CLOSE(UNDEFINED());
}

IMPLEMENT(tcs34725Enable) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, id);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(1);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  
  int id = GET_ARGUMENT_AS_INT32(0);
  
  ::tcs34725Enable(id);
  
  SCOPE_CLOSE(UNDEFINED());
}

IMPLEMENT(tcs34725Disable) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, id);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(1);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  
  int id = GET_ARGUMENT_AS_INT32(0);
  
  ::tcs34725Disable(id);
  
  SCOPE_CLOSE(UNDEFINED());
}

IMPLEMENT(tcs34725Setup) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, i2cAddress);
  SET_ARGUMENT_NAME(1, integrationTime);
  SET_ARGUMENT_NAME(2, gain);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(3);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  CHECK_ARGUMENT_TYPE_INT32(1);
  CHECK_ARGUMENT_TYPE_INT32(2);
  
  int i2cAddress = GET_ARGUMENT_AS_INT32(0);
  int integrationTime = GET_ARGUMENT_AS_INT32(1);
  int gain = GET_ARGUMENT_AS_INT32(2);
  
  CHECK_ARGUMENT_IN_INTS(1, integrationTime, (TCS34725_ATIME_2_4MS, TCS34725_ATIME_24MS, TCS34725_ATIME_50MS, TCS34725_ATIME_101MS, TCS34725_ATIME_154MS, TCS34725_ATIME_700MS));
  CHECK_ARGUMENT_IN_INTS(2, gain, (TCS34725_GAIN_1, TCS34725_GAIN_4, TCS34725_GAIN_16, TCS34725_GAIN_60));
  
  int id = ::tcs34725Setup(i2cAddress, integrationTime, gain);
  
  SCOPE_CLOSE(INT32(id));
}

IMPLEMENT_EXPORT_INIT(tcs34725) {
  EXPORT_FUNCTION(tcs34725ReadRGBC);
  EXPORT_FUNCTION(tcs34725ReadHSV);
  EXPORT_FUNCTION(tcs34725GetCorrelatedColorTemperature);
  EXPORT_FUNCTION(tcs34725GetIlluminance);
  EXPORT_FUNCTION(tcs34725SetInterrupt);
  EXPORT_FUNCTION(tcs34725ClearInterrupt);
  EXPORT_FUNCTION(tcs34725SetInterruptLimits);
  EXPORT_FUNCTION(tcs34725Enable);
  EXPORT_FUNCTION(tcs34725Disable);
  EXPORT_FUNCTION(tcs34725Setup);
  
  EXPORT_CONSTANT_INT(TCS34725_ATIME_2_4MS);
  EXPORT_CONSTANT_INT(TCS34725_ATIME_24MS);
  EXPORT_CONSTANT_INT(TCS34725_ATIME_50MS);
  EXPORT_CONSTANT_INT(TCS34725_ATIME_101MS);
  EXPORT_CONSTANT_INT(TCS34725_ATIME_154MS);
  EXPORT_CONSTANT_INT(TCS34725_ATIME_700MS);
  
  EXPORT_CONSTANT_INT(TCS34725_GAIN_1);
  EXPORT_CONSTANT_INT(TCS34725_GAIN_4);
  EXPORT_CONSTANT_INT(TCS34725_GAIN_16);
  EXPORT_CONSTANT_INT(TCS34725_GAIN_60);
  
  EXPORT_CONSTANT_INT(TCS34725_MAX_TCS34725);
}