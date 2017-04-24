#ifndef PINAGEM_H
#define PINAGEM_H

/*------------------------------------
 * Pinos do Pi utilizados no projeto
 * Os pinos serão mapeados de acordo
 * com a biblioteca wiringiPi
 * Para localizar utilize o comando
 * gpio readall 
 * 
 * 
 * Neste arquivo também estão descritos
 * algumas constantes do Sistema
 * __________________________________
 */


//Pinos do Ultrassom
const int TRIGERPIN_01 = 4;//Gpio da Biblioteca wiringiPi
const int ECHOPIN_01 = 5; 

//PWM servo Motor
/*
 * Cálculo do PWM do Servo motor:
 *pwmFrequency in Hz = 19.2e6 Hz / pwmClock / pwmRange.
 * 
 * Frequência do Servo: 19.2e6 Hz/192/2000
 * 
 */

const unsigned PWMCLOCK = 192;
const unsigned PWMRANGE = 2000;


//Pinos Servo

const unsigned SERVO_01 = 1;//Gpio da Biblioteca wiringiPi


//Pinos motor

const unsigned MOTOR_VEL = 0; //Pino de pwm do motor DC
const unsigned MOTOR_DIR = 2; //Pino de direcao do motor DC






//--CONSTANTES DE SISTEMA

 // Velocidade do som 340,29 m/s -&gt; 34029 cm/s
 #define   VELOCIDADE_DO_SOM  34029




#endif //-- Definicoes


