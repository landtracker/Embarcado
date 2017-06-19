#ifndef _ULTRASSOM_H_
#define _ULTRASSOM_H_
#include <iostream>
#include <wiringPi.h>
#include <sys/time.h>
#include"Constantes_&_Pinos.h"

using namespace std;

const unsigned timeout = 30000;


class Ultrassom{
    
private:
    int triggerPin;
    int echoPin;
    volatile long startTime;
    volatile long endTime;
    int distancia;
    long travelTime;
    long now;
    


    
    
   
    //Funcões Privadas
    void setTriggerPin(const int _triggerIn);//--Seta pino do trigger
    void setEchoPin(const int _echoIn);//--Seta pino do echo
    void retornoEcho();
    
    
    
public:
    
    Ultrassom();    
    ~Ultrassom();
    
    
    
    void iniciaUltrassom(const int _triggerIn, const int _echoIn);
    int calculaDistancia();//--retorna o valor medido pela classe

    
    
};


#endif


