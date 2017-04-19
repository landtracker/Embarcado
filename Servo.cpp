#include "Servo.h"


Servo::Servo()
{
    _servoPin = -1;
    _pwm = 0;
    _range = 0;  
    
}

Servo::~Servo(){}

void Servo::iniciaServo(const int servoIn)
{
    
    setServoPin(const int servoIn);
    pinMode (getPin(), PWM_OUTPUT); //
    pwmSetMode (PWM_MODE_MS);    
    
}


Servo::setServoPin(const int servoIn)
{
    
    this._servoPin = servoIn;
}


void Servo::setClock(const unsigned pwm)
{
    
    this._pwm = pwm;
    pwmSetClock(this._pwm);
}

void Servo::setRange(const unsigned range)
{
    this._range = range;
    pwmSetRange (this._range);
}

void Servo::setAngulo(const unsigned angulo)
{
    
    this._angulo = angulo; 
    pwmWrite (getPin, this._angulo);
}


const int Servo::getPin()
{
    
    return this._servoPin;
    
}   


