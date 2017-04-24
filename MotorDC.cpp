#include "MotorDC.h"
#include"Constantes_&_Pinos.h"


MotorDC::Servo(unsigned vel, unsigned dir)
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

void Frente(const unsigned _duracao)
{
	digitalWrite(velPin, HIGH);
	digitalWrite(dirPin, HIGH);
	delay(1000 * _duracao);
	Stop();

}
void Traz(const unsigned _duracao)
{
	digitalWrite(velPin, HIGH);
	digitalWrite(dirPin, LOW);
	delay(1000 * _duracao);
	Stop();

}

void Stop()
{
	digitalWrite(velPin, LOW);
	digitalWrite(dirPin, LOW);
}