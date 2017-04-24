#include <iostream>
#include <string>
#include <wiringPi.h>
#include <softPwm.h>
#include "Ultrassom.h"
#include "Servo.h"
#include "MotorDC.h"
#include"Constantes_&_Pinos.h"


using namespace std;


int main(int argc, char *argv[])
{
   
    bool execute = true;
    string cancela;
    int i =0;
    
    
    wiringPiSetup();
	//pwmSetMode(PWM_MODE_MS);    
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
   
   Servo servo1;

   servo1.iniciaServo(SERVO_01);//Pino setado na Constantes_&_Pinos.h
    
    while(execute)
    {
        //cout<<" Saida do Ulltrasom em cm: "<<ultra1->calculaDistancia(30000)<<endl; //Medindo a distancia do ultrassom 
        cout<<"Entrando no laço "<<i<<endl;
		servo1.setAngulo(0);
        delay(200);
        
        servo1.setAngulo(30);
        delay(200);
        
        servo1.setAngulo(60);
        delay(200);
        
        servo1.setAngulo(90);
        delay(200);
        
        servo1.setAngulo(120);
        delay(200);
        
        servo1.setAngulo(150);
        delay(200);
        
        servo1.setAngulo(180);
        delay(200);
        
        servo1.setAngulo(150);
        delay(200);
        
        servo1.setAngulo(120);
        delay(200);
        
        servo1.setAngulo(90);
        delay(200);
        
        servo1.setAngulo(60);
        delay(200);
        
        servo1.setAngulo(30);
        delay(200);
        
        servo1.setAngulo(0);
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
