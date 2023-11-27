//
// Algoritmos e Estruturas de Dados --- 2023/2024
//
// João Manuel Rodrigues, Joaquim Madeira, June 2021, Nov 2023
//
// TESTING the TAD MinHeap implementation
//

// This program lists the largest K values from a file of random integers.

//// SEARCH ... AND COMPLETE ////

// Try the arguments below.

// ARGS 10 ordenados02500.txt
// ARGS 10 ordInversa02500.txt
// ARGS 10 aleatorios02500.txt
// ARGS 100 aleatorios40000.txt

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "MinHeap.h"

// THE ALGORITHM:
//
// Read the first K values into a MIN-heap.
//
// Then:
//
// 1. Get the next value from the file -> current.
// 2. If current is smaller or equal than the MIN element from the heap,
//    then discard it.
// 3. Otherwise, remove the MIN from the heap and insert the current value.
//
// The MIN-heap stores the K largest values read from file.
//
// List the K largest values by successively removing the MIN from the heap.
//

// STORING POINTERS TO INTEGERS

// The comparator for integer items

int comparator(const void* p1, const void* p2) {
  int d = *(int*)p1 - *(int*)p2;
  return (d > 0) - (d < 0);
}

// The printer for integer items

void printer(void* p) { printf("%d ", *(int*)p); }

// MAIN

int main(int argc, char* argv[]) {
  if (argc < 3) {
    fprintf(stderr, "Usage: %s K FILE\n", argv[0]);
    exit(1);
  }

  // k -> number of largest values we are looking for
  int k = atoi(argv[1]);

  FILE* f = fopen(argv[2], "r");
  if (f == NULL) {
    perror(argv[2]);
    exit(2);
  }

  // Create heap
  // HIDE
  MinHeap* h = MinHeapCreate(k, comparator, printer);
  // EDIT MinHeap* h = ...
  if (h == NULL) abort();

  // Read the first K values into a MIN-heap
  //    Allocate memory space for an integer
  //    Read it from file
  //    Insert it in the heap

  // HIDE
  for (int i = 0; i < k; i++) {
    int* aux = (int*)malloc(sizeof(int));
    fscanf(f, "%d", aux);
    MinHeapInsert(h, (void*)aux);
  }
  // EDIT for( ... ) { ... }

  // Read and process each one of the remaining values
  while (!feof(f)) {
    // HIDE
    int* aux = (int*)malloc(sizeof(int));
    fscanf(f, "%d", aux);
    int* min = (int*)MinHeapGetMin(h);
    if (*aux > *min) {
      MinHeapRemoveMin(h);
      free(min);
      MinHeapInsert(h, (void*)aux);
    } else {
      free(aux);
    }
    // EDIT ...
  }

  // The heap stores the largest k values
  // List them by removing each one from the heap

  // HIDE
  while (!MinHeapIsEmpty(h)) {
    int* aux = (int*)MinHeapGetMin(h);
    printf("%d\n", *aux);
    MinHeapRemoveMin(h);
    free(aux);
  }
  // EDIT while( ... ) { ... }

  // House-keeping
  MinHeapDestroy(&h);
  fclose(f);
}
