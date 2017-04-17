#include "Ultrassom.h"
#include"Pinagem.h"
#include <iostream>
#include<string>
#include <wiringPi.h>

using namespace std;


int main(int argc, char *argv[])
{
   
    bool execute = true;
    string cancela;
    
    wiringPiSetup();
   
    Ultrassom ultra1;//Objeto do Ultrassom
    ultra1.iniciaUltrassom(TRIGERPIN_01, ECHOPIN_01);//Pinos trigger e echo setados na Pinagem.h
    
    while(execute)
    {
        cout<<" Saida do Ulltrasom em cm: "<<ultra1.calculaDistancia(30000)<<endl; //Medindo a distancia do ulytrassom 
        delay(300);
        
        
        cin >> cancela;    
        if(cancela == "c")
        {
            execute = false;
            break;
        }
        
    }
    
    cout<<"Encerrando o programa"<<endl;
    
   
    return 0;
}
