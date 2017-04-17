#include <stdio.h>
#include <wiringPi.h>

// LED Pin - wiringPi pin 0 is BCM_GPIO 17.

#define motorV 0
#define motorD 2
#define servo 1

int main (void)
{
  printf ("Setup\n") ;

  wiringPiSetup ();
  pinMode (motorV, OUTPUT);
  pinMode (motorD, OUTPUT);
  pinMode (servo, PWM_OUTPUT);
  pwmSetMode (PWM_MODE_MS);
  pwmSetClock (192);
  pwmSetRange (2000);
  digitalWrite (motorV, LOW);
  digitalWrite (motorD, LOW);
  pwmWrite (servo, 150);
  printf("Start\n");
  delay(1000);


    printf("Frente\n");
    pwmWrite (servo, 150);
    digitalWrite (motorD, HIGH);  // On
    digitalWrite (motorV, HIGH);
    delay (5000);               // mS
    printf("Stop\n");
    digitalWrite (motorV, LOW);
    delay (5000);
    printf("Traz\n");
    digitalWrite (motorD, LOW);
    digitalWrite (motorV, HIGH);
    delay(5000);
    printf("Stop\n");
    digitalWrite (motorV, LOW);
    delay (5000);
    printf("Esquerda\n");
    pwmWrite (servo, 100);
    delay(500);
    digitalWrite (motorV, HIGH);
    digitalWrite (motorD, HIGH);
    delay (5000);
    printf("Stop\n");
    digitalWrite (motorV, LOW);
    delay(5000);
    printf("Direita\n");
    pwmWrite (servo, 200);
    delay(500);
    digitalWrite (motorD, HIGH);
    digitalWrite (motorV, HIGH);
    delay (5000);

  return 0;
}
