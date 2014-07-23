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

### `wiringPiSetup()`
<span class="api-info"><code> >= 0.1.0 </code></span>

Initialises wiringPi and assumes that the calling program is going to be using the wiringPi pin numbering scheme.
This is a simplified numbering scheme which provides a mapping from virtual pin numbers 0 through 16 to the real underlying Broadcom GPIO pin numbers.
see the [pins](http://wiringpi.com/pins/) page for a table which maps the wiringPi pin number to the Broadcom GPIO pin number to the physical location on the edge connector.
This function needs to be called with root privileges.

### `wiringPiSetupGpio()`
<span class="api-info"><code> >= 0.1.1 </code></span>

This is indential to above, however it allows the calling programs to use the Broadcom GPIO pin numbers directly with no re-mapping. As above, this function needs to be called with root privileges, and note that some pins are different from revision 1 to revision 2 boards.

### `wiringPiSetupPhys()`
<span class="api-info"><code> >= 1.0.0 </code></span>

Identical to above, however it allows the calling programs to use the physical pin numbers on the P1 connector only. As above, this function needs to be called with root priviliges.

### `wiringPiSetupSys()`
<span class="api-info"><code> >= 0.1.1 </code></span>

This initialises wiringPi but uses the /sys/class/gpio interface rather than accessing the hardware directly. This can be called as a non-root user provided the GPIO pins have been exported before-hand using gpio program. Pin numbering in this mode is the native Broadcom GPIO numbers - the same as wiringPiSetGpio above, so be aware of the differences between Rev 1 and Rev 2 boards. Note: In this mode you can only use the pins which have been exported via the /sys/class/gpio interface before you run your program. You can do this in a seperate shell script, or by using the system() function from inside your program to call the gpio program. Also note that some functions have no effect when using this mode as they're not currently possible to action unless called with root privileges. (although you can use system() to call gpio to set/change modes if needed).

### `setup(mode)`
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

### `pinModeAlt(pin, mode)`
<span class="api-info"><code> >= 1.0.0 </code></span>

This is an un-documented special to let you set any pin to any mode.

`mode` can be one of the following values:

* `WPI_MODE_PINS`
  <span class="api-info-list"><code> >= 1.0.0 </code></span>
* `WPI_MODE_PHYS`
  <span class="api-info-list"><code> >= 1.0.0 </code></span>
* `WPI_MODE_GPIO`
  <span class="api-info-list"><code> >= 1.0.0 </code></span>
  
### `pinMode(pin, mode)`
<span class="api-info"><code> >= 0.1.0 </code></span>

This sets the mode of a pin. Note that only wiringPi pin 1 (BCM_GPIO 18) supports PWM output and only wiringPi pin 7 (BCM_GPIO 4) supports CLOCK output modes. This function has no effect when in Sys mode. If you need to change the pin mode, the you can do it with the gpio program in a script before you start your program.

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
  
### `pullUpDnControl(pin, pud)`
<span class="api-info"><code> >= 0.2.0 </code></span>

This sets the pull-up or pull-down resistor mode on the given pin, which should be set as an input. Unlike Arduino, the BCM2835 has both pull-up and down internal resistors. The internal pull up/down resistors have a value of approximately 50KΩ on the Raspberry Pi.

`pud` can be one of the following values:

* `PUD_OFF` *no pull up/down*
<span class="api-info-list"><code> >= 0.2.0 </code></span>
* `PUD_DOWN` *pull to ground*
<span class="api-info-list"><code> >= 0.2.0 </code></span>
* `PUD_UP` *pull to 3.3v*
<span class="api-info-list"><code> >= 0.2.0 </code></span>
  
### `digitalRead(pin)`
<span class="api-info"><code> >= 0.1.1 </code></span>

This function returns the value read at the given pin. It will be `HIGH` (1) or `LOW` (0) depending on the logic level at the pin.

### `digitalWrite(pin, state)`
<span class="api-info"><code> >= 0.1.0 </code></span>

Write the value `HIGH` (1) or `LOW` (0) to the given pin which must have been previously set as an output. WiringPi treats any non-zero number as `HIGH`, however 0 is the only representation of `LOW`.

`state` can be one of the following value:

* `HIGH`
  <span class="api-info-list"><code> >= 0.1.2 </code></span>
* `LOW`
  <span class="api-info-list"><code> >= 0.1.2 </code></span>

### `pwmWrite(pin, value)`
<span class="api-info"><code> >= 0.1.1 </code></span>

Writes the value to the PWM register for the given pin. The Raspberry Pi has one on-board PWM pin, pin 1 (BCM_GPIO 18, Phys 12) and the range is [0, 1024]. Other PWM devices may have other PWM ranges. This function is not able to control the Pi's on-board PWM when in Sys mode.

`value` must be in range of [0, 1024]

### `analogRead(pin)`
<span class="api-info"><code> >= 1.0.0 </code></span>

This returns the value read on the supplied analog input pin. You will need to register additional analog modules to enable this function for device such as the Gertboard, quick2Wire analog board, etc.

### `analogWrite(pin, value)`
<span class="api-info"><code> >= 1.0.0 </code></span>

This writes the given value to the supplied analog pin. You will need to register additional analog modules to enable this function for devices such as the Gertboard.

### `pulseIn(pin, state)`
<span class="api-info"><code> >= 1.1.0 </code></span>

`state` can be one of the following values:

* `HIGH`
  <span class="api-info-list"><code> >= 0.1.2 </code></span>
* `LOW`
  <span class="api-info-list"><code> >= 0.1.2 </code></span>
  
### `delay(milliseconds)`
<span class="api-info"><code> >= 1.1.0 </code></span>

### `delayMicroseconds(microseconds)`
<span class="api-info"><code> >= 1.1.0 </code></span>

### `millis()`
<span class="api-info"><code> >= 1.1.0 </code></span>

### `micros()`
<span class="api-info"><code> >= 1.1.0 </code></span>

---

## Raspberry Pi hardware specific functions

### `piBoardRev()`
<span class="api-info"><code> >= 0.1.1 </code></span>

This returns the board revision of the Raspberry Pi. It will be either 1 or 2. Some of the BCM_GPIO pins changed number and function when moving from board revision 1 to 2, so if you are using BCM_GPIO pin numbers, then you need to be aware of the differences.

### `piBoardId()`
<span class="api-info"><code> >= 1.1.0 </code></span>

### `wpiPinToGpio(pin)`
<span class="api-info"><code> >= 1.0.0 </code></span>

This returns the BCM_GPIO pin number of the supplied wiringPi pin. It takes the board revision into account.

### `physPinToGpio(pin)`
<span class="api-info"><code> >= 1.0.0 </code></span>

This returns the BCM_GPIO pin number of the suppled physical pin on the P1 connector.

### `setPadDrive(group, value)`
<span class="api-info"><code> >= 1.0.0 </code></span>

This sets the "strength" of the pad drivers for a particular group of pins. There are 3 groups of pins and the drive strength is from 0 to 7. Do not use the unless you know what you are doing.

### `getAlt(pin)`
<span class="api-info"><code> >= 1.0.0 </code></span>

Returns the ALT bits for a given port.

### `digitalWriteByte(byte)`
<span class="api-info"><code> >= 1.0.0 </code></span>

This writes the 8-bit byte supplied to the first 8 GPIO pins. It’s the fastest way to set all 8 bits at once to a particular value, although it still takes two write operations to the Pi’s GPIO hardware.

### `pwmSetMode(mode)`
<span class="api-info"><code> >= 1.0.0 </code></span>

The PWM generator can run in 2 modes – “balanced” and “mark:space”. The mark:space mode is traditional, however the default mode in the Pi is “balanced”.

`mode` can be one of the following values:

* `PWM_MODE_BAL` *balanced*
* `PWM_MODE_MS` *mark:space*
  
### `pwmSetRange(range)`
<span class="api-info"><code> >= 0.1.1 </code></span>

This sets the range register in the PWM generator. The default is 1024. Note: The PWM control functions can not be used when in Sys mode. To understand more about the PWM system, you’ll need to read the Broadcom ARM peripherals manual.

### `pwmSetClock(divisor)`
<span class="api-info"><code> >= 0.1.1 </code></span>

This sets the divisor for the PWM clock. Note: The PWM control functions can not be used when in Sys mode. To understand more about the PWM system, you’ll need to read the Broadcom ARM peripherals manual.

### `gpioClockSet(pin, frequency)`
<span class="api-info"><code> >= 1.0.0 </code></span>

Set the frequency on a GPIO clock pin

---

## I2C

### `wiringPiI2CSetup(devId)`
<span class="api-info"><code> >= 2.0.0 </code></span>

### `wiringPiI2CSetupInterface(device, devId)`
<span class="api-info"><code> >= 2.0.0 </code></span>

### `wiringPiI2CRead(fd)`
<span class="api-info"><code> >= 2.0.0 </code></span>

### `wiringPiI2CReadReg8(fd, reg)`
<span class="api-info"><code> >= 2.0.0 </code></span>

### `wiringPiI2CReadReg16(fd, red)`
<span class="api-info"><code> >= 2.0.0 </code></span>

### `wiringPiI2CWrite(fd, data)`
<span class="api-info"><code> >= 2.0.0 </code></span>

### `wiringPiI2CWriteReg8(fd, reg, data)`
<span class="api-info"><code> >= 2.0.0 </code></span>

### `wiringPiI2CWriteReg16(fd, reg, data)`
<span class="api-info"><code> >= 2.0.0 </code></span>

---

## SPI

### `wiringPiSPIGetFd(channel)`
<span class="api-info"><code> >= 1.0.0 </code></span>

### `wiringPiSPIDataRW(channel, data)`
<span class="api-info"><code> >= 1.0.0 </code></span>

### `wiringPiSPISetup(channel, speed)`
<span class="api-info"><code> >= 1.0.0 </code></span>

---

## Serial

### `serialOpen(device, baudrate)`
<span class="api-info"><code> >= 1.0.0 </code></span>

### `serialClose(fd)`
<span class="api-info"><code> >= 1.0.0 </code></span>

### `serialFlush(fd)`
<span class="api-info"><code> >= 1.0.0 </code></span>

### `serialPutchar(fd, character)`
<span class="api-info"><code> >= 1.0.0 </code></span>

### `serialPuts(fd, string)`
<span class="api-info"><code> >= 1.0.0 </code></span>

### `serialPrintf(fd, string)`
<span class="api-info">
  <code>Alias: serialPuts</code>
  <code> >= 2.0.0 </code>
</span>

### `serialDataAvail(fd)`
<span class="api-info"><code> >= 1.0.0 </code></span>

### `serialGetchar(fd)`
<span class="api-info"><code> >= 1.0.0 </code></span>

---

## Shift

### `shiftIn(dPin, cPin, order)`
<span class="api-info"><code> >= 1.0.0 </code></span>

### `shiftOut(dPin, cPin, order, value)`
<span class="api-info"><code> >= 1.0.0 </code></span>

---

## Soft PWM

### `softPwmCreate(pin, value, range)`
<span class="api-info"><code> >= 1.0.0 </code></span>

### `softPwmWrite(pin, value)`
<span class="api-info"><code> >= 1.0.0 </code></span>

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

### `softToneWrite(pin, frequency);`
<span class="api-info"><code> >= 1.0.0 </code></span>

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