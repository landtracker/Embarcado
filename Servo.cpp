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
    setClock(PWMCLOCK);
    setRange(PWMRANGE);
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
    pwmSetRange(range);
}

void Servo::setAngulo(const unsigned _angulo)
{
    
    angulo = _angulo; 
    
    if(angulo >=0 || angulo <=180)
    {
        
        
        //de 0° a 90°
        
        if(angulo>= 0 && angulo<10)
            
        {
            pwmWrite (getPin(), 200);//Setando 0°

        }

        else if(angulo>= 10 && angulo<20)
        {
           pwmWrite (getPin(), 194.44);//Setando 10°

        }


        else if(angulo>= 20 && angulo<30)
        {
            pwmWrite (getPin(), 188.89);//Setando 20°

        }

        else if(angulo>= 30 && angulo<40)
        {
            pwmWrite (getPin(), 183.33);//Setando 30°

        }

        else if(angulo>= 40 && angulo<50)
        {
            pwmWrite (getPin(), 177.78);//Setando 40°

        }

        else if(angulo>= 50 && angulo<60)
        {
            pwmWrite (getPin(), 172.22); //Setando 50°

        }

        else if(angulo>= 60 && angulo<70)
        {
            pwmWrite (getPin(), 166.67); //Setando 60°

        }

        else if(angulo>= 70 && angulo<80)
        {
            pwmWrite (getPin(), 161.11); //Setando 70°

        }

        else if(angulo>= 80 && angulo<90)
        {
            pwmWrite (getPin(), 155.56 );//Setando 80°

        }
        
         else if(angulo>= 90 && angulo<100)
        {
            pwmWrite (getPin(), 150);//Setando 90°

        }
        
        //90° a 180°
        
        
        if(angulo>= 100 && angulo<110)
            
        {
            pwmWrite (getPin(), 144.44);//Setando 100°

        }

        else if(angulo>= 110 && angulo<120)
        {
           pwmWrite (getPin(), 138.89);//Setando 110°

        }


        else if(angulo>= 120 && angulo<130)
        {
            pwmWrite (getPin(), 133.33);//Setando 120°

        }

        else if(angulo>= 130 && angulo<140)
        {
            pwmWrite (getPin(), 127.78);//Setando 130°

        }

        else if(angulo>= 140 && angulo<150)
        {
            pwmWrite (getPin(), 122.22);//Setando 140°

        }

        else if(angulo>= 150 && angulo<160)
        {
            pwmWrite (getPin(), 116.66); //Setando 150°

        }

        else if(angulo>= 160 && angulo<170)
        {
            pwmWrite (getPin(), 111.11); //Setando 160°

        }

        else if(angulo>= 170 && angulo<180)
        {
            pwmWrite (getPin(), 105.55); //Setando 170°

        }

        else if(angulo>= 180)
        {
            pwmWrite (getPin(), 100);//Setando 180°

        }
        
             

        else
        {
            cout<<"ERRO: Angulo Inválido!"<<endl;

        }
    }

    else

    {
        cout<<"ERRO: Angulo Inválido!"<<endl;
    }

    
}


const unsigned Servo::getPin()
{
    
    return servoPin;
    
}   


