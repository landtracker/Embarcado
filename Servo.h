#ifndef _SERVO_H_
#define _SERVO_H_

#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>//Para usar em pinos GPIO (sem PWM eletronico nativo)

using namespace std;



class Servo{
    
private:
    
    int servoPin;
    unsigned pwm;
    unsigned range;
    unsigned angulo;
    
    void setServoPin(const int _servoIn);//--Seta pino do trigger
    void setClock(const unsigned _pwm);
    void setRange(const unsigned _range);
    
    
    
public:
    
    
    Servo();
    ~Servo();
    
    void iniciaServo(const int _servoIn);   
    void setAngulo(const unsigned _angulo);
    
    const unsigned getPin();
    
    
};


#endif
