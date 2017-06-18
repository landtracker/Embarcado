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
    double acclX_scaled, acclY_scaled, acclZ_scaled, temp, temperatura;
    float eixoX, eixoY;
    
    
public:
    
    Giroscopio();
    
    int read_word_2c(int addr);    
    double dist(double a, double b);    
    void set_y_rotation(const double x, const double y, const double z);    
    void set_x_rotation(const double x, const double y, const double z);  
    void readEixos();
    void  setTemp(const double temp);
    float getTemp();
    float get_y_rotation();    
    float get_x_rotation();  
};

#endif
