var wpi = require('wiring-pi');

wpi.setup('wpi');

var pin = 0;

wpi.pinMode(0, wpi.OUTPUT);

var value = 1;

setInterval(function() {
  wpi.digitalWrite(pin, value);
  value = +!value;
}, 500);
