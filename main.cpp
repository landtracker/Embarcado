#include <iostream>
#include <string>
#include <wiringPi.h>
//#include <softPwm.h>
#include "Ultrassom.h"
#include "Servo.h"
#include "MotorDC.h"
#include"Constantes_&_Pinos.h"


using namespace std;


int main(int argc, char *argv[])
{
   
    bool execute = true;
    string cancela;
    int i =1;
    
    
    //wiringPiSetup(); Funcao sendo chamada 2 vezes
    if(wiringPiSetup()<0)
    {
        
        execute = false;
        cout<<"Erro na Biblioteca wiringPi"<<endl;
        
        return 1;
        
    }
   
   
   /*
   Ultrassom *ultra1;//Objeto do Ultrassom
    ultra1 = new Ultrassom();
    
    ultra1->iniciaUltrassom(TRIGERPIN_01, ECHOPIN_01);//Pinos trigger e echo setados na Constantes_&_Pinos.h
    */
   
   Servo servo1;

   //servo1.iniciaServo(SERVO_01, 0);//Pino setado na Constantes_&_Pinos.h
   servo1.iniciaServo(SERVO_02, 1);//Pino de acordo com a biblioteca GPIO e uso de softPwm
    
    while(execute)
    {
        //cout<<" Saida do Ulltrasom em cm: "<<ultra1->calculaDistancia(30000)<<endl; //Medindo a distancia do ultrassom 
        cout<<"Entrando no laço "<<i<<endl;


        

		delay(200);
        cout<<"Servo virando a Direita"<<endl;
		servo1.varreduraD();
        
		delay(200);
        cout<<"Servo virando a Esquerda"<<endl;

		servo1.varreduraE();
		delay(200);
		


       // cin >> cancela;   
        /*
        if(cancela == "c")
        {
            execute = false;
            delete(servo1);
            //delete(ultra1);
        }*/
	i++;
        
    }
    
    cout<<"Encerrando o programa. Fim da execução do Sistema embarcado"<<endl;
    
   
    return 0;
}
