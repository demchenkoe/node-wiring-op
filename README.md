Node.js bindings to [wiringPi](https://projects.drogon.net/raspberry-pi/wiringpi/)

Based on the awesome work of [Soarez](https://github.com/Soarez/node-wiring-pi)

## Install

    > npm install wiring-pi

## Use

```javascript
var wpi = require('wiring-pi');
```
## Setup

### `wpi.setup([mode])`

An handy function to setup wiringPi

```javascript
wpi.setup();
```

```javascript
wpi.setup('gpio');
```

Valid Modes:

- `wpi`: sets up pin numbering with `wiringPiSetup`
- `gpio`: sets up pin numbers with `wiringPiSetupGpio`
- `sys`: sets up pin numbers with `wiringPiSetupSys`
- `phys`: sets up pin numbers with `wiringPiSetupPhys`

See [wiringPi Pins](http://wiringpi.com/pins/) for the differences in Pin numbering;

### `wpi.wiringPiSetup()`

Initialises wiringPi and assumes that the calling program is going to be using the wiringPi pin numbering scheme.
This is a simplified numbering scheme which provides a mapping from virtual pin numbers 0 through 16 to the real underlying Broadcom GPIO pin numbers.
see the pins page (https://projects.drogon.net/raspberry-pi/wiringpi/pins/) for a table which maps the wiringPi pin number to the Broadcom GPIO pin number to the physical location on the edge connector.
This function needs to be called with root privileges.

```javascript
wpi.wiringPisetup();
```

### `wpi.wiringPiSetupGpio()`

This is indential to above, however it allows the calling programs to use the Broadcom GPIO pin numbers directly with no re-mapping.
As above, this function needs to be called with root privileges, and note that some pins are different from revision 1 to revision 2 boards.

```javascript
wpi.wiringPisetupGpio();
```

### `wpi.wiringPiSetupPhys()`

Identical to above, however it allows the calling programs to use the physical pin numbers on the P1 connector only.
As above, this function needs to be called with root priviliges.

```javascript
wpi.wiringPisetupPhys();
```

### `wpi.wiringPiSetupSys()`

This initialises wiringPi but uses the /sys/class/gpio interface rather than accessing the hardware directly. This can be called as a non-root user provided the GPIO pins have been exported before-hand using gpio program. Pin numbering in this mode is the native Broadcom GPIO numbers - the same as wiringPiSetGpio above, so be aware of the differences between Rev 1 and Rev 2 boards.
Note: In this mode you can only use the pins which have been exported via the /sys/class/gpio interface before you run your program.
You can do this in a seperate shell script, or by using the system() function from inside your program to call the gpio program.
Also note that some functions have no effect when using this mode as they're not currently possible to action unless called with root privileges. (although you can use system() to call gpio to set/change modes if needed).

```javascript
wpi.wiringPisetupSys();
```

## Core functions

### `wpi.pinModeAlt(pin, mode)`

This is an un-documented special to let you set any pin to any mode.

- `pin`: pin number
- `mode`: `wpi.WPI_MODE_PINS`, `wpi.WPI_MODE_PHYS` or `wpi.WPI_MODE_GPIO`

### `wpi.pinMode(pin, mode)`

This sets the mode of a pin to either INPUT, OUTPUT, PWM_OUTPUT or GPIO_CLOCK.
Note that only wiringPi pin 1 (BCM_GPIO 18) supports PWM output and only wiringPi pin 7 (BCM_GPIO 4) supports CLOCK output modes.
This function has no effect when in Sys mode. If you need to change the pin mode, the you can do it with the gpio program in a script before you start your program.

```javascript
wpi.pinMode(0, wpi.modes.OUTPUT);
```

- `pin`: pin number
- `mode`: `wpi.modes.INPUT`, `wpi.modes.OUTPUT`, `wpi.modes.PWM_OUTPUT` or `wpi.modes.GPIO_CLOCK`

### `wpi.pullUpDnControl(pin, pud)`

This sets the pull-up or pull-down resistor mode on the given pin, which should be set as an input. Unlike Arduino, the BCM2835 has both pull-up and down internal resistors.
The parameter pud should be; PUD_OFF (no pull up/down), PUD_DOWN (pull to ground) or PUD_UP (pull to 3.3v).
The internal pull up/down resistors have a value of approximately 50KΩ on the Raspberry Pi.

```javascript
wpi.pullUpDnControl(0, wpi.PUD_DOWN);
```

- `pin`: pin number
- `pud`: `wpi.PUD_OFF`, `wpi.PUD_DOWN`, `wpi.PUD_UP`

### `wpi.digitalRead(pin)`

This function returns the value read at the given pin. It will be HIGH or LOW (1 or 0) depending on the logic level at the pin.

```javascript
wpi.digitalRead(0);
//=> 1
```

- `pin`: pin number

### `wpi.digitalWrite(pin, value)`

Write the value HIGH or LOW (1 or 0) to the given pin which must have been previously set as an output.
WiringPi treats any non-zero number as HIGH, however 0 is the only representation of LOW.

```javascript
wpi.digitalWrite(0, wpi.HIGH);
```

```javascript
wpi.digitalWrite(0, wpi.LOW);
```

- `pin`: pin number
- `value`: 0 (`wpi.LOW`) or 1 (`wpi.HIGH`)

### `wpi.pwmWrite(pin, value)`

Writes the value to the PWM register for the given pin. The Raspberry Pi has one on-board PWM pin, pin 1 (BCM_GPIO 18, Phys 12) and the range is 0-1024.
Other PWM devices may have other PWM ranges.
This function is not able to control the Pi's on-board PWM when in Sys mode.

```javascript
wpi.pwmWrite(0, 512);
```

- `pin`: pin number
- `value`: value in PWM ranges

### `wpi.analogRead(pin)`

This returns the value read on the supplied analog input pin. You will need to register additional analog modules to enable this function for device such as the Gertboard, quick2Wire analog board, etc.

```javascript
wpi.analogRead(0);
//=> 512
```

- `pin`: pin number

### `wpi.analogWrite(pin, value)`

This writes the given value to the supplied analog pin. You will need to register additional analog modules to enable this function for devices such as the Gertboard.

```javascript
wpi.analogWrite(0, 512);
```

- `pin`: pin number
- `value`: value

## Raspberry Pi specifics

### `wpi.piBoardRev()`

This returns the board revision of the Raspberry Pi. It will be either 1 or 2.
Some of the BCM_GPIO pins changed number and function when moving from board revision 1 to 2, so if you are using BCM_GPIO pin numbers, then you need to be aware of the differences.

```javascript
wpi.piBoardRev();
//=>2
```

### `wpi.wpiPinToGpio(pin)`

This returns the BCM_GPIO pin number of the supplied wiringPi pin.
It takes the board revision into account.

```javascript
wpi.wpiPinToGpio(7);
//=>4
```

- `pin`: pin number in WiringPi scheme

### `wpi.physPinToGpio(pin)`

This returns the BCM_GPIO pin number of the suppled physical pin on the P1 connector.

```javascript
wpi.wpiPinToGpio(23);
//=>11
```

- `pin`: pin number in physical scheme

### `wpi.setPadDrive(group, value)`

This sets the "strength" of the pad drivers for a particular group of pins.
There are 3 groups of pins and the drive strength is from 0 to 7. Do not use the unless you know what you are doing.

### `wpi.getAlt(pin)`

Returns the ALT bits for a given port. Only really of-use for the gpio readall command (I think).

### `wpi.digitalWriteByte(value)`

This writes the 8-bit byte supplied to the first 8 GPIO pins. 
It’s the fastest way to set all 8 bits at once to a particular value, although it still takes two write operations to the Pi’s GPIO hardware.

```javascript
wpi.digitalWriteByte(0xFF); //set the first 8 GPIO pins to HIGH
```

- `value`: the byte to write to the first 8 GPIO pins

### `wpi.pwmSetMode(mode)`

The PWM generator can run in 2 modes – “balanced” and “mark:space”. 
The mark:space mode is traditional, however the default mode in the Pi is “balanced”. 
You can switch modes by supplying the parameter: PWM_MODE_BAL or PWM_MODE_MS.

```javascript
wpi.pwmSetMode(wpi.PWM_MODE_BAL);
```

- `mode`: `wpi.PWM_MODE_BAL` or `wpi.PWM_MODE_MS`

### `wpi.pwmSetRange(range)`

This sets the range register in the PWM generator. The default is 1024.
Note: The PWM control functions can not be used when in Sys mode.
To understand more about the PWM system, you’ll need to read the Broadcom ARM peripherals manual.

### `wpi.pwmSetClock(divisor)`

This sets the divisor for the PWM clock.
Note: The PWM control functions can not be used when in Sys mode.
To understand more about the PWM system, you’ll need to read the Broadcom ARM peripherals manual.

### `wpi.gpioClockSet(pin, freq)`

Set the frequency on a GPIO clock pin

## Contributing

wiring-pi is an [**OPEN Open Source Project**](http://openopensource.org/). This means that:

> Individuals making significant and valuable contributions are given commit-access to the project to contribute as they see fit. This project is more like an open wiki than a standard guarded open source project.

See the [CONTRIBUTING.md](https://github.com/eugeneware/wiring-pi/blob/master/CONTRIBUTING.md) file for more details.

### Contributors

wiring-pi is only possible due to the excellent work of the following contributors:

<table><tbody>
<tr><th align="left">Igor Soarez (Creator)</th><td><a href="https://github.com/Soarez">GitHub/Soarez</a></td><td><a href="https://twitter.com/igorsoarez">Twitter/@igorsoarez</a></td></tr>
<tr><th align="left">Gohy Leandre</th><td><a href="https://github.com/nekuz0r">GitHub/nekuz0r</a></td><td><a href="http://twitter.com/LeandreGohy">Twitter/@LeandreGohy</a></td></tr>
<tr><th align="left">Eugene Ware</th><td><a href="https://github.com/eugneware">GitHub/eugeneware</a></td><td><a href="http://twitter.com/eugeneware">Twitter/@eugeneware</a></td></tr>
</tbody></table>
