#include <stdio.h>
#include <stdlib.h>

void print_array(char *txt, int *array, size_t n) {
    printf("%s :\n", txt);

    for(size_t i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

}

void cum_sum(int *a, int*b, size_t n) {
    int c = 0;
    for (int i=0; i<n; i++) {
        c += a[i];
        b[i] = c;
    }
}

int main(void) {
    int a[] ={31,28,31,30,31,30,31,31,30,31,30, 31};
    print_array("a", a, 12);
    int *b = (int*)calloc(12, sizeof(int));
    cum_sum(a,b,12);
    print_array("b", b, 12);
    free(b);
    b = NULL;

    return 0;
}