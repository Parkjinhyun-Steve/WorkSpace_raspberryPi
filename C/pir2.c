#include <wiringPi.h>
#include <stdio.h>
#include <softPwm.h>

#define INFRARED 11
#define BUZZER 0
#define MOTER 5
#define LED 1

int main (void) {

    if (wiringPiSetup() == -1) {return 1;}

    pinMode(INFRARED, INPUT);
    pinMode(BUZZER, OUTPUT);
    pinMode(MOTER, OUTPUT);
    pinMode(LED, OUTPUT);
    
    digitalWrite(MOTER, LOW);
    softPwmCreate(MOTER, 0, 200);

    for(;;){

        if(digitalRead(INFRARED) == HIGH) {
            digitalWrite(BUZZER, HIGH);
            softPwmWrite(MOTER, 0);
            digitalWrite(LED, HIGH);
            
        } else{
            digitalWrite(BUZZER, LOW);
            softPwmWrite(MOTER, 120);
            digitalWrite(LED, LOW);
        }

    }
    return 0;
}