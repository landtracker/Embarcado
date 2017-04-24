#ifndef _MOTORDC_H_
#define _MOTORDC_H_

#include <iostream>
#include <wiringPi.h>

using namespace std;


class MotorDC{
    
private:
    
    unsigned velPin;    
	unsigned dirPin;

    
    
    
public:
    
    
    MotorDC(unsigned vel, unsigned dir);
    ~MotorDC();
    
    void Frente(const unsigned _duracao);   
    void Traz(const unsigned _duracao);
	void Stop();

    
    
};


#endif
