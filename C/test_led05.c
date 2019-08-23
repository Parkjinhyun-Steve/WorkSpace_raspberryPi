#include <wiringPi.h>
#include <stdio.h>

// 차량 신호 정의
#define LED_R1 0
#define LED_Y1 2
#define LED_G1 3

// 보행자 신호 정의
#define LED_R2 4
#define LED_G2 5


// 메인 함수
int main (void){
	if (wiringPiSetup() == -1) {
		printf("setup wiringPi failed!");
		return 1;
	}

// 차량 신호 pinMode 정의
	pinMode(LED_R1, OUTPUT);
	pinMode(LED_Y1, OUTPUT);
	pinMode(LED_G1, OUTPUT);

// 보행자 신호 pinMode 정의
	pinMode(LED_R2, OUTPUT);
	pinMode(LED_G2, OUTPUT);


// 신호 무한반복
	while (1) {

		digitalWrite(LED_R2, HIGH);  // 보행자 빨
		digitalWrite(LED_G2, LOW);

		delay(500);  // 보

		digitalWrite(LED_R1, LOW);   
		digitalWrite(LED_Y1, LOW);
		digitalWrite(LED_G1, HIGH);  // 차량 녹

		delay(5000);  

		digitalWrite(LED_R1, LOW);
		digitalWrite(LED_Y1, HIGH); // 차량 노
		digitalWrite(LED_G1, LOW);

		delay(1000);

		digitalWrite(LED_R1, HIGH);  // 차량 빨
		digitalWrite(LED_Y1, LOW);
		digitalWrite(LED_G1, LOW);

		delay(500);

		digitalWrite(LED_R2, LOW);  
		digitalWrite(LED_G2, HIGH); // 보행자 파

		delay(3000);

// 보행자 신호 8회 깜빡임
	for (int i = 0; i < 8 ; i++) {    
		digitalWrite(LED_R2, LOW);
		digitalWrite(LED_G2, LOW);  // 보행자 녹 (깜빡임)

		delay(100);	

		digitalWrite(LED_R2, LOW);
		digitalWrite(LED_G2, HIGH);  // 보행자 녹 (깜빡임)

		delay(100);			
		}
	}	
	return 0;
}
	






