#include "Ultrassom.h"

Ultrassom::Ultrassom()

{
    triggerPin = -1;
    echoPin = -1;
    
}



Ultrassom::~Ultrassom()

{
    triggerPin = -1;
    echoPin = -1;
}


void Ultrassom::iniciaUltrassom(const int _triggerIn, const int _echoIn)
{
    wiringPiSetup(); 
    setTriggerPin(_triggerIn);
    setEchoPin(_echoIn);
    
    pinMode(triggerPin, OUTPUT);
    pinMode(echoPin, INPUT);
    digitalWrite(triggerPin, LOW);
    delay(50);
    
    
}


int Ultrassom::calculaDistancia(){//--Retorna a distância medida
    
    
    
    
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(5);
    
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    
    digitalWrite(triggerPin, LOW);
    
    now=micros();
    
    while (digitalRead(echoPin) == LOW && micros()-now<timeout)
    {
        
    }
    retornoEcho();
    
    travelTime = endTime - startTime;
    distancia = 100*((travelTime/1000000.0)*VELOCIDADE_DO_SOM)/2;  
    
    
    //Distancia em cm
    if (distancia > 100)
        return 100;
    else
        return distancia;
}

int Ultrassom::calculaDistanciaCorrigida()
{
    int leituras = 0;
    int err1 = 0;
    int err2 = 0;
    int i = 0;
    
    while (i<3){
        err1 = calculaDistancia();
        if (err1> 10){
            if (abs(err1-err2) < 10 && i>0)
            {
                leituras += err1;
                err2 = err1;
                i++;
            }
            else
            {
                leituras += err1;
                err2 = err1;
                i++;
            }
        }
        delay(50);
    }
    
    return leituras/3;
}




 void Ultrassom::retornoEcho()
{
    startTime = micros();
    while ( digitalRead(echoPin) == HIGH );
    endTime = micros();
}


void Ultrassom::setTriggerPin(const int _triggerIn){
    triggerPin = _triggerIn;
}

void Ultrassom::setEchoPin(const int _echoIn){
    echoPin=_echoIn;
}


