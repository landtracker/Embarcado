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

void Servo::iniciaServo(const int _servoIn, const int _flag)
{

    setFlag(_flag);
    delay(30);

    if (flag==0)
    {

        setServoPin(_servoIn);
        pinMode(servoPin, PWM_OUTPUT);
        pwmSetMode (PWM_MODE_MS);
        pwmSetClock (PWMCLOCK);
        pwmSetRange (PWMRANGE);
	Alinhar();
    }

    else if(flag==1)
    {
        setServoPin(_servoIn);
        pinMode(servoPin, OUTPUT);
        digitalWrite(servoPin, LOW);
        softPwmCreate(servoPin, 0, 100);
	Alinhar();
    }
    
    else if(flag==2)
    {
        setServoPin(_servoIn);
        pinMode(servoPin, PWM_OUTPUT);
        pwmSetMode (PWM_MODE_MS);
        pwmSetClock (PWMCLOCK);
        pwmSetRange (PWMRANGE);
	pwmWrite(servoPin,154);
    }


    else
    {
        cout<<"Erro! Impossível inicializar o servo!"<<endl;
    }



}

void Servo::setServoPin(const int _servoIn)
{

    servoPin = _servoIn;
}

void Servo::setAngulo(const unsigned _angulo)
{


    if(flag==0)
    {
        pwmWrite(servoPin, ((_angulo/1.8) + 100));
    }

    else if(flag==1)
    {
        softPwmWrite(servoPin, (_angulo/1.8)); //Range 0 a 100 e nao 0 a 150

    }
    

    else
    {
        cout<<"Erro! Impossível setar Angulo!"<<endl;
    }

}

void Servo::setFlag(const int _flag)
{
    flag = _flag;
}

void Servo::varreduraD()
{

    for(int i = 0; i <= 18; i++)
    {
        setAngulo(10*i);
        delay(150);
    }


}

void Servo::varreduraE()
{

    for(int i = 18; i >= 0; i--)
    {
        setAngulo(10*i);
        delay(150);
    }



}

void Servo::Direita()
{
  if (flag==2)
  {
    pwmWrite(servoPin,100);
    delay (200);
    pwmWrite(servoPin,154);
    delay (200);
  }
  
  else
  {
	setAngulo(180);
	delay (200);
  }
}

void Servo::Esquerda()
{
  if (flag==2)
  {
    pwmWrite(servoPin,208);
    delay (250);
    pwmWrite(servoPin,154);
    delay (200);
  }
  
  else
  {
	setAngulo(0);
	delay (200);
  }
}

void Servo::Alinhar()
{
  setAngulo(90);

}
