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
    
    setTriggerPin(_triggerIn);
    setEchoPin(_echoIn);
    
    pinMode(triggerPin, OUTPUT);
    pinMode(echoPin, INPUT);
    digitalWrite(triggerPin, LOW);
    delay(50);
    
    
}


int Ultrassom::calculaDistancia(){//--Retorna a distância medida
    
    int distancia = -1;
    long unsigned startTime = 0;
    long unsigned travelTime = 0;
    
    digitalWrite(getTriggerPin(), LOW);
    delayMicroseconds(5);
    
    digitalWrite(getTriggerPin(), HIGH);
    delayMicroseconds(10);
    
    digitalWrite(getTriggerPin(), LOW);
    
    //Esperando o retorno do som
    while(digitalRead(echoPin) == LOW){
        
        //Esperando o retorno do som
        startTime = micros();
    }
    while(digitalRead(echoPin) == HIGH)
    {
        travelTime = micros() - startTime;
        
        //Get distance in cm
        distancia = ((travelTime/2) / 29.1);
        //distancia = ((100*(travelTime/1000000)*330) /2);
    }
    
    
    
    //Distancia em cm   
    return distancia;
}

void Ultrassom::setTriggerPin(const int _triggerIn){
    triggerPin = _triggerIn;
}

void Ultrassom::setEchoPin(const int _echoIn){
    echoPin=_echoIn;
}



const unsigned Ultrassom::getTriggerPin()
{
    
    return triggerPin;
}
const unsigned Ultrassom::getTriggerEcho()
{
    return echoPin;   
}
