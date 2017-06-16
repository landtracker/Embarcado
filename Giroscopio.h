#ifndef _Giroscopio_H_
#define _Giroscopio_H_

#include  <wiringPiI2C.h>
#include  <wiringPi.h>
#include  <stdio.h>
#include  <math.h>

using namespace std;


//Código de compilação

// g++ -W -o giroscopio giroscopio.cpp -lwiringPi  -lpthread

class Giroscopio
{
private:
    
    int fd;
    int acclX, acclY, acclZ;
    double acclX_scaled, acclY_scaled, acclZ_scaled;
    float eixoX, eixoY;
    
    
public:
    
    Giroscopio();
    
    int read_word_2c(int addr);    
    double dist(double a, double b);    
    void set_y_rotation(const double x, const double y, const double z);    
    void set_x_rotation(const double x, const double y, const double z);  
    void readEixos();
    
    const float get_y_rotation();    
    const float get_x_rotation();  
};

#endif
