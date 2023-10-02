#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "elapsed_time.h"


size_t number_digits(int n) {
    size_t c = (n==0)?1:log10(n)+1;  
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

long factorion(int n, int* fact) {
    size_t nd = 0;
    int* ds = digits(n, &nd);
    
    long rv = 0;
    for (size_t i = 0; i < nd; i++) {
        rv += fact[ds[i]];   
    }

    free(ds);

    return rv;
}

long factorial(int n) {  
  if (n == 0)  
    return 1;  
  else  
    return(n * factorial(n-1));  
}  

long naive_factorion(int n) {
    size_t nd = 0;
    int* ds = digits(n, &nd);
    
    long rv = 0;
    for (size_t i = 0; i < nd; i++) {
        rv += factorial(ds[i]);   
    }

    return rv;
}

int main (void) {
    // compute factorials for 0! to 9!
    int fact[10];
    fact[0] = 1;
    fact[1] = 1;
    fact[2] = 2;
    for(size_t i = 3; i < 10; i++) {
        fact[i] = i * fact[i-1];
    }
        
    int number = 1234567987;
    long rv = factorion(number, fact);
    printf("Factorion (%d) = %ld\n", number, rv);
    rv = naive_factorion(number);
    printf("Factorion (%d) = %ld\n", number, rv);

    double start_time, finish_time, exec_time;

    rv = 0;
    start_time = cpu_time();
    for (size_t i = 0; i < 10e7; i++) {
        rv += factorion(i, fact);
    }
    finish_time = cpu_time();
    exec_time = finish_time - start_time;
    printf("Factorion [0!! - 10^7!!] = %ld\n", rv);
    printf("%9.3e\n", exec_time);


    rv = 0;
    start_time = cpu_time();
    for (size_t i = 0; i < 10e7; i++) {
        rv += naive_factorion(i);
    }
    finish_time = cpu_time();
    exec_time = finish_time - start_time;
    printf("Factorion [0!! - 10^7!!] = %ld\n", rv);
    printf("%9.3e\n", exec_time);
    
    return 0;
}
