#!/bin/bash

#Link pro softpwm https://projects.drogon.net/raspberry-pi/wiringpi/software-pwm-library/

g++ main.cpp -o test -lwiringPi -lpthread Ultrassom.cpp Servo.cpp
./test
