var wiringpi = require( 'wiring-op' );

wiringpi.wiringPiSetupPhys();
wiringpi.pinMode( 29, wiringpi.OUTPUT );

wiringpi.digitalWrite( 29,1);
console.log( wiringpi.digitalRead( 29) );


