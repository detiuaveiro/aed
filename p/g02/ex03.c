#include<stdio.h>

void Permute(int *a, int *b, int *c) {
    int t = *a;
    *a = *c;
    *c = t;
}

int main(void) {
    int a = 1, b = 2, c = 3;
    printf("%d %d %d\n", a, b, c);
    Permute(&a, &b, &c);
    printf("%d %d %d\n", a, b, c);
    Permute(&a, &b, &c);
    printf("%d %d %d\n", a, b, c);
}