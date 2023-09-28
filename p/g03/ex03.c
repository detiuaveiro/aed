#include<stdio.h>
#include<stdlib.h>

size_t number_digits(int n) {
    size_t c = 0;
    do {
        n /= 10;
        c++;
    } while (n != 0);
  return c;
}

int* digits(int n, size_t* nd) {
    *nd = number_digits(n);
    int* ds = (int*)calloc(*nd, sizeof(int)); 
    size_t i = (*nd)-1;
    
    while(n)
    {
        ds[i--] = n%10;
        n /= 10;
    }

    return ds;
}

int factorion(int n) {
    int fact[10];
    fact[0]=1;
    fact[1]=1;
    for(size_t i = 2; i < 10; i++) {
        fact[i] = i * fact[i-1];
    }

    for (size_t i = 0; i < 10; i++) {
        printf("%d, ", fact[i]);
    }
    printf("\n");

    printf("%d\n",n);
    size_t nd = 0;
    int* ds = digits(n, &nd);
    
    int rv = 0;
    for (size_t i = 0; i < nd; i++) {
        rv += fact[ds[i]];
        printf("%d, ", ds[i]);
    }
    printf("\n");

    free(ds);

    return rv;
}

int main (void) {
    int number = 1234567987;
    int rv = factorion(number);
    printf("Factorion (%d) = %d\n", number, rv);
    return 0;
}
