{
  'targets': [
    {
      'target_name': 'wiringPi',
      'sources': [
        'src/wiringPi.cc',
        'src/softPwm.cc',
        'src/softServo.cc',
        'src/softTone.cc',
        'src/wiringPiI2C.cc',
        'src/wiringPiSPI.cc',
        'src/wiringSerial.cc',
        'src/wiringShift.cc',
        'src/wiringPiISR.cc',
        
        'src/extensions/drcSerial.cc',
        
        'src/wpi.cc'
      ],
      'include_dirs': [
        'wiringpi/wiringPi'
      ],
      'libraries': [
        '<!(pwd)/wiringpi/wiringPi/libwiringPi.a'
      ],
      'cflags': [
        '-Wall'
      ]
    }
  ]
}
