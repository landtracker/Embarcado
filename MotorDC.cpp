#include "MotorDC.h"
#include"Constantes_&_Pinos.h"


MotorDC::MotorDC()
{
    
}

MotorDC::MotorDC(unsigned vel, unsigned dir)
{
    velPin = vel;
    dirPin = dir;
    pinMode(vel, OUTPUT);
    pinMode(dir, OUTPUT);
    Stop();
    
    
}

MotorDC::~MotorDC()
{
    Stop();
    velPin = -1;
    dirPin = -1;
}



void MotorDC::Frente(const unsigned _distancia)
{
    
    digitalWrite(velPin, HIGH);
    digitalWrite(dirPin, LOW);
//    delay(_distancia*1000);

}
void MotorDC::Tras(const unsigned _distancia)
{

    digitalWrite(velPin, HIGH);
    digitalWrite(dirPin, HIGH);
    
}

void MotorDC::Stop()
{
    digitalWrite(velPin, LOW);
    digitalWrite(dirPin, LOW);
}

void MotorDC::setup(unsigned vel, unsigned dir)
{
    velPin = vel;
    dirPin = dir;
    pinMode(vel, OUTPUT);
    pinMode(dir, OUTPUT);
    Stop();
    
}

