#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>


size_t number_digits(int n) {
    size_t c = (n==0)?1:log10(n)+1;  
    return c;
}

int* digits(int n, size_t* nd) {
    *nd = number_digits(n);
    int* ds = (int*)calloc(*nd, sizeof(int)); 
    size_t i = (*nd)-1;
    
    while(n) {
        ds[i--] = n%10;
        n /= 10;
    }

    return ds;
}

bool armstrong(unsigned int number) {
    size_t nd = 0;
    int *d = digits(number, &nd);

    unsigned int tmp = 0;
    for(size_t i = 0; i < nd; i++) {
        tmp += pow(d[i], nd);
    }

    free(d);

    if(number == tmp) {
        return true;
    } else {
        return false;
    }
} 

int main (void) {
    /*int v1 = pow(1, 3);
    int v2 = pow(5, 3);
    int v3 = pow(3, 3);
    int t = v1+v2+v3;
    printf("%d+%d+%d = %d\n", v1,v2,v3,t);*/

    unsigned int number = 153;
    printf("%d -> %d\n", number, armstrong(number));
    number = 9474;
    printf("%d -> %d\n", number, armstrong(number));

    printf("--------------\n");

    number = 9473;
    printf("%d -> %d\n", number, armstrong(number));
    number = 9475;
    printf("%d -> %d\n", number, armstrong(number));

    return 0;
}