#include <wiringPi.h>
#include <stdio.h>
#include <time.h>
#include <softTone.h>

#define FLAME 0  // FLAME 0
#define FAN_IA 4   // FAN 4
#define FAN_IB 5   // FAN 5

#define SPEAKER 6  // SPEAKER
#define C 261.63
#define D 293.66
#define E 329.63
#define F 349.23
#define G 391.00
#define A 440.00

float notes[][2] = {
    {G, 8}, {G, 8}, {A, 8}, {A, 8}, {G, 8}, {G, 8}, {E, 4},
    {G, 8}, {G, 8}, {E, 8}, {E, 8}, {D, 2},
    {G, 8}, {G, 8}, {A, 8}, {A, 8}, {G, 8}, {G, 8}, {E, 4},
    {G, 8}, {E, 8}, {D, 8}, {E, 8}, {C, 2}
};


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
    
    pinMode(FAN_IA, OUTPUT);
    pinMode(FAN_IB, OUTPUT);

    softToneCreate(SPEAKER);

    digitalWrite(FAN_IA,LOW);  // FAN
    digitalWrite(FAN_IB,LOW);

    while(1){
        timestamp();
        delay(1000);
        
        if(digitalRead(FLAME)==HIGH){
            printf("안전\n");
            
            digitalWrite(FAN_IA,LOW);  // FAN
            digitalWrite(FAN_IB,LOW);

        }else {
            printf("화재경보\n"); // FLAME
            
            digitalWrite(FAN_IA,LOW);  // FAN
            digitalWrite(FAN_IB,HIGH);

            for (int i = 0 ; i < sizeof(notes) ; i++)  // SPEAKER
                softToneWrite(SPEAKER, notes[i][0]);
                // delay (4 / ((notes[i][1] * 1000) - 10));
                softToneWrite(SPEAKER, 0);
                delay (10);
            }
               
        }       
                
    return 0;
}