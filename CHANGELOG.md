# CHANGELOG

## v2.1.0 *[not released yet]*
  * **Update:** libWiringPi to [custom][nekuz0r-libWiringPi] v2.25 `nekuz0r`
  * **Update:** wiringPiISR now keeps event loop running `nekuz0r`
  * **Update:** piModelNames string array `nekuz0r`
  * **Update:** piMakerNames string array `nekuz0r`
  * **Update:** install.sh now clone tagged version of the custom libWiringPi
  * **Add:** support for node 0.12.0
  * **Add:** raspberry pi A+ support `nekuz0r`
  * **Add:** raspberry pi 2 support `nekuz0r`
  * **Add:** constant PI_MODEL_AP `nekuz0r`
  * **Add:** constant PI_MODEL_2 `nekuz0r`
  * **Add:** constant PI_MARKER_MBEST `nekuz0r`
  * **Add:** wiringPiISRCancel `nekuz0r`
  * **Add:** wiringPiSPISetupMode `nekuz0r`
  * **Fix:** blink.js example `louterrailloune`
  * **Fix:** SPI speed select argument `noddy76`

## v2.0.0 *[Jan 1 2015]*
  * **Update:** libWiringPi to [custom][nekuz0r-libWiringPi] v2.20 `nekuz0r`
  * **Update:** split source code (based on libWiringPi hierarchy) `nekuz0r`
  * **Update:** better types check `nekuz0r`
  * **Update:** better allowed values check `nekuz0r`
  * **Update:** better error messages `nekuz0r`
  * **Update:** documentation `nekuz0r`
  * **Update:** constants are exported from c++ (ReadOnly | DontDelete) `nekuz0r`
  * **Update:** setup() is exported from c++ `nekuz0r`
    * NOTE: it no longer accepts empty parameter 'mode' (breaks backward compatibility)
  * **Update:** wiringPiSPIDataRW now takes a buffer as second parameter (no third anymore) `nekuz0r`
  * **Update:** piBoardId `nekuz0r`
  * **Remove:** backward compatibility constants `nekuz0r`
  * **Remove:** export of piComputeModuleRevisionNames `nekuz0r`
  * **Add:** export of PI_MODEL_* constants `nekuz0r`
  * **Add:** export of PI_VERSION_* constants `nekuz0r`
  * **Add:** export of PI_MAKER_* constants `nekuz0r`
  * **Add:** export of piMakerNames string table `nekuz0r`
  * **Add:** wiringPiISR `nekuz0r`
  * **Add:** pwmToneWrite `nekuz0r`
  * **Add:** CHANGELOG.md `nekuz0r`
  * **Add:** wiringPiI2C support `nekuz0r`
  * **Add:** wiring-pi install gpio utilty (required for interrupts) `nekuz0r`
  * **Add:** ds1302 support `nekuz0r`
  * **Add:** gertboard support `nekuz0r`
  * **Add:** lcd support `nekuz0r`
  * **Add:** lcd128x64 support `nekuz0r`
  * **Add:** maxdetect support `nekuz0r`
  * **Add:** piFace support `nekuz0r`
  * **Add:** piGlow support `nekuz0r`
  * **Add:** piNes support `nekuz0r`
  * **Add:** tcs34725 support `nekuz0r`
  * **Add:** dac7678 support `nekuz0r`
  * **Fictitious:** this release eats Pi(e)s :)

## v1.1.1 *[Jul 4 2014]*
  * **Fix:** missing constant in pinModeCheck `nekuz0r`
  * **Fix:** missing constant PI_MODEL_CM `nekuz0r`
  * **Add:** serialPrintf (alias to serialPuts) `nekuz0r`

## v1.1.0 *[Jun 30 2014]*
  * **Update:** libWiringPi to [custom][nekuz0r-libWiringPi] v2.15 `nekuz0r`
  * **Fix:** mcp3422 constants again `nekuz0r`
  * **Remove:** precompiled dependencies `nekuz0r`
  * **Add:** install script
  * **Add:** pca9685 support `nekuz0r`
  * **Add:** pulseIn `nekuz0r`
  * **Add:** piBoardId `nekuz0r`
  * **Add:** softPwmStop `nekuz0r`
  * **Add:** softToneStop `nekuz0r`
  * **Add:** SOFT_PWM_OUTPUT, SOFT_TONE_OUTPUT `nekuz0r`
  * **Add:** PI_MODEL_A, PI_MODEL_B, PI_MODEL_CM `nekuz0r`
  * **Add:** PI_MODEL_NAMES, PI_REVISION_NAMES, PI_COMPUTE_REVISION_NAMES `nekuz0r`
  * **Add:** delay `nekuz0r`
  * **Add:** delayMicroseconds `nekuz0r`
  * **Add:** millis `nekuz0r`
  * **Add:** micros `nekuz0r`

