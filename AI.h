#ifndef _AI_H_
#define _AI_H_
#include "Ultrassom.h"
#include <iostream>
#include <wiringPi.h>

using namespace std;


class AI {

private:

	Ultrassom US_Esquerda;
	Ultrassom US_Direita;
	Ultrassom US_Meio;

public:

	AI();
	~AI();

	bool VerificaObstaculo();

	int DesvioObstaculo();


};


#endif
