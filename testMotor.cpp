#include <stdio.h>
#include <wiringPi.h>

// LED Pin - wiringPi pin 0 is BCM_GPIO 17.
//g++ -o test testMotor.cpp -lwiringPi

#define motorV 0
#define motorD 2
#define servo 1
#define powerBtn 3

int main (void)
{
  bool activate = true;
  printf ("Setup\n") ;
  wiringPiSetup ();
  pinMode (motorV, OUTPUT);
  pinMode (motorD, OUTPUT);
  pinMode (servo, PWM_OUTPUT);
  pwmSetMode (PWM_MODE_MS);
  pinMode (powerBtn, INPUT);
  pwmSetClock (192);
  pwmSetRange (2000);
  digitalWrite (motorV, LOW);
  digitalWrite (motorD, LOW);
  pwmWrite (servo, 152);

while (1)
{
	while (!activate)
		if(powerBtn == HIGH)
			activate = true;

	printf("Start\n");
    	delay (1000);
   	printf("Frente\n");
    	pwmWrite (servo, 152);
    	digitalWrite (motorD, HIGH);  // On
    	digitalWrite (motorV, HIGH);
    	delay (5000);               // mS
    	printf("Stop\n");
    	digitalWrite (motorV, LOW);
    	delay (3000);
    	printf("Traz\n");
    	digitalWrite (motorD, LOW);
    	digitalWrite (motorV, HIGH);
    	delay(5000);
    	printf("Stop\n");
    	digitalWrite (motorV, LOW);
    	delay (3000);
    	printf("Esquerda\n");
    	pwmWrite (servo, 100);
    	delay(200);
	pwmWrite (servo, 152);
    	digitalWrite (motorV, HIGH);
    	digitalWrite (motorD, HIGH);
    	delay (5000);
    	printf("Stop\n");
    	digitalWrite (motorV, LOW);
    	delay(1000);
    	printf("Direita\n");
    	pwmWrite (servo, 204);
    	delay(400);
	pwmWrite (servo, 152);
    	digitalWrite (motorD, HIGH);
    	digitalWrite (motorV, HIGH);
    	delay (5000);
	pwmWrite (servo, 100);
	delay (210);
	pwmWrite (servo, 152);
//	activate = false;
 }
 return 0;
}
