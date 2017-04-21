#include "Servo.h"


Servo::Servo()
{
    servoPin = -1;
    pwm = 0;
    range = 0;  
    
}

Servo::~Servo()
{
    servoPin = -1;
    pwm = 0;
    range = 0;  
    
}

void Servo::iniciaServo(const int _servoIn)
{
    
    setServoPin(_servoIn);
    pinMode (getPin(), PWM_OUTPUT); //
    pwmSetMode (PWM_MODE_MS);    
    
}


void Servo::setServoPin(const int _servoIn)
{
    
    servoPin = _servoIn;
}


void Servo::setClock(const unsigned _pwm)
{
    
    pwm = _pwm;
    pwmSetClock(pwm);
}

void Servo::setRange(const unsigned _range)
{
    range = _range;
    pwmSetRange (range);
}

void Servo::setAngulo(const unsigned _angulo)
{
    
    angulo = _angulo; 
    pwmWrite (getPin(), angulo);
}


const unsigned Servo::getPin()
{
    
    return servoPin;
    
}   


