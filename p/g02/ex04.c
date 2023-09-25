#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <assert.h>

// Display the contents of array a with n elements
// Pre-Conditions: a != NULL and n > 0
// Example of produced output: Array = [ 1.00, 2.00, 3.00 ] 

void DisplayArray(double* a, size_t n) {
    assert(a != NULL);
    assert(n > 0);

    printf("Array = [ ");
    for (size_t i = 0; i < n-1; i++){
        printf("%.2f, ", a[i]);
    }
    printf(" %.2f ]\n", a[n-1]);
}

// Read the number of elements, allocate the array and read its elements 
// Condition: number of elements > 0 
// Pre-Condition: size_p != NULL 
// Return NULL if memory allocation fails 
// Set *size_p to ZERO if memory allocation fails 

double* ReadArray(size_t* size_p) {
    assert(size_p != NULL);
    
    size_t temp_size_p = 0;
    printf("Insert the number of elements: ");
    scanf("%zu", &temp_size_p);

    double *array = (double*) calloc(temp_size_p, sizeof(double));
    if (array == NULL) {
        *size_p = 0;
        return NULL;
    } else {
        *size_p = temp_size_p;

        for (size_t i = 0; i < temp_size_p; i++) {
            double v = 0;
            printf("Insert the {%zu} element: ", i);
            scanf("%lf", &v);
            array[i] = v;
        }

        return array;
    }
}

// Allocate and return a new array with (size_1 + size_2) elements 
// which stores the elements of array_1 followed by the elements of array_2 
// Pre-Conditions: array_1 != NULL and array_2 != NULL 
// Pre-Conditions: size_1 > 0 and size_2 > 0 
// Return NULL if memory allocation fails 

double* Append(double* array_1, size_t size_1, double* array_2, size_t size_2) {
    double* rv_array = (double*) calloc(size_1+size_2, sizeof(double));

    size_t i = 0, j = 0;

    for (; i < size_1; i++) {
        rv_array[i] = array_1[i];
    }

    for (; j < size_2; i++, j++) {
        rv_array[i] = array_2[j];
    }

    return rv_array;
}

double* Append2(double* array_1, size_t size_1, double* array_2, size_t size_2) {
    double* rv_array = (double*) calloc(size_1+size_2, sizeof(double));

    memcpy (rv_array, array_1, size_1*sizeof(double));
    memcpy (&rv_array[size_1], array_2, size_2*sizeof(double));
    return rv_array;
}

int main(void) {
    size_t size_1 = 0, size_2 = 0;
    
    double* array_1 = ReadArray(&size_1);
    DisplayArray(array_1, size_1);

    double* array_2 = ReadArray(&size_2);
    DisplayArray(array_2, size_2);

    double* array_3 = Append(array_1, size_1, array_2, size_2);
    DisplayArray(array_3, size_1+size_2);

    double* array_4 = Append2(array_1, size_1, array_2, size_2);
    DisplayArray(array_4, size_1+size_2);

    free(array_1);
    free(array_2);
    free(array_3);
    free(array_4);
}