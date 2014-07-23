# Install

```
npm install wiring-pi
```

# Usage

```javascript
var wpi = require('wiring-pi');
```

# APIs

## Setup

### wiringPiSetup()
<span class="api-info"><code> >= 0.1.0 </code></span>

Initialises wiringPi and assumes that the calling program is going to be using the wiringPi pin numbering scheme.

This is a simplified numbering scheme which provides a mapping from virtual pin numbers 0 through 16 to the real underlying Broadcom GPIO pin numbers.

see the [pins](http://wiringpi.com/pins/) page for a table which maps the wiringPi pin number to the Broadcom GPIO pin number to the physical location on the edge connector.

This function needs to be called with root privileges.

### wiringPiSetupGpio()
<span class="api-info"><code> >= 0.1.1 </code></span>

This is indential to above, however it allows the calling programs to use the Broadcom GPIO pin numbers directly with no re-mapping.

As above, this function needs to be called with root privileges, and note that some pins are different from revision 1 to revision 2 boards.

### wiringPiSetupPhys()
<span class="api-info"><code> >= 1.0.0 </code></span>

Identical to above, however it allows the calling programs to use the physical pin numbers on the P1 connector only.

As above, this function needs to be called with root priviliges.

### wiringPiSetupSys()
<span class="api-info"><code> >= 0.1.1 </code></span>

This initialises wiringPi but uses the /sys/class/gpio interface rather than accessing the hardware directly.

This can be called as a non-root user provided the GPIO pins have been exported before-hand using gpio program.

Pin numbering in this mode is the native Broadcom GPIO numbers - the same as wiringPiSetGpio above, so be aware of the differences between Rev 1 and Rev 2 boards.

**NOTE: In this mode you can only use the pins which have been exported via the /sys/class/gpio interface before you run your program.**

**You can do this in a seperate shell script, or by using the system() function from inside your program to call the gpio program.**

**Also note that some functions have no effect when using this mode as they're not currently possible to action unless called with root privileges. (although you can use system() to call gpio to set/change modes if needed).**

### setup(mode)
<span class="api-info"><code> >= 0.1.1 </code></span>

An handy function to setup wiringPi

`mode` can be one of the following values:

* `wpi`: sets up pin numbering with wiringPiSetup
  <span class="api-info-list"><code> >= 0.1.1 </code></span>
* `gpio`: sets up pin numbering with wiringPiSetupGpio
  <span class="api-info-list"><code> >= 0.1.1 </code></span>
* `sys`: sets up pin numbering with wiringPiSetupSys
  <span class="api-info-list"><code> >= 0.1.1 </code></span>
* `phys`: sets up pin numbering with wiringPiSetupPhys
  <span class="api-info-list"><code> >= 1.0.0 </code></span>

More info about pin numbering systems at [wiringpi.com/pins/](http://wiringpi.com/pins/)

**NOTE: `>= 2.0.0` no longer accept calling setup without mode specified. (defaulting to `wpi` in `< 2.0.0`)**

---

## Core functions

### pinModeAlt(pin, mode)
<span class="api-info"><code> >= 1.0.0 </code></span>

This is an un-documented special to let you set any pin to any mode.

`mode` can be one of the following values:

* `WPI_MODE_PINS`
  <span class="api-info-list"><code> >= 1.0.0 </code></span>
* `WPI_MODE_PHYS`
  <span class="api-info-list"><code> >= 1.0.0 </code></span>
* `WPI_MODE_GPIO`
  <span class="api-info-list"><code> >= 1.0.0 </code></span>
  
### pinMode(pin, mode)
<span class="api-info"><code> >= 0.1.0 </code></span>

This sets the mode of a pin.

Note that only wiringPi pin 1 (BCM_GPIO 18) supports PWM output and only wiringPi pin 7 (BCM_GPIO 4) supports CLOCK output modes.

This function has no effect when in Sys mode.

If you need to change the pin mode, the you can do it with the gpio program in a script before you start your program.

`mode` can be one of the following values:

* `modes.INPUT`
  <span class="api-info-list"><code> >= 0.1.1 < 2.0.0 </code><code class="api-info-removed">removed</code></span>
* `modes.OUTPUT`
  <span class="api-info-list"><code> >= 0.1.1 < 2.0.0 </code><code class="api-info-removed">removed</code></span>
* `modes.PWM_OUTPUT`
  <span class="api-info-list"><code> >= 0.1.1 < 2.0.0 </code><code class="api-info-removed">removed</code></span>
* `modes.GPIO_CLOCK`
  <span class="api-info-list"><code> >= 0.1.1 < 2.0.0 </code><code class="api-info-removed">removed</code></span>
* `INPUT`
  <span class="api-info-list"><code> >= 1.0.0 </code></span>
* `OUTPUT`
  <span class="api-info-list"><code> >= 1.0.0 </code></span>
* `PWM_OUTPUT`
  <span class="api-info-list"><code> >= 1.0.0 </code></span>
* `GPIO_CLOCK`
  <span class="api-info-list"><code> >= 1.0.0 </code></span>
* `SOFT_PWM_OUTPUT`
  <span class="api-info-list"><code> >= 1.1.0 </code></span>
* `SOFT_TONE_OUTPUT`
  <span class="api-info-list"><code> >= 1.1.0 </code></span>
  
### pullUpDnControl(pin, pud)
<span class="api-info"><code> >= 0.2.0 </code></span>

This sets the pull-up or pull-down resistor mode on the given pin, which should be set as an input.

Unlike Arduino, the BCM2835 has both pull-up and down internal resistors.

The internal pull up/down resistors have a value of approximately 50KΩ on the Raspberry Pi.

`pud` can be one of the following values:

* `PUD_OFF` *no pull up/down*
<span class="api-info-list"><code> >= 0.2.0 </code></span>
* `PUD_DOWN` *pull to ground*
<span class="api-info-list"><code> >= 0.2.0 </code></span>
* `PUD_UP` *pull to 3.3v*
<span class="api-info-list"><code> >= 0.2.0 </code></span>
  
### digitalRead(pin)
<span class="api-info"><code> >= 0.1.1 </code></span>

This function returns the value read at the given pin.

It will be `HIGH` (1) or `LOW` (0) depending on the logic level at the pin.

### digitalWrite(pin, state)
<span class="api-info"><code> >= 0.1.0 </code></span>

Write the value `HIGH` (1) or `LOW` (0) to the given pin which must have been previously set as an output.

WiringPi treats any non-zero number as `HIGH`, however 0 is the only representation of `LOW`.

`state` can be one of the following value:

* `HIGH`
  <span class="api-info-list"><code> >= 0.1.2 </code></span>
* `LOW`
  <span class="api-info-list"><code> >= 0.1.2 </code></span>

### pwmWrite(pin, value)
<span class="api-info"><code> >= 0.1.1 </code></span>

Writes the value to the PWM register for the given pin.

The Raspberry Pi has one on-board PWM pin, pin 1 (BCM_GPIO 18, Phys 12) and the range is [0, 1024].

Other PWM devices may have other PWM ranges.

This function is not able to control the Pi's on-board PWM when in Sys mode.

### analogRead(pin)
<span class="api-info"><code> >= 1.0.0 </code></span>

This returns the value read on the supplied analog input pin.

You will need to register additional analog modules to enable this function for device such as the Gertboard, quick2Wire analog board, etc.

### analogWrite(pin, value)
<span class="api-info"><code> >= 1.0.0 </code></span>

This writes the given value to the supplied analog pin.

You will need to register additional analog modules to enable this function for devices such as the Gertboard.

### pulseIn(pin, state)
<span class="api-info"><code> >= 1.1.0 </code></span>

Reads a pulse (either HIGH or LOW) on a pin.

For example, if `state` is HIGH, pulseIn waits for the pin to go HIGH, starts timing, then waits for the pin to go LOW and stops timing.

Returns the length of the pulse in microseconds.

Gives up and returns 0 if no pulse starts within a specified time out.

`state` can be one of the following values:

* `HIGH`
  <span class="api-info-list"><code> >= 0.1.2 </code></span>
* `LOW`
  <span class="api-info-list"><code> >= 0.1.2 </code></span>
  
### delay(milliseconds)
<span class="api-info"><code> >= 1.1.0 </code></span>

Pauses the program for the amount of time (in miliseconds) specified as parameter.

There are 1000 milliseconds in a second.

### delayMicroseconds(microseconds)
<span class="api-info"><code> >= 1.1.0 </code></span>

Pauses the program for the amount of time (in microseconds) specified as parameter.

There are a thousand microseconds in a millisecond, and a million microseconds in a second.

For delays longer than a few thousand microseconds, you should use delay() instead.

### millis()
<span class="api-info"><code> >= 1.1.0 </code></span>

Returns the number of milliseconds since the beginning running of the current program

### micros()
<span class="api-info"><code> >= 1.1.0 </code></span>

Returns the number of microseconds since the beginning running of the current program

---

## Interrupts

### wiringPiISR(pin, edgeType, callback)
<span class="api-info"><code> >= 2.0.0 </code></span>

This function registers a function to received interrupts on the specified pin.

The edgeType parameter is either `INT_EDGE_FALLING`, `INT_EDGE_RISING`, `INT_EDGE_BOTH` or `INT_EDGE_SETUP`.

If it is `INT_EDGE_SETUP` then no initialisation of the pin will happen – it’s assumed that you have already setup the pin elsewhere (e.g. with the gpio program), but if you specify one of the other types, then the pin will be exported and initialised as specified.

This is accomplished via a suitable call to the gpio utility program, so it need to be available.

The pin number is supplied in the current mode – native wiringPi, BCM_GPIO, physical or Sys modes.

This function will work in any mode, and does not need root privileges to work.

The callback will be called when the interrupt triggers.

When it is triggered, it’s cleared in the dispatcher before calling your function, so if a subsequent interrupt fires before you finish your handler, then it won’t be missed.

However it can only track one more interrupt, if more than one interrupt fires while one is being handled then they will be ignored.

```javascript
wpi.setup('wpi');
wpi.pinMode(7, wpi.INPUT);
wpi.pullUpDnControl(7, wpi.PUD_UP);
wpi.wiringPiISR(7, wpi.INT_EDGE_FALLING, function(delta) {
  console.log('Pin 7 changed to LOW (', delta, ')');
});
```

---

## Raspberry Pi hardware specific functions

### piBoardRev()
<span class="api-info"><code> >= 0.1.1 </code></span>

This returns the board revision of the Raspberry Pi.

It will be either 1 or 2.

Some of the BCM_GPIO pins changed number and function when moving from board revision 1 to 2, so if you are using BCM_GPIO pin numbers, then you need to be aware of the differences.

### piBoardId()
<span class="api-info"><code> >= 1.1.0 </code></span>

Do more digging into the board revision string as above, but return as much details as we can.

Returns an object with the following keys:

* `model`: indexes to `PI_MODEL_NAMES` string table
* `rev`: indexes to `PI_REVISION_NAMES` string table
* `mem`: 256 or 512
* `maker`: indexes to `PI_MAKER_NAMES` string table
* `overvolted`: 0 or 1
  <span class="api-info-list"><code> >= 2.0.0 </code></span>

**NOTE: `maker` was a string in versions >= 1.1.0 and < 2.0.0**

Indexes of each string table have corresponding constants

* `PI_MODEL_NAME`
  * `PI_MODEL_UNKNOWN`
  <span class="api-info-list"><code> >= 2.0.0 </code></span>
  * `PI_MODEL_A`
  <span class="api-info-list"><code> >= 1.1.0 </code></span>
  * `PI_MODEL_B`
  <span class="api-info-list"><code> >= 1.1.0 </code></span>
  * `PI_MODEL_BP`
  <span class="api-info-list"><code> >= 2.0.0 </code></span>
  * `PI_MODEL_CM`
  <span class="api-info-list"><code> >= 1.1.1 </code></span>


* `PI_REVISION_NAMES`
  * `PI_VERSION_UNKNOWN`
  <span class="api-info-list"><code> >= 2.0.0 </code></span>
  * `PI_VERSION_1`
  <span class="api-info-list"><code> >= 2.0.0 </code></span>
  * `PI_VERSION_1_1`
  <span class="api-info-list"><code> >= 2.0.0 </code></span>
  * `PI_VERSION_1_2`
  <span class="api-info-list"><code> >= 2.0.0 </code></span>
  * `PI_VERSION_2`
  <span class="api-info-list"><code> >= 2.0.0 </code></span>

* `PI_MAKER_NAMES`
  * `PI_MAKER_UNKNOWN`
  <span class="api-info-list"><code> >= 2.0.0 </code></span>
  * `PI_MAKER_EGOMAN`
  <span class="api-info-list"><code> >= 2.0.0 </code></span>
  * `PI_MAKER_SONY`
  <span class="api-info-list"><code> >= 2.0.0 </code></span>
  * `PI_MAKER_QISDA`
  <span class="api-info-list"><code> >= 2.0.0 </code></span>

### wpiPinToGpio(pin)
<span class="api-info"><code> >= 1.0.0 </code></span>

This returns the BCM_GPIO pin number of the supplied wiringPi pin.

It takes the board revision into account.

### physPinToGpio(pin)
<span class="api-info"><code> >= 1.0.0 </code></span>

This returns the BCM_GPIO pin number of the suppled physical pin on the P1 connector.

### setPadDrive(group, value)
<span class="api-info"><code> >= 1.0.0 </code></span>

This sets the "strength" of the pad drivers for a particular group of pins.

There are 3 groups of pins and the drive strength is from 0 to 7.

**NOTE: Do not use the unless you know what you are doing.**

### getAlt(pin)
<span class="api-info"><code> >= 1.0.0 </code></span>

Returns the ALT bits for a given port.

### digitalWriteByte(byte)
<span class="api-info"><code> >= 1.0.0 </code></span>

This writes the 8-bit byte supplied to the first 8 GPIO pins.

It’s the fastest way to set all 8 bits at once to a particular value, although it still takes two write operations to the Pi’s GPIO hardware.

### pwmSetMode(mode)
<span class="api-info"><code> >= 1.0.0 </code></span>

The PWM generator can run in 2 modes – “balanced” and “mark:space”.

The mark:space mode is traditional, however the default mode in the Pi is “balanced”.

`mode` can be one of the following values:

* `PWM_MODE_BAL` *balanced*
* `PWM_MODE_MS` *mark:space*
  
### pwmSetRange(range)
<span class="api-info"><code> >= 0.1.1 </code></span>

This sets the range register in the PWM generator.

The default is 1024.

**NOTE: The PWM control functions can not be used when in Sys mode. To understand more about the PWM system, you’ll need to read the Broadcom ARM peripherals manual.**

### pwmSetClock(divisor)
<span class="api-info"><code> >= 0.1.1 </code></span>

This sets the divisor for the PWM clock.

**NOTE: The PWM control functions can not be used when in Sys mode. To understand more about the PWM system, you’ll need to read the Broadcom ARM peripherals manual.**

### gpioClockSet(pin, frequency)
<span class="api-info"><code> >= 1.0.0 </code></span>

Set the frequency on a GPIO clock pin

---

## I2C

### wiringPiI2CSetup(devId)
<span class="api-info"><code> >= 2.0.0 </code></span>

This initialises the I2C system with your given device identifier.

The ID is the I2C number of the device and you can use the i2cdetect program to find this out.

wiringPiI2CSetup() will work out which revision Raspberry Pi you have and open the appropriate device in /dev.

The return value is the standard Linux filehandle, or -1 if any error – in which case, you can consult errno as usual.

### wiringPiI2CSetupInterface(device, devId)
<span class="api-info"><code> >= 2.0.0 </code></span>

Undocumented access to set the interface explicitly - might be used for the Pi's 2nd I2C interface...

### wiringPiI2CRead(fd)
<span class="api-info"><code> >= 2.0.0 </code></span>

Simple device read.

Some devices present data when you read them without having to do any register transactions.

### wiringPiI2CReadReg8(fd, reg)
<span class="api-info"><code> >= 2.0.0 </code></span>

This read an 8-bit value from the device register indicated.

### wiringPiI2CReadReg16(fd, red)
<span class="api-info"><code> >= 2.0.0 </code></span>

This read an 16-bit value from the device register indicated.

### wiringPiI2CWrite(fd, data)
<span class="api-info"><code> >= 2.0.0 </code></span>

Simple device write.

Some devices accept data this way without needing to access any internal registers.

### wiringPiI2CWriteReg8(fd, reg, data)
<span class="api-info"><code> >= 2.0.0 </code></span>

This write an 8-bit data value into the device register indicated.

### wiringPiI2CWriteReg16(fd, reg, data)
<span class="api-info"><code> >= 2.0.0 </code></span>

This write an 16-bit data value into the device register indicated.

---

## SPI

### wiringPiSPIGetFd(channel)
<span class="api-info"><code> >= 1.0.0 </code></span>

Returns the file-descriptor for the given channel

### wiringPiSPIDataRW(channel, data)
<span class="api-info"><code> >= 1.0.0 </code></span>

This performs a simultaneous write/read transaction over the selected SPI bus.

Data that was in your buffer is overwritten by data returned from the SPI bus.

It is possible to do simple read and writes over the SPI bus using the standard read() and write() system calls though – write() may be better to use for sending data to chains of shift registers, or those LED strings where you send RGB triplets of data.

Devices such as A/D and D/A converters usually need to perform a concurrent write/read transaction to work.

### wiringPiSPISetup(channel, speed)
<span class="api-info"><code> >= 1.0.0 </code></span>

This is the way to initialise a channel (The Pi has 2 channels; 0 and 1).

The speed parameter is an integer in the range 500,000 through 32,000,000 and represents the SPI clock speed in Hz.

The returned value is the Linux file-descriptor for the device, or -1 on error.

If an error has happened, you may use the standard errno global variable to see why.

---

## Serial

### serialOpen(device, baudrate)
<span class="api-info"><code> >= 1.0.0 </code></span>

This opens and initialises the serial device and sets the baud rate.

It sets the port into “raw” mode (character at a time and no translations), and sets the read timeout to 10 seconds.

The return value is the file descriptor or -1 for any error, in which case errno will be set as appropriate.

**NOTE: The file descriptor (fd) returned is a standard Linux file descriptor.**

**You can use the standard read(), write(), etc. system calls on this file descriptor as required.** 

**E.g. you may wish to write a larger block of binary data where the serialPutchar() or serialPuts() function may not be the most appropriate function to use, in which case, you can use write() to send the data.**

### serialClose(fd)
<span class="api-info"><code> >= 1.0.0 </code></span>

Closes the device identified by the file descriptor given.

### serialFlush(fd)
<span class="api-info"><code> >= 1.0.0 </code></span>

This discards all data received, or waiting to be send down the given device.

### serialPutchar(fd, character)
<span class="api-info"><code> >= 1.0.0 </code></span>

Sends the single byte to the serial device identified by the given file descriptor.

### serialPuts(fd, string)
<span class="api-info"><code> >= 1.0.0 </code></span>

Sends the nul-terminated string to the serial device identified by the given file descriptor.

### serialPrintf(fd, string)
<span class="api-info">
  <code>Alias: serialPuts</code>
  <code> >= 2.0.0 </code>
</span>

### serialDataAvail(fd)
<span class="api-info"><code> >= 1.0.0 </code></span>

Returns the number of characters available for reading, or -1 for any error condition, in which case errno will be set appropriately.

### serialGetchar(fd)
<span class="api-info"><code> >= 1.0.0 </code></span>

Returns the next character available on the serial device.

This call will block for up to 10 seconds if no data is available (when it will return -1)

---

## Shift

### shiftIn(dPin, cPin, order)
<span class="api-info"><code> >= 1.0.0 </code></span>

This shifts an 8-bit data value in with the data appearing on the dPin and the clock being sent out on the cPin.

Order is either `LSBFIRST` or `MSBFIRST`.

The data is sampled after the cPin goes high. (So cPin high, sample data, cPin low, repeat for 8 bits) The 8-bit value is returned by the function.

### shiftOut(dPin, cPin, order, value)
<span class="api-info"><code> >= 1.0.0 </code></span>

The shifts an 8-bit data value val out with the data being sent out on dPin and the clock being sent out on the cPin.

Order is as above.

Data is clocked out on the rising or falling edge – ie. dPin is set, then cPin is taken high then low – repeated for the 8 bits.

---

## Soft PWM

### softPwmCreate(pin, value, range)
<span class="api-info"><code> >= 1.0.0 </code></span>

This creates a software controlled PWM pin.

You can use any GPIO pin and the pin numbering will be that of the wiringPiSetup() function you used.

Use 100 for the pwmRange, then the value can be anything from 0 (off) to 100 (fully on) for the given pin.

The return value is 0 for success.

Anything else and you should check the global errno variable to see what went wrong.

**NOTE: Each “cycle” of PWM output takes 10mS with the default range value of 100, so trying to change the PWM value more than 100 times a second will be futile.**

**NOTE: Each pin activated in softPWM mode uses approximately 0.5% of the CPU.**

**NOTE: You need to keep your program running to maintain the PWM output!**

### `softPwmWrite(pin, value)`
<span class="api-info"><code> >= 1.0.0 </code></span>

This updates the PWM value on the given pin.

The value is checked to be in-range and pins that haven’t previously been initialised via softPwmCreate will be silently ignored.

### `softPwmStop(pin)`
<span class="api-info"><code> >= 1.1.0 </code></span>

---

## Soft Servo

### `softServoWrite(pin, value)`
<span class="api-info"><code> >= 1.0.0 </code></span>

### `softServoSetup(p0, p1, p2, p3, p4, p5, p6, p7)`
<span class="api-info"><code> >= 1.0.0 </code></span>

---

## Soft Tone

### `softToneCreate(pin);`
<span class="api-info"><code> >= 1.0.0 </code></span>

This creates a software controlled tone pin.

You can use any GPIO pin and the pin numbering will be that of the wiringPiSetup() function you used.

The return value is 0 for success.

Anything else and you should check the global errno variable to see what went wrong.

**NOTE: Each pin activated in softTone mode uses approximately 0.5% of the CPU.**

**NOTE: You need to keep your program running to maintain the sound output!**

### `softToneWrite(pin, frequency);`
<span class="api-info"><code> >= 1.0.0 </code></span>

This updates the tone frequency value on the given pin.

The tone will be played until you set the frequency to 0.

### `softToneStop(pin);`
<span class="api-info"><code> >= 1.1.0 </code></span>

---

## Extensions

### drcSerial

#### `drcSetupSerial(pinBase, numPins, device, baudrate)`

### max31855

Cold-junction compensated thermocouple-to-digital converter (SPI)

### max5322

12-Bit DAC (SPI)

#### `max31855Setup(pinBase, spiChannel)`

### mcp23008

8-Bit I/O expander (I2C)

#### `mcp23008Setup(pinBase, i2cAddress)`

### mcp23016

16-Bit I/O expander (I2C)

#### `mcp23016Setup(pinBase, i2cAddress)`

### mpc23017

16-Bit I/O expander (I2C)

#### `mcp23017Setup(pinBase, i2cAddress)`

### mcp23s08

8-Bit I/O expander (SPI)

#### `mcp23s08Setup(pinBase, spiChannel, devId)`

### mcp23s17

16-Bit I/O expander (SPI)

#### `mcp23s17Setup(pinBase, spiChannel, devId)`

### mcp3002

2-Channel 10-Bit ADC (SPI)

#### `mcp3002Setup(pinBase, spiChannel)`

### mcp3004/8

4/8-Channel 10-Bit ADC (SPI)

#### `mcp3004Setup(pinBase, spiChannel)`

### mcp3422/3/4

2/4-Channel 18-Bit ADC (I2C)

#### `mcp3422Setup(pinBase, i2cAddress, sampleRate, gain)`

### mcp4802/12/22

2-Channel 8/10/12-Bit DAC (SPI)

#### `mcp4802Setup(pinBase, spiChannel)`

### pca9685

16-Channel 12-Bit PWM led/servo driver (I2C)

#### `pca9685Setup(pinBase, i2cAddress, frequency)`

### pcf8574

8-Bit I/O expander (I2C)

#### `pcf8574Setup(pinBase, i2cAddress)`

### pcf8591

8-Bit ADC and DAC (I2C)

#### `pcf8591Setup(pinBase, i2cAddress)`

### sn3218

18-Channel PWM led driver (I2C)

#### `sn3218Setup(pinBase)`

### sr595

74x595 shift register

#### `sr595Setup(pinBase, numPins, dataPin, clockPin, latchPin)`

---

## DevLib

### ds1302

Trickle-charge timekeeping chip

#### `ds1302setup(clockPin, dataPin, csPin)`

#### `ds1302rtcRead(reg)`

#### `ds1302rtcWrite(reg, data)`

#### `ds1302ramRead(address)`

#### `ds1302ramWrite(address, data)`

#### `ds1302clockRead()`

#### `ds1302clockWrite(clockData[8])`

#### `ds1302trickleCharge(diodes, resistors)`

### GertBoard

#### `getboardAnalogSetup(pinBase)`

### LCD

#### `lcdInit(rows, cols, bits, rs, strb, d0, d1, d2, d3, d4, d5, d6, d7)`

#### `lcdHome(fd)`

#### `lcdClear(fd)`

#### `lcdDisplay(fd, state)`

#### `lcdCursor(fd, state)`

#### `lcdCursorBlink(fd, state)`

#### `lcdSendCommand(fd, command)`

#### `lcdPosition(fd, x, y)`

#### `lcdCharDef(fd, index, data[8])`

#### `lcdPutchar(fd, character)`

#### `lcdPuts(fd, string)`

#### `lcdPrintf(fd, string)`

### LCD 128x64

### MaxDetect

#### `maxDetectRead(pin)`

#### `readRHT03(pin)`

### piFace

#### `piFaceSetup(pinBase)`

### piGlow

#### `piGlowSetup(clear)`

#### `piGlow1(leg, ring, intensity)`

#### `piGlowLeg(leg, intensity)`

#### `piGlowRing(ring, intensity)`

### piNes

#### `setupNesJoystick(dPin, cPin, lPin)`

#### `readNesJoystick(joystick)`

### tcs34725

#### `tcs34725ReadRGBC(id)`

#### `tcs34725GetCorrelatedColorTemperature(r, g, b)`

#### `tcs34725GetIlluminance(r, g, b)`

#### `tcs34725SetInterrupt(id, aien)`

#### `tcs34725ClearInterrupt(id)`

#### `tcs34725SetInterruptLimits(id, low, high)`

#### `tcs34725Enable(id)`

#### `tcs34725Disable(id)`

#### `tcs34725Setup(i2cAddress, integrationTime, gain)`