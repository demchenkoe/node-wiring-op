// PCA9685 Registers

#define MODE1 0x00
#define MODE2 0x01
#define SUBADR1 0x02
#define SUBADR2 0x03
#define SUBADR3 0x04
#define ALLCALLADR 0x05
#define LED0_ON_L 0x06
#define LED0_ON_H 0x07
#define LED0_OFF_L 0x08
#define LED0_OFF_H 0x09
// LED1 .. LED15 (0x0A .. 0x45)
#define ALL_LED_ON_L 0xFA
#define ALL_LED_ON_H 0xFB
#define ALL_LED_OFF_L 0xFC
#define ALL_LED_OFF_H 0xFD
#define PRE_SCALE 0xFE
#define TESTMODE 0xFF

// Bits in the MODE1 register

#define MODE1_RESTART 0x80
#define MODE1_EXTCLK 0x40
#define MODE1_AI 0x20
#define MODE1_SLEEP 0x10
#define MODE1_SUB1 0x08
#define MODE1_SUB2 0x04
#define MODE1_SUB3 0x02
#define MODE1_ALLCALL 0x01

// Bits in the MODE2 register

#define MODE2_INVRT 0x10
#define MODE2_OCH 0x08
#define MODE2_OUTDRV 0x04
#define MODE2_OUTNE_1 0x02
#define MODE2_OUTNE_0 0x01

#define OSC_CLOCK 25000000.0f
#define PRESCALE_DIVIDER 4096.0f