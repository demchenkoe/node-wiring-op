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
see the pins page (http://wiringpi.com/pins/) for a table which maps the wiringPi pin number to the Broadcom GPIO pin number to the physical location on the edge connector.
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