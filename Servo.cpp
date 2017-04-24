#include "Servo.h"
#include"Constantes_&_Pinos.h"


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
    pinMode (servoPin, PWM_OUTPUT);
    pwmSetMode (PWM_MODE_MS);    
	pwmSetClock (PWMCLOCK);
	pwmSetRange (PWMRANGE);
    
}

void Servo::setServoPin(const int _servoIn)
{
    
    servoPin = _servoIn;
}

void Servo::setAngulo(const unsigned _angulo)
{
    
   pwmWrite (servoPin, _angulo/1.8+100);

}

void Servo::varreduraD()
{
	for (int i = 100; i < 200; i++)
	{
		pwmWrite(servoPin, i);
		delay(500);
	}
		
}

void Servo::varreduraE()
{
	for (int i = 200; i > 100; i--)
	{
		pwmWrite(servoPin, i);
		delay(500);
	}

}

