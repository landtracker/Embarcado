#include <iostream>
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include"Constantes_&_Pinos.h"
using namespace std;




int main()
{
	int fd = wiringPiI2CSetup(I2CADDR_ARD);
	int in, reg;
	while (1) {
		cout << "Instrucao" << endl; // 0 -> Servo, 1 -> angulo, 2 -> distancia
		cin >> reg;
		cout << "Valor" << endl;
		cin >> in;
		wiringPiI2CWriteReg8(fd, reg, in);
	}
}


