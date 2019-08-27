#include <wiringPi.h>
#include <stdio.h>
#include <time.h>
#include <softTone.h>

#define FAN_IA 4   // FAN 4
#define FAN_IB 5   // FAN 5



int timestamp(void) {
    time_t time_now;
    struct tm *tm;
    time(&time_now);
    tm = localtime(&time_now);
    return(printf("%d-%02d-%02d %02d:%02d:%02d ",
    tm->tm_year+1900, tm->tm_mon+1, tm->tm_mday,
    tm->tm_hour, tm->tm_min, tm->tm_sec));

}

int main (void) {
    if(wiringPiSetup()== -1) {return 1;}    
    
    pinMode(FAN_IA, OUTPUT);
    pinMode(FAN_IB, OUTPUT);

    digitalWrite(FAN_IA,LOW);  // FAN
    digitalWrite(FAN_IB,LOW);

    while(1){
        digitalWrite(FAN_IA,LOW);  // FAN
        digitalWrite(FAN_IB,HIGH);
        timestamp();
        
        delay(1000);
    }        
                
    return 0;
}