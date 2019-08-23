#include <wiringPi.h>
#include <stdio.h>

// ���� ��ȣ ����
#define LED_R1 0
#define LED_Y1 2
#define LED_G1 3

// ������ ��ȣ ����
#define LED_R2 4
#define LED_G2 5


// ���� �Լ�
int main (void){
	if (wiringPiSetup() == -1) {
		printf("setup wiringPi failed!");
		return 1;
	}

// ���� ��ȣ pinMode ����
	pinMode(LED_R1, OUTPUT);
	pinMode(LED_Y1, OUTPUT);
	pinMode(LED_G1, OUTPUT);

// ������ ��ȣ pinMode ����
	pinMode(LED_R2, OUTPUT);
	pinMode(LED_G2, OUTPUT);


// ��ȣ ���ѹݺ�
	while (1) {

		digitalWrite(LED_R2, HIGH);  // ������ ��
		digitalWrite(LED_G2, LOW);

		delay(500);  // ��

		digitalWrite(LED_R1, LOW);   
		digitalWrite(LED_Y1, LOW);
		digitalWrite(LED_G1, HIGH);  // ���� ��

		delay(5000);  

		digitalWrite(LED_R1, LOW);
		digitalWrite(LED_Y1, HIGH); // ���� ��
		digitalWrite(LED_G1, LOW);

		delay(1000);

		digitalWrite(LED_R1, HIGH);  // ���� ��
		digitalWrite(LED_Y1, LOW);
		digitalWrite(LED_G1, LOW);

		delay(500);

		digitalWrite(LED_R2, LOW);  
		digitalWrite(LED_G2, HIGH); // ������ ��

		delay(3000);

// ������ ��ȣ 8ȸ ������
	for (int i = 0; i < 8 ; i++) {    
		digitalWrite(LED_R2, LOW);
		digitalWrite(LED_G2, LOW);  // ������ �� (������)

		delay(100);	

		digitalWrite(LED_R2, LOW);
		digitalWrite(LED_G2, HIGH);  // ������ �� (������)

		delay(100);			
		}
	}	
	return 0;
}
	






