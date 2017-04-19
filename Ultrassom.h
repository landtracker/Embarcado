#ifndef _ULTRASSOM_H_
#define _ULTRASSOM_H_
#include <iostream>
#include <wiringPi.h>
#include <sys/time.h>


class Ultrassom{
    
private:
    int _triggerPin;
    int _echoPin;
    
    volatile long startTimeUsec;
    volatile long endTimeUsec;
    double distanceMeters;
    long travelTimeUsec;
    long now;
    
    //Funcões Privadas
    void setTriggerPin(const int triggerIn);//--Seta pino do trigger
    void setEchoPin(const int echoIn);//--Seta pino do echo
    void recordPulseLength();
    
    
public:
    
    Ultrassom(){};
    
    ~Ultrassom(){};
    
    
    
    float calculaDistancia(int timeout);//--retorna o valor medido pela classe
    void iniciaUltrassom(const int triggerIn, const int echoIn);
    
    
};


#endif


