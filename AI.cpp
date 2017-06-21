#include "AI.h"
#include <math.h>
#include"Constantes_&_Pinos.h"


AI::AI()
{
    US_Direita.iniciaUltrassom(TRIGERPIN_01, ECHOPIN_01);
    US_Esquerda.iniciaUltrassom(TRIGERPIN_02, ECHOPIN_02);
    //US_Meio.iniciaUltrassom(TRIGERPIN_03, ECHOPIN_03);
    
}



AI::~AI()
{
    
}

void AI::setup(Servo *servoC, Servo *servoD, Servo *servoE)
{
    servoCamera = servoC;
    servoDireita = servoD;
    servoEsquerda = servoE;
}


bool AI::VerificaObstaculo()
{
    int distEsq, distDir;
    distEsq = distDir = 0;
    /*printf("AI1!\n");
    cout<<US_Esquerda.calculaDistancia()<<endl<<US_Direita.calculaDistancia()<<endl<<US_Meio.calculaDistancia()<<endl;
    if (US_Esquerda.calculaDistancia() < detect_dist || US_Direita.calculaDistancia() < detect_dist || US_Meio.calculaDistancia() < detect_dist)
    {
	printf("AI!\n");
	cout<<US_Esquerda.calculaDistancia()<<endl<<US_Direita.calculaDistancia()<<endl<<US_Meio.calculaDistancia()<<endl;
	 return true;
    }
    else
        return false;
    */
    
    for (int i = 0; i<5; i++){
    
        distEsq += US_Esquerda.calculaDistancia();
        distDir += US_Direita.calculaDistancia();
        
    }
    distEsq = distEsq / 3;
    distDir = distDir / 3;
    
    cout << "Distancia Direita: "<< distDir << " Distancia Esquerda: " << distEsq << endl;
        
    
    if (distEsq < detect_dist || distDir < detect_dist)
    {
//	cout<<"Ultrassom D: "<<US_Direita.calculaDistancia()<<endl;
//	cout<<"Ultrassom E: "<<US_Esquerda.calculaDistancia()<<endl;
	//servoDireita->setAngulo(0);
	 return true;
    }
    else
        return false;
}

int AI::DesvioObstaculo()
{
    
    
    int distD, distE, barreiraStart_D, barreiraEnd_D, barreiraStart_E, barreiraEnd_E;
    distD = distE = barreiraStart_D = barreiraEnd_D = barreiraStart_E = barreiraEnd_E = 0;
    int BrechaE, BrechaD, anguloStart_D, anguloEnd_D, anguloStart_E, anguloEnd_E;
    BrechaE = BrechaD = 0;
    anguloStart_D = anguloEnd_D = anguloStart_E = anguloEnd_E = -1;
    for (int i = 90; i <= 170; i+=10) 
    {
        cout << "Aki"<< endl;
        servoDireita->setAngulo(i);
        delay(500);
        servoEsquerda->setAngulo(170 - i);
        delay(500);
        distD = US_Direita.calculaDistancia();
        distE = US_Esquerda.calculaDistancia();
        if (distD > barreiraStart_D)
        {
            barreiraStart_D = distD;
            barreiraEnd_D = distD;
            anguloStart_D = i;
        }
        
        else if (distD < barreiraStart_D && distD < barreiraEnd_D) 
        {
            barreiraEnd_D = distD;
            anguloEnd_D = i;
        }
        
        
        else
        {
            
        }
        
        if (distE > barreiraStart_E)
        {
            barreiraStart_E = distE;
            barreiraEnd_E = distE;
            anguloStart_E = i;
        }
        
        else if (distE < barreiraStart_E && distE < barreiraEnd_E)
        {
            barreiraEnd_E = distE;
            anguloEnd_E = i;
        }
        
        
        else
        {
            
        }
        
    }
    BrechaD = sqrt(pow(barreiraStart_D, 2) + pow(barreiraEnd_D, 2) + 2 * barreiraStart_D*barreiraEnd_D*cos(abs(anguloStart_D - anguloEnd_D)*PI / 180));
    BrechaE = sqrt(pow(barreiraStart_E, 2) + pow(barreiraEnd_E, 2) + 2 * barreiraStart_E*barreiraEnd_E*cos(abs(anguloStart_E - anguloEnd_E)*PI / 180));
    servoDireita->Alinhar();
    servoEsquerda->Alinhar();
    cout << "Brecha Esquerda: " << BrechaD << " Brecha Direita: " << BrechaE << endl;
}


