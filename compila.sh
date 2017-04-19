#!/bin/bash
g++ main.cpp -o test -lwiringPi Ultrassom.cpp Servo.cpp
./test
