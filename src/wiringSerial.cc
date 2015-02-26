#include "wiringSerial.h"
#include <wiringSerial.h>

DECLARE(serialOpen);
DECLARE(serialClose);
DECLARE(serialFlush);
DECLARE(serialPutchar);
DECLARE(serialPuts);
DECLARE(serialPrintf);
DECLARE(serialDataAvail);
DECLARE(serialGetchar);

// Func : int serialOpen(const char* device, const int baud)

IMPLEMENT(serialOpen) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, device);
  SET_ARGUMENT_NAME(1, baudrate);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(2);
  
  CHECK_ARGUMENT_TYPE_STRING(0);
  CHECK_ARGUMENT_TYPE_INT32(1);
  
  #if NODE_VERSION_AT_LEAST(0, 11, 0)
    String::Utf8Value device(GET_ARGUMENT_AS_STRING(0));
  #else
    String::AsciiValue device(GET_ARGUMENT_AS_STRING(0));
  #endif
  int baudrate = GET_ARGUMENT_AS_INT32(1);
  
  int res = ::serialOpen(*device, baudrate);
  
  SCOPE_CLOSE(INT32(res));
}

// Func : void serialClose(const int fd)

IMPLEMENT(serialClose) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, fd);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(1);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  
  int fd = GET_ARGUMENT_AS_INT32(0);
  
  ::serialClose(fd);
  
  SCOPE_CLOSE(UNDEFINED());
}

// Func : void serialFlush(const int fd);

IMPLEMENT(serialFlush) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, fd);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(1);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  
  int fd = GET_ARGUMENT_AS_INT32(0);
  
  ::serialFlush(fd);
  
  SCOPE_CLOSE(UNDEFINED());
}

// Func : void serialPutchar(const int fd, const unsigned char c)

IMPLEMENT(serialPutchar) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, fd);
  SET_ARGUMENT_NAME(1, character);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(2);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  CHECK_ARGUMENT_TYPE_UINT32(1);
  
  int fd = GET_ARGUMENT_AS_INT32(0);
  unsigned char character = GET_ARGUMENT_AS_UINT32(1);
  
  ::serialPutchar(fd, character);
  
  SCOPE_CLOSE(UNDEFINED());
}

// Func : void serialPuts(const int fd, const char* s)

IMPLEMENT(serialPuts) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, fd);
  SET_ARGUMENT_NAME(1, string);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(2);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  CHECK_ARGUMENT_TYPE_STRING(1);
  
  int fd = GET_ARGUMENT_AS_INT32(0);
  #if NODE_VERSION_AT_LEAST(0, 11, 0)
    String::Utf8Value string(GET_ARGUMENT_AS_STRING(1));
  #else
    String::AsciiValue string(GET_ARGUMENT_AS_STRING(1));
  #endif
  
  ::serialPuts(fd, *string);
  
  SCOPE_CLOSE(UNDEFINED());
}

// Func : void serialPrintf(const int fd, const char* message, ...)

IMPLEMENT(serialPrintf) {
  // Make serialPrintf a alias to serialPuts
  return serialPuts(args);
}

// Func : int serialDataAvail(const int fd)

IMPLEMENT(serialDataAvail) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, fd);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(1);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  
  int fd = GET_ARGUMENT_AS_INT32(0);
  
  int res = ::serialDataAvail(fd);
  
  SCOPE_CLOSE(INT32(res));
}

// Func : int serialGetchar(const int fd)
// NOTE TO MYSELF : I don't understand why serialPutchar takes a unsigned char and on the other side
// serialGetchar returns a int ... serialGetchar should returns a unsigned char too.

IMPLEMENT(serialGetchar) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, fd);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(1);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  
  int fd = GET_ARGUMENT_AS_INT32(0);
  
  int res = ::serialGetchar(fd);
  
  SCOPE_CLOSE(INT32(res));
}

IMPLEMENT_EXPORT_INIT(wiringSerial) {
  EXPORT_FUNCTION(serialOpen);
  EXPORT_FUNCTION(serialClose);
  EXPORT_FUNCTION(serialFlush);
  EXPORT_FUNCTION(serialPutchar);
  EXPORT_FUNCTION(serialPuts);
  EXPORT_FUNCTION(serialPrintf);
  EXPORT_FUNCTION(serialDataAvail);
  EXPORT_FUNCTION(serialGetchar);
}