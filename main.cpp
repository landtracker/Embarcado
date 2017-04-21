#include <iostream>
#include<string>
#include <wiringPi.h>
#include <softPwm.h>
#include "Ultrassom.h"
#include "Servo.h"
#include"Constantes_&_Pinos.h"


using namespace std;


int main(int argc, char *argv[])
{
   
    bool execute = true;
    string cancela;
    
    
    wiringPiSetup();    
    if(wiringPiSetup()==-1)
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
   
   Servo *servo1;
   servo1 = new Servo();
   servo1->iniciaServo(SERVO_01);//Pino setado na Constantes_&_Pinos.h
    
    while(execute)
    {
        //cout<<" Saida do Ulltrasom em cm: "<<ultra1->calculaDistancia(30000)<<endl; //Medindo a distancia do ultrassom 
        servo1->setAngulo(0);
        delay(300);
        
        servo1->setAngulo(30);
        delay(300);
        
        servo1->setAngulo(60);
        delay(300);
        
        servo1->setAngulo(90);
        delay(300);
        
        servo1->setAngulo(120);
        delay(300);
        
        servo1->setAngulo(150);
        delay(300);
        
        servo1->setAngulo(180);
        delay(300);
        
        servo1->setAngulo(150);
        delay(300);
        
        servo1->setAngulo(120);
        delay(300);
        
        servo1->setAngulo(90);
        delay(300);
        
        servo1->setAngulo(60);
        delay(300);
        
        servo1->setAngulo(30);
        delay(300);
        
        servo1->setAngulo(0);
        delay(300);
         
        
        cin >> cancela;   
        
        if(cancela == "c")
        {
            execute = false;
            delete(servo1);
            //delete(ultra1);
        }
        
    }
    
    cout<<"Encerrando o programa. Fim da execução do Sistema embarcado"<<endl;
    
   
    return 0;
}
