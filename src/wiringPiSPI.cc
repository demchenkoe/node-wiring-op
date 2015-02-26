#include "wiringPiSPI.h"
#include <wiringPiSPI.h>

DECLARE(wiringPiSPIGetFd);
DECLARE(wiringPiSPIDataRW);
DECLARE(wiringPiSPISetup);
DECLARE(wiringPiSPISetupMode);

// Func : int wiringPiSPIGetFd(int channel)

IMPLEMENT(wiringPiSPIGetFd) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, channel);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(1);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  
  int channel = GET_ARGUMENT_AS_INT32(0);
  
  CHECK_ARGUMENT_IN_INTS(0, channel, (0, 1));
  
  int res = ::wiringPiSPIGetFd(channel);
  
  SCOPE_CLOSE(INT32(res));
}

// Func : wiringPiSPIDataRW(int channel, unsigned char* data, int len)

IMPLEMENT(wiringPiSPIDataRW) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, channel);
  SET_ARGUMENT_NAME(1, data);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(2);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  CHECK_ARGUMENT_TYPE_NODE_BUFFER(1);
  
  int channel = GET_ARGUMENT_AS_INT32(0);
  char* data = node::Buffer::Data(args[1]->ToObject());
  int length = node::Buffer::Length(args[1]->ToObject());
  
  CHECK_ARGUMENT_IN_INTS(0, channel, (0, 1));
  
  int res = ::wiringPiSPIDataRW(channel, reinterpret_cast<unsigned char*>(data), length);
  
  SCOPE_CLOSE(INT32(res));
}

// Func : int wiringPiSPISetup(int channel, int speed)

IMPLEMENT(wiringPiSPISetup) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, channel);
  SET_ARGUMENT_NAME(1, speed);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(2);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  CHECK_ARGUMENT_TYPE_INT32(1);
  
  int channel = GET_ARGUMENT_AS_INT32(0);
  int speed = GET_ARGUMENT_AS_INT32(1);
  
  CHECK_ARGUMENT_IN_INTS(0, channel, (0, 1));
  
  int res = ::wiringPiSPISetup(channel, speed);
  
  SCOPE_CLOSE(INT32(res));
}

IMPLEMENT(wiringPiSPISetupMode) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, channel);
  SET_ARGUMENT_NAME(1, speed);
  SET_ARGUMENT_NAME(2, mode);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(3);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  CHECK_ARGUMENT_TYPE_INT32(1);
  CHECK_ARGUMENT_TYPE_INT32(2);
  
  int channel = GET_ARGUMENT_AS_INT32(0);
  int speed = GET_ARGUMENT_AS_INT32(1);
  int mode = GET_ARGUMENT_AS_INT32(2);
  
  CHECK_ARGUMENT_IN_INTS(0, channel, (0, 1));
  CHECK_ARGUMENT_IN_INTS(2, mode, (0, 1, 2, 3));
  
  int res = ::wiringPiSPISetupMode(channel, speed, mode);
  
  SCOPE_CLOSE(INT32(res));
}

IMPLEMENT_EXPORT_INIT(wiringPiSPI) {
  EXPORT_FUNCTION(wiringPiSPIGetFd);
  EXPORT_FUNCTION(wiringPiSPIDataRW);
  EXPORT_FUNCTION(wiringPiSPISetup);
  EXPORT_FUNCTION(wiringPiSPISetupMode);
}