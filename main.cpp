#include "Ultrassom.h"
#include"Pinagem.h"
#include <iostream>
#include <wiringPi.h>

using namespace std;


int main(int argc, char *argv[])
{
    if (wiringPiSetup() <= 0)
    {
        return -1;
        cout<<"Pino Invalido!"<<endl;
    }
    
    Ultrassom ultra1;
    ultra1.iniciaUltrassom(TRIGERPIN_01, ECHOPIN_01);
    
    while(1)
    {
        cout<<" Saida do Ulltrasom em cm: "<<ultra1.calculaDistancia(30000)<<endl;    
        delay(300);
    }
    
    return 0;
}
