#include "Ultrassom.h"


float Ultrassom::calculaDistancia(){//--Retorna a distância medida
    //--Emite o pulso!
    digitalWrite(_triggerPin, LOW);
    delayMicroseconds(30);
    
    digitalWrite(_triggerPin, HIGH);
    delayMicroseconds(20);
    digitalWrite(_triggerPin, LOW);
    
    
    //Esperando pelo Inicio do ECHO
    while(digitalRead(_echoPin) == LOW);
    
    //Esperando pelo fim do ECHO
    long startTime = micros();
    while(digitalRead(_echoPin) == HIGH);
    long travelTime = micros() - startTime;
    
    //Distancia em cm
    float distance = travelTime / 58;
    
    return distance;
}

void Ultrassom::setTriggerPin(const int triggerIn){
    _triggerPin = triggerIn;
}

void Ultrassom::setEchoPin(const int echoIn){
    _echoPin=echoIn;
}
