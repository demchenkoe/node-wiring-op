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
        'src/wpi.cc'
      ],
      'include_dirs': [
        'wiringpi/wiringPi'
      ],
      'libraries': [
        '<!(pwd)/wiringpi/wiringPi/libwiringPi.a'
      ],
      'cflags': [
        '-Wall -std=c++11'
      ],
      'conditions': [
        [
          'OS=="mac"', {
            "xcode_settings": {
              'OTHER_CPLUSPLUSFLAGS' : ['-std=c++11','-stdlib=libc++'],
              'OTHER_LDFLAGS': ['-stdlib=libc++'],
              'MACOSX_DEPLOYMENT_TARGET': '10.7'
            }
          }
        ]
      ]
    }
  ]
}
