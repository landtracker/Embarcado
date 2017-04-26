#ifndef _SERVO_H_
#define _SERVO_H_

#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>//Para usar em pinos GPIO (sem PWM eletrônico nativo)

using namespace std;



class Servo{
    
private:
    
    int servoPin;
    unsigned pwm;
    unsigned range;
    unsigned angulo;
    int flag;
    
    void setServoPin(const int _servoIn);//--Seta pino de controle
    
    
    
public:
    
    
    Servo();
    ~Servo();
    
    void iniciaServo(const int _servoIn, const int _flag);   
    void setAngulo(const unsigned _angulo);
    void setFlag(const int _flag);
	void varreduraD();
	void varreduraE();
};


#endif
