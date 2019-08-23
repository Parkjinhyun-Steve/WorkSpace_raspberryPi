#include <wiringPi.h>
#include <stdio.h>
#define SWITCH 1
// wPi. 1(GPIO.1), BCM.18, Physical-Pin. 12
#define LED 4
// wPi. 4(GPIO.4), BCM.23, Physical-Pin. 16

int main (void) {
	if (wiringPiSetup() == -1) {
		// wiringPiSetup�� �ҷ����� ������ ���
		printf("setup wiringPi failed!");
		// �����α� ���
		return 1;
		// ������ ����
	}

	pinMode(SWITCH, INPUT);
	// SWICH�� INPUT���� �޾� ����
	pinMode(SWITCH, PUD_DOWN);  //Ǯ�ٿ� ���� ����
	pinMode(LED, OUTPUT); // LED�� OUTPUT���� ����

	for (;;) {  // ���ѷ���
		if(digitalRead(SWITCH) == 1) {  // ����ġ�� ��������
			digitalWrite(LED, HIGH);  // LED����
		} else {
			//����ġ�� ������ �ʰ� ���� ��
			digitalWrite(LED, LOW);  // LED����
		}
	}
	return 0;

}