#!/bin/bash

#Link pro softpwm https://projects.drogon.net/raspberry-pi/wiringpi/software-pwm-library/

g++ main.cpp -o test -lwiringPi  MotorDC.cpp  Ultrassom.cpp Servo.cpp
sudo ./test
