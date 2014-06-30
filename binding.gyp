{
  'targets': [
    {
      'target_name': 'wiringPi',
      'sources': [
        'src/bindings.cc'
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
