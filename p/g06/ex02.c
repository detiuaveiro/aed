#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b) (((a)>(b))?(a):(b)) 


size_t coin_row(size_t *C, size_t n)  {
    size_t first_total;
    size_t second_total;

    if (n == 0) return 0;
    if (n == 1) return *C;
    if (n == 2) return MAX(*C, *(C+1));

    first_total = *C + coin_row(C+2, n-2);
    second_total = *(C+1) + coin_row(C+3, n-3);

    return(MAX(first_total, second_total));
}

size_t coin_row_pd(size_t *C, size_t n) {
  if(n==0) return 0;
  if(n==1) return C[0];
  if(n==2) return MAX(C[0], C[1]);

  int F[n+1], i;
  F[0] = 0; F[1] = C[0];

  for(i = 2 ; i <= n + 1 ; i++) {
    F[i] = MAX(C[i-1] + F[i-2], F[i-1]);
  }

  return F[n];
}

void print_array(size_t *C, size_t n) {
    printf("[");
    for(size_t i = 0; i < n-1; i++) {
        printf("%3ld,", C[i]);
    }
    printf("%3ld]\n", C[n-1]);
}

int main(int argc, char* argv[]) {

    size_t *coin_array = (size_t*)calloc(argc-1, sizeof(size_t));

    for (size_t k = 1; k < argc; k++) {
        coin_array[k-1] = atoi(argv[k]);
    }

    print_array(coin_array, argc-1);

    size_t r = coin_row(coin_array, argc-1);

    printf("V(%d) = %ld\n", argc-1, r);

    r = coin_row_pd(coin_array, argc-1);

    printf("V(%d) = %ld\n", argc-1, r);
}