#include "Ultrassom.h"



void Ultrassom::iniciaUltrassom(const int triggerIn, const int echoIn)
{
    
    setTriggerPin(triggerIn);
    setEchoPin(echoIn);
    
    pinMode(_triggerPin, OUTPUT);
    pinMode(_echoPin, INPUT);
    digitalWrite(_triggerPin, LOW);
    delay(500);
    
    
}


float Ultrassom::calculaDistancia(int timeout){//--Retorna a distância medida
    
    float distancia;
    
    delay(10);
    //--Emite o pulso!
    digitalWrite(_triggerPin, LOW);
    delayMicroseconds(30);
    
    digitalWrite(_triggerPin, HIGH);
    delayMicroseconds(20);
    digitalWrite(_triggerPin, LOW);
    
     now=micros();
     
     
    while (digitalRead(_echoPin) == LOW && micros()-now<timeout);
    {
    recordPulseLength();

    travelTimeUsec = endTimeUsec - startTimeUsec;
    distancia = 100*((travelTimeUsec/1000000.0)*340.29)/2;
    
    }
    //Distancia em cm   
    return distancia;
}

void Ultrassom::setTriggerPin(const int triggerIn){
    _triggerPin = triggerIn;
}

void Ultrassom::setEchoPin(const int echoIn){
    _echoPin=echoIn;
}




void Ultrassom::recordPulseLength()
{
    startTimeUsec = micros();
    while ( digitalRead(_echoPin) == HIGH );
    endTimeUsec = micros();
}
