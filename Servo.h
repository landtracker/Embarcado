#ifndef _SERVO_H_
#define _SERVO_H_

#include <iostream>
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>

using namespace std;
const unsigned i2cAddress = 0x04;




class Servo{
    
private:
    
    int servoPin;
    unsigned pwm;
    unsigned range;
    unsigned angulo;
    unsigned servoArduino;
    bool flagArduino;
    
    void setServoPin(const int _servoIn);//--Seta pino de controle
    void setAnguloServoArduino(const unsigned _angulo);

    
    
    
public:
    
    
    Servo();
    ~Servo();
    
    void iniciaServo(const int _servoIn);
    void iniciaServoArduino(const int _servoIn);
    
    void setAngulo(const unsigned _angulo);
    void Alinhar();
    void varreduraD();
    void varreduraE();
    void setFlagArduino(const bool _flag); 
    const bool getFlag() const;
    unsigned getAngulo();
    void Direita();
    void Esquerda();
};


#endif
