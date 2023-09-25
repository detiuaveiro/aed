#include<stdio.h>

void Permute(int *a, int *b, int *c) {
    int t = *a;
    *a = *c;
    *c = t;
}

void dummy_Permute(int a, int b, int c) {
    printf("DP %d %d %d\n", a, b, c);
    int t = a;
    a = c;
    c = t;
    printf("DP %d %d %d\n", a, b, c);
} // <- 

int main(void) {
    int a = 1, b = 2, c = 3;
    
    //int i = 42;
    //int* p = &i;
    //int j = *(&i);
    //int* t = &(*p);

    //printf("%d %d\n", i, j);
    //printf("%p %p\n", p, t);

    //printf("%d %d\n", i, *p);
    //printf("%p %p\n", &i, p);
    
    printf("%d %d %d\n", a, b, c);
    //Permute(&a, &b, &c);
    dummy_Permute(a, b, c);
    printf("%d %d %d\n", a, b, c);
    //Permute(&a, &b, &c);
    dummy_Permute(a, b, c);
    printf("%d %d %d\n", a, b, c);
}