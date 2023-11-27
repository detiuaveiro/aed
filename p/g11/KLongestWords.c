//
// Algoritmos e Estruturas de Dados --- 2023/2024
//
// Joaquim Madeira, May 2020, November 2023
//

//
// This program creates a HASH TABLE that stores the words of a text file and
// the number of occurrences of each word.
//
// It also creates a MIN-HEAP that stores the K longest words of the text file.
//

//// SEARCH ... AND COMPLETE ////

// Try the arguments below.

// ARGS 5 file20.txt
// ARGS 10 file99.txt
// ARGS 20 SherlockHolmes.txt

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "HashTable.h"
#include "MinHeap.h"

//
// The MIN-HEAP stores pairs (word, length), where length is the word length.
// Examples: (dog, 3), (house, 5)
//
// The MIN-HEAP elements are orderer according to the second attribute (length).
//

// The info for each min-heap node
struct heapElem {
  char word[64];        // A word
  unsigned int length;  // Its length
};

typedef struct heapElem* heapElemPtr;

// The comparator for heap elements

int comparator(const void* p1, const void* p2) {
  heapElemPtr item1 = (heapElemPtr)p1;
  heapElemPtr item2 = (heapElemPtr)p2;

  int d = item1->length - item2->length;
  return (d > 0) - (d < 0);
}

// The printer for heap elements

void printer(void* p) {
  heapElemPtr item = (heapElemPtr)p;
  printf("(%s, %d)", item->word, item->length);
}

//
// main
//

int main(int argc, char** argv) {
  if (argc < 3) {
    fprintf(stderr, "Usage: %s K FILE\n", argv[0]);
    exit(1);
  }

  // k -> number of words we are looking for
  unsigned int k = atoi(argv[1]);

  FILE* file = fopen(argv[2], "r");
  if (file == NULL) {
    fprintf(stderr, "Unable to open file %s\n", argv[1]);
    exit(1);
  }

  //
  // The hash table for registering words and counting word occurrences.
  // It uses the hash3 hashing function
  //
  HashTable* hashT = HashTableCreate(50021, hash3, linearProbing, 1);

  //
  // The MIN-HEAP for registering K words according to their length
  //
  MinHeap* topKByLength = MinHeapCreate(k, comparator, printer);

  //
  // Scan the entire file
  //
  // Token processing SHOULD BE improved !!!!!
  //

  char line[10000];
  char word[64];

  while (fgets(line, sizeof(line), file) != NULL) {
    // Replace non-digits and non-letters by a space
    for (size_t i = 0; line[i] != '\0'; i++) {
      if ((line[i] < '0' || line[i] > '9') &&
          (line[i] < 'A' || line[i] > 'Z') &&
          (line[i] < 'a' || line[i] > 'z') && line[i] != '\'') {
        line[i] = ' ';
      }
    }
    // Go again over the line and extract each word
    size_t j;
    for (size_t i = 0; line[i] != '\0'; i += j) {
      if (line[i] == ' ') {
        j = 1;
      } else {
        for (j = 0; line[i + j] != '\0' && line[i + j] != ' '; j++) {
          if (j < 63) word[j] = line[i + j];
        }
        word[(j < 63) ? j : 63] = '\0';

        // Update the HASH TABLE with the occurrence of the current word
        // ...
        HashTableIncrement(hashT, word);

        // Update the MIN-HEAP, if needed
        heapElemPtr p;
        if (MinHeapSize(topKByLength) != k) {
          // Add to the MIN-HEAP until it has k elements

          // Allocate the new heap element and set its attributes
          // ...
          p = (heapElemPtr)malloc(sizeof(struct heapElem));
          strcpy(p->word, word);
          p->length = strlen(word);

          // Add it to the MIN-HEAP
          // ...
          MinHeapInsert(topKByLength, (void*)p);
        } else if (HashTableGet(hashT, word) == 1) {
          // The MIN-HEAP has K elements
          // AND the current word just appeared for the first time
          // Replace the min element of the heap, if the word is longer
          // than the min word

          p = MinHeapGetMin(topKByLength);

          // If the current word is longer than the min word
          // ---> remove the min from the heap
          // ---> free its allocated memory
          // ---> allocate the pair (word, length) for the current word
          //      and set its attributes
          // ---> add it to the heap
          // ...

          if (strlen(word) > p->length) {
            // Current word is longer!!
            // Remove the min from the heap and free its memory
            MinHeapRemoveMin(topKByLength);
            free(p);
            // Add the current word to the heap
            // The new heap element
            p = (heapElemPtr)malloc(sizeof(struct heapElem));
            strcpy(p->word, word);
            p->length = strlen(word);
            MinHeapInsert(topKByLength, (void*)p);
          }
        }
      }
    }
  }

  // Closing the file
  fclose(file);

  // FOR DEBUGGING
  // HashTableDisplayItems(hashT);
  // MinHeapView(topKByLength);

  // List the words in ascending order
  printf("*** The %u longest words ***\n", k);

  // Loop to print and remove the min element from the heap,
  // and free its allocated memory
  // until the heap is empty
  // ...
  while (MinHeapIsEmpty(topKByLength) == 0) {
    heapElemPtr p = MinHeapGetMin(topKByLength);
    printer(p);
    printf("\n");
    MinHeapRemoveMin(topKByLength);
    free(p);
  }

  // Freeing the allocated memory
  HashTableDestroy(&hashT);
  MinHeapDestroy(&topKByLength);

  return 0;
}