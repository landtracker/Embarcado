#ifndef _ULTRASSOM_H_
#define _ULTRASSOM_H_

#include <wiringPi.h>

class Ultrassom{
    
private:
    int _triggerPin;
    int _echoPin;
    
public:
    
    Ultrassom()
    {
        pinMode(_triggerPin, OUTPUT);
        pinMode(_echoPin, INPUT);   
        
    };
    
    ~Ultrassom(){};
    
    
    float calculaDistancia();//--retorna o valor medido pela classe
    void setTriggerPin(const int triggerIn);//--Seta pino do trigger
    void setEchoPin(const int echoIn);//--Seta pino do echo
};


#endif
