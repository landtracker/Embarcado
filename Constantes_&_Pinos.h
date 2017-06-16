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

const unsigned I2CADDR_ARD = 0x04;
const unsigned I2CADDR_GYRO = 0x68;

//Pinos do Ultrassom
const int TRIGERPIN_01 = 4;//Gpio da Biblioteca wiringiPi
const int ECHOPIN_01 = 5;
const int TRIGERPIN_02 = 6;//Gpio da Biblioteca wiringiPi
const int ECHOPIN_02 = 7;
const int TRIGERPIN_03 = 8;//Gpio da Biblioteca wiringiPi
const int ECHOPIN_03 = 9;

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

//Pino Controle Delay Arduino

const unsigned SIGPIN_ARD = 10;

//Pino interrupcao

const unsigned INTERRUPT_A = 11;




//Pinos motor

const unsigned MOTOR_VEL = 0; //Pino de pwm do motor DC
const unsigned MOTOR_DIR = 2; //Pino de direcao do motor DC






//--CONSTANTES DE SISTEMA

 // Velocidade do som 340,29 m/s -&gt; 34029 cm/s
 #define   VELOCIDADE_DO_SOM  34029




#endif //-- Definicoes


