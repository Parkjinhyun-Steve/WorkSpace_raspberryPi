#include <wiringPi.h>
#include <stdio.h>
#define SWITCH 1
// wPi. 1(GPIO.1), BCM.18, Physical-Pin. 12
#define LED 4
// wPi. 4(GPIO.4), BCM.23, Physical-Pin. 16

int main (void) {
	if (wiringPiSetup() == -1) {
		// wiringPiSetup를 불러오지 못했을 경우
		printf("setup wiringPi failed!");
		// 에러로그 출력
		return 1;
		// 비정상 종료
	}

	pinMode(SWITCH, INPUT);
	// SWICH를 INPUT으로 받아 들임
	pinMode(SWITCH, PUD_DOWN);  //풀다운 저항 설정
	pinMode(LED, OUTPUT); // LED는 OUTPUT으로 설정

	for (;;) {  // 무한루프
		if(digitalRead(SWITCH) == 1) {  // 스위치를 눌렀을때
			digitalWrite(LED, HIGH);  // LED켜짐
		} else {
			//스위치를 누르지 않고 있을 때
			digitalWrite(LED, LOW);  // LED꺼짐
		}
	}
	return 0;

}