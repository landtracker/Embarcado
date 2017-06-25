#ifndef _AI_H_
#define _AI_H_
#include "Ultrassom.h"
#include "Servo.h"
#include <iostream>
#include <wiringPi.h>
#include <vector>
#include "Comando.h"

const int detect_dist = 20;


using namespace std;


class AI {
    
private:
    
    Ultrassom US_Esquerda;
    Ultrassom US_Direita;
    Ultrassom US_Meio;
    Servo *servoCamera;
    Servo *servoDireita;
    Servo *servoEsquerda;
    
public:
    
    AI();
    ~AI();
    void setup(Servo *servoC, Servo *servoD, Servo *servoE);
    bool VerificaObstaculo();
    
    vector<Comando> DesvioObstaculo();
    
    
};


#endif
