#!/bin/bash

check_make_ok() {
  echo ""
  echo "================================================================================"
  if [ $2 == 1 ]; then
    echo "FATAL: Making $1 failed."
  else
    echo "Making $1 failed."
  fi
  echo "Please check the messages and fix any problems. If you're still stuck,"
  echo "then please open a new issue then post all the output and as many details as you can to"
  echo "  https://github.com/eugeneware/wiring-pi/issues"
  echo "================================================================================"
  echo ""
  if [ $2 == 1 ]; then
    exit 1
  fi
}

git clone https://github.com/nekuz0r/wiringpi.git

cd ./wiringpi/wiringPi/
make clean
make static
check_make_ok "libWiringPi" 1
cd ../../

cd ./wiringpi/gpio/
sudo make uninstall
make clean
make
check_make_ok "gpio utility"
sudo make install
check_make_ok "gpio utility"

node-gyp rebuild