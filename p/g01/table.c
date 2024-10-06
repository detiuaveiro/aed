#include <stdio.h>
#include <math.h>

int main (void) {
    int lines = 0;
    printf("Insert number of lines: ");
    scanf("%d", &lines);

    printf("%7s %7s %7s\n", "Number", "Power", "SQRT");
    for(int i = 1; i <= lines; i++) {
        printf("%7d %7.2f %7.2f\n", i, pow(i, 2), sqrt(i));
    }
}