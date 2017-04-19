#ifndef PINAGEM_H
#define PINAGEM_H

/*------------------------------------
 * Pinos do Pi utilizados no projeto
 * Os pinos serão mapeados de acordo
 * com a biblioteca wiringiPi
 * Para localizar utilize o comando
 * gpio readall 
 * __________________________________
 */


//Pinos do Ultrassom
const int TRIGERPIN_01 = 4;//Gpio da Biblioteca wiringiPi
const int ECHOPIN_01 = 5; 


//Pinos Servo

const unsigned SERVO_01 = 1;


//Pinos motor








//--CONSTANTES DE SISTEMA

 // Velocidade do som 340,29 m/s -&gt; 34029 cm/s
 #define   VELOCIDADE_DO_SOM  34029




#endif //-- Definicoes


