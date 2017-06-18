#ifndef _ULTRASSOM_H_
#define _ULTRASSOM_H_
#include <iostream>
#include <wiringPi.h>
#include <sys/time.h>


class Ultrassom{
    
private:
    int triggerPin;
    int echoPin;
    
   
    //Funcões Privadas
    void setTriggerPin(const int _triggerIn);//--Seta pino do trigger
    void setEchoPin(const int _echoIn);//--Seta pino do echo
    void recordPulseLength();
    
    
    
public:
    
    Ultrassom();    
    ~Ultrassom();
    
    
    
    void iniciaUltrassom(const int _triggerIn, const int _echoIn);
    int calculaDistancia();//--retorna o valor medido pela classe
    
    
};


#endif


