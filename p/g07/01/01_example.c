//
// TO DO : desenvolva um algoritmo para verificar se um numero inteiro positivo
//         e uma capicua
//         Exemplos: 12321 e uma capiacua, mas 123456 nao e
//         USE uma PILHA DE INTEIROS (STACK) e uma FILA DE INTEIROS (QUEUE)
//
// TO DO : design an algorithm to check if the digits of a positive decimal
//         integer number constitue a palindrome
//         Examples: 12321 is a palindrome, but 123456 is not
//         USE a STACK of integers and a QUEUE of integers
//

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "IntegersQueue.h"
#include "IntegersStack.h"


#define MAX(a,b) (((a)>(b))?(a):(b))

#define TRUE  (1==1)
#define FALSE (!TRUE)

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


int main(int argc, char* argv[]) { 
    // Get the word from arguments
    for(size_t i = 1; i < (size_t)argc; i++) {
        int number = atoi(argv[i]);
        size_t nd = 0;
        int *d = digits(number, &nd);

        Queue* queue = QueueCreate(MAX(10, nd));
        Stack* stack = StackCreate(MAX(10, nd));

        for(size_t j = 0; j < nd; j++) {
            StackPush(stack, d[j]);
            QueueEnqueue(queue, d[j]);
        }
        
        int result = TRUE;
        while (!QueueIsEmpty(queue) && !StackIsEmpty(stack)) {
            int digit_stack = 0, digit_queue = 0;

            digit_stack = StackPop(stack);
            digit_queue = QueueDequeue(queue);

            if(digit_queue != digit_stack) {
                result = FALSE;
                break;
            }
        }

        if (result) {
            printf("%d = True\n", number);
        } else {
            printf("%d = False\n", number);
        }

        StackDestroy(&stack);
        QueueDestroy(&queue);
        free(d);
    }

    return 0; 
}
