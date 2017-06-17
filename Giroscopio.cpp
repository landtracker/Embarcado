#include "Giroscopio.h"
#include "Constantes_&_Pinos.h"


Giroscopio::Giroscopio()
{
    
    fd = wiringPiI2CSetup (I2CADDR_GYRO);
    wiringPiI2CWriteReg8 (fd,0x6B,0x00);//disable sleep mode 
    acclX = read_word_2c(0x3B);
    acclY = read_word_2c(0x3D);
    acclZ = read_word_2c(0x3F);
     
}


int Giroscopio::read_word_2c(int addr)
{
    int val;
    val = wiringPiI2CReadReg8(fd, addr);
    val = val << 8;
    val += wiringPiI2CReadReg8(fd, addr+1);
    if (val >= 0x8000)
        val = -(65536 - val);
    
    return val;
}

double Giroscopio::dist(double a, double b)
{
    return sqrt((a*a) + (b*b));
}

void Giroscopio::set_y_rotation(const double x, const double y, const double z)
{
    double radians;
    radians = atan2(x, dist(y, z));
    eixoY = -(radians * (180.0 / M_PI));
}

void Giroscopio::set_x_rotation(const double x, const double y, const double z)
{
    double radians;
    radians = atan2(y, dist(x, z));
    eixoX = (radians * (180.0 / M_PI));
}

const float Giroscopio::get_y_rotation() 
{
    return  eixoY;
}


const float Giroscopio::get_x_rotation() 
{
     return  eixoX;
}

void Giroscopio::readEixos()
{
     acclX = read_word_2c(0x3B);
     acclY = read_word_2c(0x3D);
     acclZ = read_word_2c(0x3F);
     
     acclX_scaled = acclX / 16384.0;
     acclY_scaled = acclY / 16384.0;
     acclZ_scaled = acclZ / 16384.0;
     
    set_x_rotation(acclX_scaled, acclY_scaled, acclZ_scaled);
    set_y_rotation(acclX_scaled, acclY_scaled, acclZ_scaled);     
    
}


/*
 i n*t main()
 {
 fd = wiringPiI2CSetup (0x68);
 wiringPiI2CWriteReg8 (fd,0x6B,0x00);//disable sleep mode 
 printf("set 0x6B=%X\n",wiringPiI2CReadReg8 (fd,0x6B));
 
 
 
 while(1) {
     
     acclX = read_word_2c(0x3B);
     acclY = read_word_2c(0x3D);
     acclZ = read_word_2c(0x3F);
     
     acclX_scaled = acclX / 16384.0;
     acclY_scaled = acclY / 16384.0;
     acclZ_scaled = acclZ / 16384.0;
     
     printf("My acclX_scaled: %f\n", acclX_scaled);
     printf("My acclY_scaled: %f\n", acclY_scaled);
     printf("My acclZ_scaled: %f\n", acclZ_scaled);
     
     printf("My X rotation: %f\n", get_x_rotation(acclX_scaled, acclY_scaled, acclZ_scaled));
     printf("My Y rotation: %f\n", get_y_rotation(acclX_scaled, acclY_scaled, acclZ_scaled));
     
     
     delay(100);
     }
     return 0;
     }
     
     */
