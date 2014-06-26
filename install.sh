#!/bin/bash

git clone https://github.com/nekuz0r/wiringpi.git
cd ./wiringpi/wiringPi/
make static
cd ../../
node-gyp rebuild