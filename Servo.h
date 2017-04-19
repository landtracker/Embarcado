#ifndef _SERVO_H_
#define _SERVO_H_


#include <wiringPi.h>
#include <iostream>



class Servo{
    
private:
    
    int _servoPin;
    unsigned _pwm;
    unsigned _range;
    unsigned _angulo;
    
    void setServoPin(const int servoIn);//--Seta pino do trigger
    
    
    
public:
    
    
    Servo();
    ~Servo();
    
    void iniciaServo(const int servoIn);
    void setClock(const unsigned pwm);
    void setRange(const unsigned range);
    void setAngulo(const unsigned angulo);
    
    const int getPin();
    
    
};


#endif
