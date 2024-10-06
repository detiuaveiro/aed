#include <stdio.h>

int main(void) {
    // O programa mais simples de C
    //printf( "%ld\n", __STDC_VERSION__ );
    //puts( "Hello World!%d" );
    short A = 32700;
    short B = 32700;
    short AB = A+B;
    short C = (A/2)+(B/2);
    short D = AB/2;
    printf("%d %d \n", C, D);
    return 0;
}