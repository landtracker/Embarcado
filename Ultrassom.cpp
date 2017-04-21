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
    delay(500);
    
    
}


float Ultrassom::calculaDistancia(int timeout){//--Retorna a distância medida
    
    float distancia;
    
    delay(10);
    //--Emite o pulso!
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(30);
    
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(20);
    digitalWrite(triggerPin, LOW);
    
     now=micros();
     
     
    while (digitalRead(echoPin) == LOW && micros()-now<timeout);
    {
    recordPulseLength();

    travelTimeUsec = endTimeUsec - startTimeUsec;
    distancia = 100*((travelTimeUsec/1000000.0)*340.29)/2;
    
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


void Ultrassom::recordPulseLength()
{
    startTimeUsec = micros();
    while ( digitalRead(echoPin) == HIGH );
    endTimeUsec = micros();
}


const unsigned Ultrassom::getTriggerPin()
{
    
    return triggerPin;
}
const unsigned Ultrassom::getTriggerEcho()
{
 return echoPin;   
}
