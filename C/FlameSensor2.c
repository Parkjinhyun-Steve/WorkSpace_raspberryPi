#include <wiringPi.h>
#include <stdio.h>
#include <time.h>

#define FLAME 0

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
    
    pinMode(FLAME, INPUT);    

    while(1){
        timestamp();
        delay(1000);
        
        if(digitalRead(FLAME)==HIGH){
            printf("안전\n");

        }else
            printf("화재경보\n");            
        }        
        
    return 0;
}