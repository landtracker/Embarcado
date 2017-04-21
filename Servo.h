#ifndef _SERVO_H_
#define _SERVO_H_


#include <wiringPi.h>
#include <iostream>



class Servo{
    
private:
    
    int servoPin;
    unsigned pwm;
    unsigned range;
    unsigned angulo;
    
    void setServoPin(const int _servoIn);//--Seta pino do trigger
    
    
    
public:
    
    
    Servo();
    ~Servo();
    
    void iniciaServo(const int _servoIn);
    void setClock(const unsigned _pwm);
    void setRange(const unsigned _range);
    void setAngulo(const unsigned _angulo);
    
    const unsigned getPin();
    
    
};


#endif
