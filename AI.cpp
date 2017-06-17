#include "AI.h"
#include"Constantes_&_Pinos.h"


AI::AI()
{
	US_Direita.iniciaUltrassom(TRIGERPIN_01, ECHOPIN_01);
	US_Esquerda.iniciaUltrassom(TRIGERPIN_02, ECHOPIN_02);
	US_Meio.iniciaUltrassom(TRIGERPIN_03, ECHOPIN_03);

}



AI::~AI()
{

}



bool AI::VerificaObstaculo()
{
	if (US_Esquerda.calculaDistancia(1000) < 50 || US_Direita.calculaDistancia(1000) < 50 || US_Meio.calculaDistancia(1000) > 50)
		return true
	else
		return false;
}

int AI::DesvioObstaculo()
{

}


