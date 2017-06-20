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
    
    if(!flagArduino)
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

void Servo::iniciaServoArduino(const int _servoIn, unsigned _fd)
{
    //cout << "AKI" << endl;
    fd = _fd;
    if( _servoIn >0 &  _servoIn <4)
    {
        servoArduino = _servoIn;
        setFlagArduino(true);
        //Alinhar();
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
    wiringPiI2CWriteReg8(fd, servoArduino, _angulo);
    
}


void Servo::setFlagArduino(const bool _flag)
{
    flagArduino = _flag;
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
