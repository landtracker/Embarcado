#include "Servo.h"
#include"Constantes_&_Pinos.h"


Servo::Servo()
{
    servoPin = -1;
    pwm = 0;
    range = 0;
    flagArduino = false;
    
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
    pinMode(servoPin, PWM_OUTPUT);
    pwmSetMode (PWM_MODE_MS);
    pwmSetClock (PWMCLOCK);
    pwmSetRange (PWMRANGE);
    Alinhar();    
    
}

void Servo::setServoPin(const int _servoIn)
{
    
    servoPin = _servoIn;
}

void Servo::setAngulo(const unsigned _angulo)
{
    
    angulo = _angulo;
    
    if(!getFlag())
    {
        pwmWrite(servoPin, ((_angulo/1.8) + 100));
    }
    
    else
        
    {
        setAnguloServoArduino(_angulo);
    }
    
}



void Servo::Alinhar()
{
    setAngulo(90);
    
}

void Servo::iniciaServoArduino(const int _servoIn)
{
    
    if( _servoIn >0 &  _servoIn <4)
    {
        servoArduino = _servoIn;
        setFlagArduino(true);
    }
    
    else
    {
        servoArduino = -1;
        setFlagArduino(false);
        cout<<"Servo Arduino Invalido"<<endl;
    }
    
}

void Servo::setAnguloServoArduino(const unsigned _angulo)
{
    unsigned fd = 0; 
    fd = wiringPiI2CSetup(I2CADDR);
    
    if( servoArduino > 0 & servoArduino < 4)
    {
        wiringPiI2CWrite(fd, servoArduino );
        delay(30);
        
        if(_angulo >=0 & _angulo <=180)
        {
            wiringPiI2CWrite(fd, _angulo);   
            
        }
        
        else
        {
            cout<<"Angulo Invalido no Servo Arduino!"<<endl;
        }
        
    }
    
    else
    {
        cout<<"Servo Arduino Invalido"<<endl;   
    }        
    
}


void Servo::setFlagArduino(const bool _flag)
{
    flagArduino = _flag;
}

const bool Servo:: getFlag() const
{
    return flagArduino;
}

unsigned Servo::getAngulo()
{
    return angulo;
}

void Servo::Direita()
{
    setAngulo(180);
}
void Servo::Esquerda()
{
    setAngulo(0);
}
