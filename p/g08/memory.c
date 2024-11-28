#include<stdio.h>
#include<stdlib.h>

int main() {
    int l = 10;

    int *array = calloc(sizeof(int), l);

    for(int i = 0; i < l; i++) {
        array[i] = i % 2 == 0 ? i/2 : i*3+1;
    }

    printf("Array = [");
    for (int i = 0; i < l-1; i++) {
        printf("%03d; ", array[i]);
    }
    printf("%03d]\n", array[l-1]);

    //free(array);
    array = NULL;

    return 0;
}