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
    ultra1.setTriggerPin(TRIGERPIN_01);//Pinos definidos na Pinagem.h
    ultra1.setEchoPin(ECHOPIN_01);
    
    while(1)
    {
        cout<<" Saida do Ulltrasom em cm: "<<ultra1.calculaDistancia()<<endl;    
        delay(300);
    }
    
    return 0;
}
