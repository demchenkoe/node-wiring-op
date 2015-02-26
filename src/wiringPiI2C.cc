#include "wiringPiI2C.h"
#include <wiringPiI2C.h>

DECLARE(wiringPiI2CRead);
DECLARE(wiringPiI2CReadReg8);
DECLARE(wiringPiI2CReadReg16);
DECLARE(wiringPiI2CWrite);
DECLARE(wiringPiI2CWriteReg8);
DECLARE(wiringPiI2CWriteReg16);
DECLARE(wiringPiI2CSetupInterface);
DECLARE(wiringPiI2CSetup);

// Func : int wiringPiI2CRead (int fd);
// Simple device read. Some devices present data when you read them without having to do any register transactions.

IMPLEMENT(wiringPiI2CRead) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, fd);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(1);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  
  int fd = GET_ARGUMENT_AS_INT32(0);
  
  int res = ::wiringPiI2CRead(fd);
  
  SCOPE_CLOSE(INT32(res));
}

// Func : int wiringPiI2CRead (int fd, int reg);
// read an 8-bits value from the device register indicated.

IMPLEMENT(wiringPiI2CReadReg8) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, fd);
  SET_ARGUMENT_NAME(1, reg);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(2);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  CHECK_ARGUMENT_TYPE_INT32(1);
  
  int fd = GET_ARGUMENT_AS_INT32(0);
  int reg = GET_ARGUMENT_AS_INT32(1);
  
  int res = ::wiringPiI2CReadReg8(fd, reg);
  
  SCOPE_CLOSE(INT32(res));
}

// Func : int wiringPiI2CRead (int fd, int reg)
// read a 16-bits value from the device register indicated.

IMPLEMENT(wiringPiI2CReadReg16) {
  SCOPE_OPEN();

  SET_ARGUMENT_NAME(0, fd);
  SET_ARGUMENT_NAME(1, reg);

  CHECK_ARGUMENTS_LENGTH_EQUAL(2);

  CHECK_ARGUMENT_TYPE_INT32(0);
  CHECK_ARGUMENT_TYPE_INT32(1);

  int fd = GET_ARGUMENT_AS_INT32(0);
  int reg = GET_ARGUMENT_AS_INT32(1);

  int res = ::wiringPiI2CReadReg16(fd, reg);

  SCOPE_CLOSE(INT32(res));
}

// Func : int wiringPiI2CWrite (int fd, int data)
// Simple device write. Some devices accept data this way without needing to access any internal registers.

IMPLEMENT(wiringPiI2CWrite) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, fd);
  SET_ARGUMENT_NAME(1, data);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(2);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  CHECK_ARGUMENT_TYPE_INT32(1);
  
  int fd = GET_ARGUMENT_AS_INT32(0);
  int data = GET_ARGUMENT_AS_INT32(1);
  data = data & 0xFF;
  
  int res = ::wiringPiI2CWrite(fd, data);
  
  SCOPE_CLOSE(INT32(res));
}

// Func : int wiringPiI2CWriteReg8 (int fd, int reg, int data)
// write an 8-bit data value into the device register indicated.

IMPLEMENT(wiringPiI2CWriteReg8) {
  SCOPE_OPEN();

  SET_ARGUMENT_NAME(0, fd);
  SET_ARGUMENT_NAME(1, reg);
  SET_ARGUMENT_NAME(2, data);

  CHECK_ARGUMENTS_LENGTH_EQUAL(3);

  CHECK_ARGUMENT_TYPE_INT32(0);
  CHECK_ARGUMENT_TYPE_INT32(1);
  CHECK_ARGUMENT_TYPE_INT32(2);

  int fd = GET_ARGUMENT_AS_INT32(0);
  int reg = GET_ARGUMENT_AS_INT32(1);
  int data = GET_ARGUMENT_AS_INT32(2);
  data = data & 0xFF;

  int res = ::wiringPiI2CWriteReg8(fd, reg, data);

  SCOPE_CLOSE(INT32(res));
}

IMPLEMENT(wiringPiI2CWriteReg16) {
  SCOPE_OPEN();

  SET_ARGUMENT_NAME(0, fd);
  SET_ARGUMENT_NAME(1, reg);
  SET_ARGUMENT_NAME(2, data);

  CHECK_ARGUMENTS_LENGTH_EQUAL(3);

  CHECK_ARGUMENT_TYPE_INT32(0);
  CHECK_ARGUMENT_TYPE_INT32(1);
  CHECK_ARGUMENT_TYPE_INT32(2);

  int fd = GET_ARGUMENT_AS_INT32(0);
  int reg = GET_ARGUMENT_AS_INT32(1);
  int data = GET_ARGUMENT_AS_INT32(2);
  data = data & 0xFFFF;

  int res = ::wiringPiI2CWriteReg16(fd, reg, data);

  SCOPE_CLOSE(INT32(res));
}

// Func : int wiringPiI2CSetupInterface (const char *device, int devId)

IMPLEMENT(wiringPiI2CSetupInterface) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, device);
  SET_ARGUMENT_NAME(1, devId);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(2);
  
  CHECK_ARGUMENT_TYPE_STRING(0);
  CHECK_ARGUMENT_TYPE_INT32(1);
  
  #if NODE_VERSION_AT_LEAST(0, 11, 0)
    String::Utf8Value device(GET_ARGUMENT_AS_STRING(0));
  #else
    String::AsciiValue device(GET_ARGUMENT_AS_STRING(0));
  #endif
  int devId = GET_ARGUMENT_AS_INT32(1);
  
  int res = ::wiringPiI2CSetupInterface(*device, devId);
  
  SCOPE_CLOSE(INT32(res));
}

// Func : int wirintPiI2CSetup (int devId)

IMPLEMENT(wiringPiI2CSetup) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, devId);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(1);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  
  int devId = GET_ARGUMENT_AS_INT32(0);
  
  int res = ::wiringPiI2CSetup(devId);
  
  SCOPE_CLOSE(INT32(res));
}

IMPLEMENT_EXPORT_INIT(wiringPiI2C) {
  EXPORT_FUNCTION(wiringPiI2CRead);
  EXPORT_FUNCTION(wiringPiI2CReadReg8);
  EXPORT_FUNCTION(wiringPiI2CReadReg16);
  EXPORT_FUNCTION(wiringPiI2CWrite);
  EXPORT_FUNCTION(wiringPiI2CWriteReg8);
  EXPORT_FUNCTION(wiringPiI2CWriteReg16);
  EXPORT_FUNCTION(wiringPiI2CSetupInterface);
  EXPORT_FUNCTION(wiringPiI2CSetup);
}
