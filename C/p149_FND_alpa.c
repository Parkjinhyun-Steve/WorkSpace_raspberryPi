#include <stdio.h>
#include <wiringPi.h>

#define A 13   // GPIO. 13
#define B 14   // GPIO. 14
#define C 4    // GPIO. 4
#define D 5    // GPIO. 5
#define E 21   // GPIO. 21
#define F 22   // GPIO. 22
#define G 23   // GPIO. 23

unsigned char SEGMENTS[7] = {A, B, C, D, E, F, G};
unsigned char NUMBER[10][7] = {
//  {a, b, c, d, e, f, g}   
    
    {0, 0, 0, 1, 0, 0, 0},  // A
    {1, 1, 0, 0, 0, 0, 0},  // b
    {1, 1, 1, 0, 0, 1, 0},  // c
    {1, 0, 0, 0, 0, 1, 0},  // d
    {1, 1, 1, 1, 1, 1, 1},  // 
    {1, 0, 0, 1, 0, 0, 0},  // H
    {0, 1, 1, 0, 0, 0, 0},  // E
    {1, 1, 1, 0, 0, 0, 1},  // L
    {0, 0, 1, 1, 0, 0, 0},  // P
    {1, 1, 1, 1, 1, 1, 1},  // 
};

int main(void){
    if(wiringPiSetup() == -1){return 1;}


// output
    for (char i = 0 ; i < 7 ; i++) {
        pinMode(SEGMENTS[i], OUTPUT);
    }

    while(1){

        for (char i = 0 ; i < 10 ; i++) {
            for (char j = 0 ; j < 7 ; j++) {
                digitalWrite(SEGMENTS[j], NUMBER[i][j]);
            } 
            delay(1000);
        }
    }
}