## v1.0.2 *[Mar 18 2014]*
  * Releasing as Open Open Source `eugeneware`

## v1.0.1 *[Mar 18 2014]*
  * **Fix:** mcp3422 constants `nekuz0r`

## v1.0.0 *[Nov 29 2013]*
  * **Update:** libWiringPi to v2.13 `nekuz0r`
  * **Update:** examples (blink, pwm) `nekuz0r`
  * **Update:** documentation `nekuz0r`
  * **Add:** physical numbering scheme support (setup) `nekuz0r`
  * **Add:** drcSerial support `nekuz0r`
  * **Add:** max5322 support `nekuz0r`
  * **Add:** mcp23s08 support `nekuz0r`
  * **Add:** mcp3002 support `nekuz0r`
  * **Add:** mcp3004 support `nekuz0r`
  * **Add:** mcp3422 support `nekuz0r`
  * **Add:** mcp4802 support `nekuz0r`
  * **Add:** mcp23008 support `nekuz0r`
  * **Add:** mcp23016 support `nekuz0r`
  * **Add:** mcp23017 support `nekuz0r`
  * **Add:** pcf8574 support `nekuz0r`
  * **Add:** pcf8591 support `nekuz0r`
  * **Add:** softPWM support `nekuz0r`
  * **Add:** softServo support `nekuz0r`
  * **Add:** softTone support `nekuz0r`
  * **Add:** sr595 support `nekuz0r`
  * **Add:** wiringPiSPI support `nekuz0r`
  * **Add:** wiringPiSerial support (serialPrintf not implemented yet) `nekuz0r`
  * **Add:** wiringPiShift support `nekuz0r`
  * **Add:** pinModeAlt `nekuz0r`
  * **Add:** analogRead `nekuz0r`
  * **Add:** analogWrite `nekuz0r`
  * **Add:** wpiPinToGpio `nekuz0r`
  * **Add:** physPinToGpio `nekuz0r`
  * **Add:** setPadDrive `nekuz0r`
  * **Add:** getAlt `nekuz0r`
  * **Add:** digitalWriteByte `nekuz0r`
  * **Add:** pwmSetMode `nekuz0r`
  * **Add:** gpioClockSet `nekuz0r`
  * **Add:** LSBFIRST, MSBFIRST `nekuz0r`
  * **Add:** MCP3422_SR_3_75, MCP3422_SR_15, MCP3422_SR_60, MCP3422_SR_240 `nekuz0r`
  * **Add:** MCP3422_GAIN_1, MCP3422_GAIN_2, MCP3422_GAIN_4, MCP3422_GAIN_8 `nekuz0r`
  * **Add:** WPI_MODE_PINS, WPI_MODE_GPIO, WPI_MODE_GPIO_SYS, WPI_MODE_GPIO_PHYS, WPI_MODE_PIFACE, WPI_MODE_UNINITIALIZED `nekuz0r`
  * **Add:** INPUT, OUTPUT, PWM_OUTPUT, GPIO_CLOCK `nekuz0r`
  * **Add:** PUD_OFF, PUD_UP, PUD_DOWN `nekuz0r`
  * **Add:** PWM_MODE_MS, PWM_MODE, BAL `nekuz0r`
  * **Add:** INT_EDGE_SETUP, INT_EDGE_FALLING, INT_EDGE_RISING, INT_EDGE_BOTH `nekuz0r`
  
## v0.2.0 *[Nov 5 2013]*
  * **Add:** pullUpDnControl `nekuz0r`
  * **Add:** pull.PUD_OFF, pull.PUD_UP, pull.PUD_DOWN `nekuz0r`
  
## v0.1.2 *[Aug 2 2013]*
  * **Add:** HIGH, LOW `csquared`
  * **Fix:** typo in exports.js `csquared`
  * **Update:** README.md `csquared`
  
## v0.1.1 *[Jun 11 2013]*
  * **Add:** PWM example `eugeneware`
  * **Fix:** pwmWrite export `eugeneware`
  
## v0.1.0 *[Dec 20 2013]*
  * Initial version `soarez`
    * wiringPiSetup
    * wiringPiSetupGpio
    * wiringPiSetupSys
    * piBoardRev
    * pinMode
    * digitalWrite
    * digitalRead
    * pwmSetRange
    * pwmSetClock
    * pwmWrite
    * setup
    * blink example
    
[nekuz0r-libWiringPi]: https://github.com/nekuz0r/wiringpi/