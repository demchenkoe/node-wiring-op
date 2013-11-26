#include <node.h>
#include <v8.h>

#include <wiringPi.h>
#include <mcp23s17.h>

using namespace v8;

#define DECLARE(name) \
  static Handle<Value> name(const Arguments& args)
#define IMPLEMENT(name) \
  Handle<Value> wpi::name(const Arguments& args)
#define EXPORT(name)  \
  target->Set(String::NewSymbol(#name), \
  FunctionTemplate::New(wpi::name)->GetFunction())

namespace wpi {
  // Setup
  DECLARE(wiringPiSetup);
  DECLARE(wiringPiSetupGpio);
  DECLARE(wiringPiSetupSys);
  DECLARE(wiringPiSetupPhys);
  
  // Core wiringPi functions
  DECLARE(pinModeAlt);
  DECLARE(pinMode);
  DECLARE(pullUpDnControl);
  DECLARE(digitalRead);
  DECLARE(digitalWrite);
  DELCARE(pwmWrite);
  DECLARE(analogRead);
  DECLARE(analagoWrite);
  
  // PiFace specifics (Deprecated)
  //DECLARE(wiringPiSetupPiFace);
  //DECLARE(wiringPiSetupPiFaceForGpioProg); // Don't use this - for gpio program only
  
  // On-Board Rasberry Pi hardware specific stuff
  DECLARE(piBoardRev);
  DECLARE(wpiPinToGpio);
  DECLARE(physPinToGpio);
  DECLARE(setPadDrive);
  DECLARE(getAlt);
  DECLARE(digitalWriteByte);
  DECLARE(pwmSetMode);
  DECLARE(pwmSetRange);
  DECLARE(pwmSetClock);
  DECLARE(gpioClockSet);
  
  //MCP23S17
  DECLARE(mcp23s17Setup);
}

// === Setup ===

// Func : int wiringPiSetup(void)
// Returns : error code if v1 mode otherwise always returns 0
// Description : Initialises wiringPi and assumes that the calling program is going
// to be using the wiringPi pin numbering scheme.
// This is a simplified numbering scheme which provides a mapping from virtual 
// pin numbers 0 through 16 to the real underlying Broadcom GPIO pin numbers.
// see the pins page (https://projects.drogon.net/raspberry-pi/wiringpi/pins/) for a table
// which maps the wiringPi pin number to the Broadcom GPIO pin number to the physical location
// on the edge connector.
// This function needs to be called with root privileges.

IMPLEMENT(wiringPiSetup) {
  HandleScope scope;
  int res;

  // CHECK: Number of argument
  if (args.Length() != 0) {
    ThrowException(Exception::TypeError(
      String::New("Wrong number of arguments.")));
    return scope.Close(Undefined());
  }

  res = ::wiringPiSetup();

  return scope.Close(Int32::New(res));
}

// Func : int wiringPiSetupGpio(void)
// Returns : error code if v1 mode otherwise always returns 0
// Description : This is indential to above, however it allows the calling programs to use
// the Broadcom GPIO pin numbers directly with no re-mapping.
// As above, this function needs to be called with root privileges, and note that some pins
// are different from revision 1 to revision 2 boards.

IMPLEMENT(wiringPiSetupGpio) {
  HandleScope scope;
  int res;

  // CHECK: Number of argument
  if (args.Length() != 0) {
    ThrowException(Exception::TypeError(
      String::New("Wrong number of arguments.")));
    return scope.Close(Undefined());
  }

  res = ::wiringPiSetupGpio();

  return scope.Close(Int32::New(res));
}

// Func : int wiringPiSetupPhys(void)
// Returns : error code if v1 mode otherwise always returns 0
// Description : Identical to above, however it allows the calling programs to use 
// the physical pin numbers on the P1 connector only.
// As above, this function needs to be called with root priviliges.

IMPLEMENT(wiringPiSetupPhys) {
  HandleScope scope;
  int res;
  
  // CHECK: Number of argument
  if (args.Length() != 0) {
    ThrowException(Exception::TypeError(
      String::New("Wrong number of arguments.")));
    return scope.Close(Undefined());
  }
  
  res = ::wiringPiSetupPhys();
  
  return scope.Close(Int32::New(res));
}

// Func : int wiringPiSetupSys(void)
// Returns : error code if v1 mode otherwise always returns 0
// Description : This initialises wiringPi but uses the /sys/class/gpio interface rather than
// accessing the hardware directly. This can be called as a non-root user provided the GPIO pins
// have been exported before-hand using gpio program. Pin numbering in this mode is the native
// Broadcom GPIO numbers - the same as wiringPiSetGpio above, so be aware of the differences
// between Rev 1 and Rev 2 boards.
// Note: In this mode you can only use the pins which have been exported via the
// /sys/class/gpio interface before you run your program. You can do this in a seperate
// shell script, or by using the system() function from inside your program to call the gpio program.
// Also note that some functions have no effect when using this mode as they're not currently
// possible to action unless called with root privileges. (although you can use system() to call
// gpio to set/change modes if needed).

IMPLEMENT(wiringPiSetupSys) {
  HandleScope scope;
  int res;

  // CHECK: Number of argument
  if (args.Length() != 0) {
    ThrowException(Exception::TypeError(
      String::New("Wrong number of arguments.")));
    return scope.Close(Undefined());
  }

  res = ::wiringPiSetupSys();

  return scope.Close(Int32::New(res));
}

// === Core functions ===

// Func : void pinModeAlt(int pin, int mode)
// Description : This is an un-documented special to let you set any pin to any mode.
// Modes are WPI_MODE_PINS, WPI_MODE_PHYS, WPI_MODE_GPIO.

IMPLEMENT(pinModeAlt) {
  HandleScope scope;
  int pin;
  int mode;
  
  // CHECK: Number of argument
  if (args.Length() != 0) {
    ThrowException(Exception::TypeError(
      String::New("Wrong number of arguments.")));
    return scope.Close(Undefined());
  }
  
  // CHECK: Argument types
  if (!args[0]->IsNumber() || !args[1]->IsNumber()) {
    ThrowException(Exception::TypeError(
      String::New("Incorrect argument types. Numbers expected.")));
    return scope.Close(Undefined());
  }
  
  pin = args[0]->NumberValue();
  mode = args[1]->NumberValue();
  
  // CHECK: Allowed values
  if (mode != WPI_MODE_PINS && mode != WPI_MODE_PHYS && mode != WPI_MODE_GPIO) {
    ThrowException(Exception::TypeError(
      String::New("Incorrect mode value. WPI_MODE_PINS, WPI_MODE_PHYS or WPI_MODE_GPIO expected.")));
    return scope.Close(Undefined());
  }
  
  ::pinModeAlt(pin, mode);
  
  return scope.Close(Undefined());
}

// Func : void pinMode(int pin, int mode)
// Description : This sets the mode of a pin to either INPUT, OUTPUT, PWM_OUTPUT or GPIO_CLOCK.
// Note that only wiringPi pin 1 (BCM_GPIO 18) supports PWM output and only wiringPi pin 7 (BCM_GPIO 4)
// supports CLOCK output modes.
// This function has no effect when in Sys mode. If you need to change the pin mode, the you can
// do it with the gpio program in a script before you start your program.

IMPLEMENT(pinMode) {
  HandleScope scope;
  int mode;
  int pin;

  // CHECK: Number of argument
  if (args.Length() != 2) {
    ThrowException(Exception::TypeError(
      String::New("Wrong number of arguments.")));
    return scope.Close(Undefined());
  }

  // CHECK: Argument types
  if (!args[0]->IsNumber() || !args[1]->IsNumber()) {
    ThrowException(Exception::TypeError(
      String::New("Incorrect argument types. Numbers expected.")));
    return scope.Close(Undefined());
  }
  
  pin = args[0]->NumberValue();
  mode = args[1]->NumberValue();
  
  // CHECK: Allowed values
  if (mode != INPUT && mode != OUTPUT && mode != PWM_OUTPUT && mode != GPIO_CLOCK) {
    ThrowException(Exception::TypeError(
      String::New("Incorrect mode value. INPUT, OUTPUT, PWM_OUTPUT or GPIO_CLOCK expected.")));
    return scope.Close(Undefined());
  }

  ::pinMode(pin, mode);

  return scope.Close(Undefined());
}

// Func : void pullUpDnControl(int pin, int pud)
// Description : This sets the pull-up or pull-down resistor mode on the given pin, which should be set
// as an input. Unlike Arduino, the BCM2835 has both pull-up and down internal resistors.
// The parameter pud should be; PUD_OFF (no pull up/down), PUD_DOWN (pull to ground) or PUD_UP (pull to 3.3v).
// The internal pull up/down resistors have a value of approximately 50KΩ on the Raspberry Pi.

IMPLEMENT(pullUpDnControl) {
  HandleScope scope;
  int pin;
  int pud;
  
  // CHECK: Number of argument
  if (args.Length() != 2) {
    ThrowException(Exception::TypeError(
      String::New("Wrong number of arguments.")));
    return scope.Close(Undefined());
  }
  
  // CHECK: Argument types
  if (!args[0]->IsNumber() || !args[1]->IsNumber()) {
    ThrowException(Exception::TypeError(
      String::New("Incorrect argument types. Numbers expected.")));
    return scope.Close(Undefined());
  }
  
  pin = args[0]->NumberValue();
  pud = args[1]->NumberValue();
  
  // CHECK: Allowed values
  if (pud != PUD_OFF && pud != PUD_DOWN && pud != PUD_UP) {
    ThrowException(Exception::TypeError(
      String::New("Incorrect mode value. PUD_OFF, PUD_DOWN or PUD_UP expected.")));
    return scope.Close(Undefined());
  }
  
  ::pullUpDnControl(pin, pud);

  return scope.Close(Undefined());
}

// Func : int digitalRead(int pin)
// Description : This function returns the value read at the given pin. It will be HIGH or LOW (1 or 0)
// depending on the logic level at the pin.

IMPLEMENT(digitalRead) {
  HandleScope scope;
  int pin
  int res;

  // CHECK: Number of argument
  if (args.Length() != 1) {
    ThrowException(Exception::TypeError(
      String::New("Wrong number of arguments.")));
    return scope.Close(Undefined());
  }

  // CHECK: Argument types
  if (!args[0]->IsNumber()) {
    ThrowException(Exception::TypeError(
      String::New("Incorrect argument type. Number expected.")));
    return scope.Close(Undefined());
  }

  pin = args[0]->NumberValue();
  res = ::digitalRead(pin);
  
  // Make sure the function returns strictly 1 or 0
  // §4.7/4 from the C++ Standard says (Integral Conversion)
  // If the source type is bool, the value false is converted to zero and the value true is converted to one.
  res = (res != 0);

  return scope.Close(Int32::New(res));
}

// Func : void digitalWrite(int pin, int value)
// Description : Write the value HIGH or LOW (1 or 0) to the given pin which must have been
// previously set as an output.
// WiringPi treats any non-zero number as HIGH, however 0 is the only representation of LOW.

IMPLEMENT(digitalWrite) {
  HandleScope scope;
  int pin;
  int value;

  //CHECK: Number of argument
  if (args.Length() != 2) {
    ThrowException(Exception::TypeError(
      String::New("Wrong number of arguments.")));
    return scope.Close(Undefined());
  }

  //CHECK: Argument types
  if (!args[0]->IsNumber() || !args[1]->IsNumber()) {
    ThrowException(Exception::TypeError(
      String::New("Incorrect argument types. Numbers expected.")));
    return scope.Close(Undefined());
  }
  
  pin = args[0]->NumberValue();
  value = args[1]->NumberValue();
  
  // Make sure value is strictly 1 or 0
  // §4.7/4 from the C++ Standard says (Integral Conversion)
  // If the source type is bool, the value false is converted to zero and the value true is converted to one.
  value = (value != 0)

  ::digitalWrite(pin, value);

  return scope.Close(Undefined());
}

// Func : void pwmWrite(int pin, int value)
// Description : Writes the value to the PWM register for the given pin. The Raspberry Pi has
// one on-board PWM pin, pin 1 (BCM_GPIO 18, Phys 12) and the range is 0-1024. Other PWM
// devices may have other PWM ranges.
// This function is not able to control the Pi's on-board PWM when in Sys mode.

IMPLEMENT(pwmWrite) {
  HandleScope scope;
  int pin;
  int value;

  //CHECK: Number of argument
  if (args.Length() != 2) {
    ThrowException(Exception::TypeError(
      String::New("Wrong number of arguments.")));
    return scope.Close(Undefined());
  }

  //CHECK: Argument types
  if (!args[0]->IsNumber() || !args[1]->IsNumber()) {
    ThrowException(Exception::TypeError(
      String::New("Incorrect argument types. Numbers expected.")));
    return scope.Close(Undefined());
  }
  
  pin = args[0]->NumberValue();
  value = args[1]->NumberValue();

  ::pwmWrite(pin, value);

  return scope.Close(Undefined());
}

// Func : int analogRead(int pin)
// Description : This returns the value read on the supplied analog input pin. You will need to
// register additional analog modules to enable this function for device such as the Gertboard,
// quick2Wire analog board, etc.

IMPLEMENT(analogRead) {
  HandleScope scope;
  int pin;
  int res;
  
  //CHECK: Number of argument
  if (args.Length() != 1) {
    ThrowException(Exception::TypeError(
      String::New("Wrong number of arguments.")));
    return scope.Close(Undefined());
  }
  
  //CHECK: Argument types
  if (!args[0]->IsNumber()) {
    ThrowException(Exception::TypeError(
      String::New("Incorrect argument type. Number expected.")));
    return scope.Close(Undefined());
  }
  
  pin = args[0]->NumberValue();
  res = ::analogRead(pin);
  
  return scope.Close(Int32::New(res));
}

// Func : void analogWrite(int pin, int value)
// Description : This writes the given value to the supplied analog pin. You will need to register
// additional analog modules to enable this function for devices such as the Gertboard.

IMPLEMENT(analogWrite) {
  HandleScope scope;
  int pin;
  int value;
  
  //CHECK: Number of argument
  if (args.Length() != 2) {
    ThrowException(Exception::TypeError(
      String::New("Wrong number of arguments.")));
    return scope.Close(Undefined());
  }
  
  //CHECK: Argument types
  if (!args[0]->IsNumber() || !args[1]->IsNumber()) {
    ThrowException(Exception::TypeError(
      String::New("Incorrect argument type. Number expected.")));
    return scope.Close(Undefined());
  }
  
  pin = args[0]->NumberValue();
  value = args[1]->NumberValue();
  
  ::analogWrite(pin, value);
  
  return scope.Close(Undefined());
}

// === Raspberry Pi specific ===

// Func : int piBoardRev(void)
// Description : This returns the board revision of the Raspberry Pi. It will be either 1 or 2.
// Some of the BCM_GPIO pins changed number and function when moving from board revision 1 to 2,
// so if you are using BCM_GPIO pin numbers, then you need to be aware of the differences.

IMPLEMENT(piBoardRev) {
  HandleScope scope;
  int res;

  //CHECK: Number of argument
  if (args.Length() != 0) {
    ThrowException(Exception::TypeError(
      String::New("Wrong number of arguments.")));
    return scope.Close(Undefined());
  }

  res = ::piBoardRev();

  return scope.Close(Int32::New(res));
}

// Func : int wpiPinToGpio(int wpiPin)
// Description : This returns the BCM_GPIO pin number of the supplied wiringPi pin.
// It takes the board revision into account.

IMPLEMENT(wpiPinToGpio) {
  HandleScope scope;
  int wpiPin;
  int res;
  
  //CHECK: Number of argument
  if (args.Length() != 1) {
    ThrowException(Exception::TypeError(
      String::New("Wrong number of arguments.")));
    return scope.Close(Undefined());
  }
  
  //CHECK: Argument types
  if (!args[0].IsNumber()) {
    ThrowException(Exception::TypeError(
      String::New("Incorrect argument type. Number expected.")));
    return scope.Close(Undefined());
  }
  
  wpiPin = args[0]->NumberValue();
  res = ::wpiPinToGpio(wpiPin);
  
  return scope.Close(Int32::New(res));
}

// Func : int physPinToGpio (int physPin)
// Description : This returns the BCM_GPIO pin number of the suppled physical pin on the P1 connector.

IMPLEMENT(physPinToGpio) {
  HandleScope scope;
  int physPin;
  int res;
  
  //CHECK: Number of argument
  if (args.Length() != 1) {
    ThrowException(Exception::TypeError(
      String::New("Wrong number of arguments.")));
    return scope.Close(Undefined());
  }
  
  //CHECK: Argument types
  if (!args[0].IsNumber()) {
    ThrowException(Exception::TypeError(
      String::New("Incorrect argument type. Number expected.")));
    return scope.Close(Undefined());
  }
  
  physPin = args[0]->NumberValue();
  res = ::physPinToGpio(physPin);
  
  return scope.Close(Int32::New(res));
}

// Func : void setPadDrive(int group, int value)
// Description : This sets the "strength" of the pad drivers for a particular group of pins.
// There are 3 groups of pins and the drive strength is from 0 to 7. Do not use the unless you
// know what you are doing.

IMPLEMENT(setPadDrive) {
  HandleScope scope;
  int group;
  int value;
  
  //CHECK: Number of argument
  if (args.Length() != 2) {
    ThrowException(Exception::TypeError(
      String::New("Wrong number of arguments.")));
    return scope.Close(Undefined());
  }
  
  //CHECK: Argument types
  if (!args[0]->IsNumber() || !args[1]->IsNumber()) {
    ThrowException(Exception::TypeError(
      String::New("Incorrect argument type. Number expected.")));
    return scope.Close(Undefined());
  }
  
  group = args[0]->NumberValue();
  value = args[1]->NumberValue();
  ::setPadDrive(group, value);
  
  return scope.Close(Undefined());
}

// Func : int getAlt(int pin)
// Description : Returns the ALT bits for a given port. Only really of-use
// for the gpio readall command (I think).

IMPLEMENT(getAlt) {
  HandleScope scope;
  int pin;
  int res;
  
  //CHECK: Number of argument
  if (args.Length() != 1) {
    ThrowException(Exception::TypeError(
      String::New("Wrong number of arguments.")));
    return scope.Close(Undefined());
  }

  //CHECK: Argument types
  if (!args[0]->IsNumber()) {
    ThrowException(Exception::TypeError(
      String::New("Incorrect argument type. Number expected.")));
    return scope.Close(Undefined());
  }
  
  pin = args[0]->NumberValue();
  res = ::getAlt(pin);
  
  return scope.Close(Int32::New(res));
}

// Func : void digitalWriteByte(int value)
// Description : This writes the 8-bit byte supplied to the first 8 GPIO pins. 
// It’s the fastest way to set all 8 bits at once to a particular value, although it still takes 
// two write operations to the Pi’s GPIO hardware.

IMPLEMENT(digitalWriteByte) {
  HandleScope scope;
  int value;
  
  //CHECK: Number of argument
  if (args.Length() != 1) {
    ThrowException(Exception::TypeError(
      String::New("Wrong number of arguments.")));
    return scope.Close(Undefined());
  }

  //CHECK: Argument types
  if (!args[0]->IsNumber()) {
    ThrowException(Exception::TypeError(
      String::New("Incorrect argument type. Number expected.")));
    return scope.Close(Undefined());
  }
  
  value = args[0]->NumberValue();
  ::digitalWriteByte(value);
  
  return scope.Close(Undefined());
}

// Func : void pwmSetMode(int mode)
// Description : The PWM generator can run in 2 modes – “balanced” and “mark:space”. 
// The mark:space mode is traditional, however the default mode in the Pi is “balanced”. 
// You can switch modes by supplying the parameter: PWM_MODE_BAL or PWM_MODE_MS.

IMPLEMENT(pwmSetMode) {
  HandleScope scope;
  int mode;
  
  //CHECK: Number of argument
  if (args.Length() != 1) {
    ThrowException(Exception::TypeError(
      String::New("Wrong number of arguments.")));
    return scope.Close(Undefined());
  }

  //CHECK: Argument types
  if (!args[0]->IsNumber()) {
    ThrowException(Exception::TypeError(
      String::New("Incorrect argument type. Number expected.")));
    return scope.Close(Undefined());
  }
  
  mode = args[0]->NumberValue();
  
  //CHECK: Allowed values
  if (mode != PWM_MODE_BAL && mode != PWM_MODE_MS) {
    ThrowException(Exception::TypeError(
      String::New("Incorrect mode value. PWM_MODE_BAL or PWM_MODE_MS expected.")));
    return scope.Close(Undefined());
  }
  
  ::pwmSetMode(mode);
  
  return scope.Close(Undefined());
}

// Func : void pwmSetRange(unsigned int range)
// Description : This sets the range register in the PWM generator. The default is 1024.
// Note: The PWM control functions can not be used when in Sys mode. To understand more about 
// the PWM system, you’ll need to read the Broadcom ARM peripherals manual.

IMPLEMENT(pwmSetRange) {
  HandleScope scope;
  unsigned int range;

  //CHECK: Number of argument
  if (args.Length() != 1) {
    ThrowException(Exception::TypeError(
      String::New("Wrong number of arguments.")));
    return scope.Close(Undefined());
  }

  //CHECK: Argument types
  if (!args[0]->IsNumber()) {
    ThrowException(Exception::TypeError(
      String::New("Incorrect argument type. Number expected.")));
    return scope.Close(Undefined());
  }
  
  range = args[0]->Uint32Value();
  ::pwmSetRange(range);

  return scope.Close(Undefined());
}

// Func : void pwmSetClock(int divisor)
// Description : This sets the divisor for the PWM clock.
// Note: The PWM control functions can not be used when in Sys mode. To understand more about 
// the PWM system, you’ll need to read the Broadcom ARM peripherals manual.

IMPLEMENT(pwmSetClock) {
  HandleScope scope;
  int divisor;

  //CHECK: Number of argument
  if (args.Length() != 1) {
    ThrowException(Exception::TypeError(
      String::New("Wrong number of arguments.")));
    return scope.Close(Undefined());
  }

  //CHECK: Argument types
  if (!args[0]->IsNumber()) {
    ThrowException(Exception::TypeError(
      String::New("Incorrect argument type. Number expected.")));
    return scope.Close(Undefined());
  }

  divisor = args[0]->NumberValue();
  ::pwmSetClock(divisor);

  return scope.Close(Undefined());
}

// Func : void gpioClockSet(int pin, int freq)
// Description : Set the frequency on a GPIO clock pin

IMPLEMENT(gpioClockSet) {
  HandleScope scope;
  int pin;
  int freq;
  
  //CHECK: Number of argument
  if (args.Length() != 2) {
    ThrowException(Exception::TypeError(
      String::New("Wrong number of arguments.")));
    return scope.Close(Undefined());
  }
  
  //CHECK: Argument types
  if (!args[0]->IsNumber() || !args[1]->IsNumber()) {
    ThrowException(Exception::TypeError(
      String::New("Incorrect argument type. Number expected.")));
    return scope.Close(Undefined());
  }
  
  pin = args[0]->NumberValue();
  freq = args[1]->NumberValue();
  ::gpioClockSet(pin, freq);
  
  return scope.Close(Undefined());
}

// === MCP23S17 ===

// Func : int mcp23s17Setup(int pinBase, int spiPort, int devId)
// Description : Initialise libWiringPi to be used with MCP23S17
// pinBase is any number above 64 that doesn’t clash with any other wiringPi expansion module, 
// spiPort is 0 or 1 for one of the two SPI ports on the Pi and devId is the ID of that MCP23s17 on the SPI port.

IMPLEMENT(mcp23s17Setup) {
  HandleScope scope;
  int pinBase;
  int spiPort;
  int devId;
  int res;
  
  //CHECK: Number of argument
  if (args.Length() != 3) {
    ThrowException(Exception::TypeError(
      String::New("Wrong number of arguments.")));
    return scope.Close(Undefined());
  }
  
  //CHECK: Argument types
  if (!args[0]->IsNumber() || !args[1]->IsNumber() || !args[2]->IsNumber) {
    ThrowException(Exception::TypeError(
      String::New("Incorrect argument type. Number expected.")));
    return scope.Close(Undefined());
  }
  
  pinBase = args[0]->NumberValue();
  spiPort = args[1]->NumberValue();
  devId = args[2]->NumberValue();
  
  //CHECK: Allowed values
  if (pinBase <= 64) {
    ThrowException(Exception::TypeError(
      String::New("Incorrect pinBase value. >64 expected.")));
    return scope.Close(Undefined());
  }
  
  if (spiPort != 0 && spiPort != 1) {
    ThrowException(Exception::TypeError(
      String::New("Incorrect spiPort value. 0 or 1 expected.")));
    return scope.Close(Undefined());
  }
  
  res = ::mcp23s17Setup(pinBase, spiPort, devId);
  
  return scope.Close(Int32::New(res));
}

void init(Handle<Object> target) {
  // Setup
  EXPORT(wiringPiSetup);
  EXPORT(wiringPiSetupGpio);
  EXPORT(wiringPiSetupSys);
  EXPORT(wiringPiSetupPhys);
  
  // Core wiringPi functions
  EXPORT(pinModeAlt);
  EXPORT(pinMode);
  EXPORT(pullUpDnControl);
  EXPORT(digitalRead);
  EXPORT(digitalWrite);
  EXPORT(pwmWrite);
  EXPORT(analogRead);
  EXPORT(analagoWrite);
  
  // PiFace specifics (Deprecated)
  //EXPORT(wiringPiSetupPiFace);
  //EXPORT(wiringPiSetupPiFaceForGpioProg); // Don't use this - for gpio program only
  
  // On-Board Rasberry Pi hardware specific stuff
  EXPORT(piBoardRev);
  EXPORT(wpiPinToGpio);
  EXPORT(physPinToGpio);
  EXPORT(setPadDrive);
  EXPORT(getAlt);
  EXPORT(digitalWriteByte);
  EXPORT(pwmSetMode);
  EXPORT(pwmSetRange);
  EXPORT(pwmSetClock);
  EXPORT(gpioClockSet);
  
  //MCP23S17
  EXPORT(mcp23s17Setup);
}
NODE_MODULE(wiringPi, init)
