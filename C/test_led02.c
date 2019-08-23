#include <wiringPi.h>
#include <stdio.h>
#define LED_R 0
#define LED_G 2
#define LED_Y 3

int main (void){
	if (wiringPiSetup() == -1) {
		printf("setup wiringPi failed!");
		return 1;
	}

	pinMode(LED_R, OUTPUT);
	pinMode(LED_G, OUTPUT);
	pinMode(LED_Y, OUTPUT);

	while (1) {
		digitalWrite(LED_R, HIGH);
		digitalWrite(LED_G, LOW);
		digitalWrite(LED_Y, LOW);

		delay(500);

                digitalWrite(LED_R, LOW);
                digitalWrite(LED_G, LOW);
                digitalWrite(LED_Y, LOW);

                delay(500);

                digitalWrite(LED_R, LOW);
                digitalWrite(LED_G, HIGH);
                digitalWrite(LED_Y, LOW);

                delay(500);

                digitalWrite(LED_R, LOW);
                digitalWrite(LED_G, LOW);
                digitalWrite(LED_Y, LOW);

                delay(500);

                digitalWrite(LED_R, LOW);
                digitalWrite(LED_G, LOW);
                digitalWrite(LED_Y, HIGH);

                delay(500);

                digitalWrite(LED_R, LOW);
                digitalWrite(LED_G, LOW);
                digitalWrite(LED_Y, LOW);

                delay(500);

                digitalWrite(LED_R, HIGH);
                digitalWrite(LED_G, HIGH);
                digitalWrite(LED_Y, LOW);

                delay(500);

                digitalWrite(LED_R, LOW);
                digitalWrite(LED_G, LOW);
                digitalWrite(LED_Y, LOW);

                delay(500);

                digitalWrite(LED_R, LOW);
                digitalWrite(LED_G, HIGH);
                digitalWrite(LED_Y, HIGH);

                delay(500);

                digitalWrite(LED_R, LOW);
                digitalWrite(LED_G, LOW);
                digitalWrite(LED_Y, LOW);

                delay(500);


                digitalWrite(LED_R, HIGH);
                digitalWrite(LED_G, LOW);
                digitalWrite(LED_Y, HIGH);

                delay(500);

 		digitalWrite(LED_R, LOW);
                digitalWrite(LED_G, LOW);
                digitalWrite(LED_Y, LOW);

		delay(500);

                digitalWrite(LED_R, HIGH);
                digitalWrite(LED_G, HIGH);
                digitalWrite(LED_Y, HIGH);

                delay(500);

                digitalWrite(LED_R, LOW);
                digitalWrite(LED_G, LOW);
                digitalWrite(LED_Y, LOW);

                delay(500);


	}
	return 0;

}

