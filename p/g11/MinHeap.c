//
// Algoritmos e Estruturas de Dados --- 2023/2024
//
// João Manuel Rodrigues, Joaquim Madeira, June 2021, Nov 2023
//
// Binary Min Heap storing pointers to generic items.
//

//// SEARCH ... AND COMPLETE ////

#include "MinHeap.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

//
// A binary or 2-way heap is a complete tree stored in an array.
//
// +-------------------------------------------------------------------------------+
// |                                       0 |
// +---------------------------------------+---------------------------------------+
// |                   1                   |                   2 |
// +-------------------+-------------------+-------------------+-------------------+
// |         3         |         4         |         5         |         6 |
// +---------+---------+---------+---------+---------+---------+---------+---------+
// |    7    |    8    |    9    |   10    |   11    |   12    |   13    |   14
// |
// +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
// | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | 24 | 25 | 26 | 27 | 28 | 29 |
// 30 |
// +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
//
// The children of node k, if any, are 2*k+1 and 2*k+2.
//
// The value of each node cannot be larger that those of its descendents.
//

// The heap data structure
struct _Heap {
  void** array;
  unsigned int capacity;
  unsigned int size;
  compFunc compare;
  printFunc print;
};

MinHeap* MinHeapCreate(unsigned int capacity, compFunc compF,
                       printFunc printF) {
  MinHeap* h = (MinHeap*)malloc(sizeof(MinHeap));  // alloc heap header
  if (h == NULL) abort();
  h->array = (void**)malloc(capacity * sizeof(void*));  // alloc array
  if (h->array == NULL) {
    free(h);
    abort();
  }
  h->capacity = capacity;
  h->size = 0;
  h->compare = compF;
  h->print = printF;
  return h;
}

void MinHeapDestroy(MinHeap** pph) {
  MinHeap* ph = *pph;
  if (ph == NULL) return;
  free(ph->array);
  free(ph);
  *pph = NULL;
}

unsigned int MinHeapCapacity(MinHeap* ph) { return ph->capacity; }

unsigned int MinHeapSize(MinHeap* ph) { return ph->size; }

int MinHeapIsEmpty(MinHeap* ph) { return ph->size == 0; }

int MinHeapIsFull(MinHeap* ph) { return ph->size == ph->capacity; }

void* MinHeapGetMin(MinHeap* ph) {
  assert(!MinHeapIsEmpty(ph));
  return ph->array[0];
}

// Internal functions

// n is the index of a node (n in [0, size[).
// _child(n, 1) is the index of the first child of node n, if < size.
// _child(n, 2) is the index of the second child of node n, if < size.
static inline int _child(int n, int c) { return 2 * n + c; }

// _parent(n) is the index of the parent node of node n, if >=0.
static inline int _parent(int n) {
  assert(n > 0);
  return (n - 1) / 2;
}

// Insert the item into the heap
void MinHeapInsert(MinHeap* ph, void* item) {
  assert(!MinHeapIsFull(ph));
  // start at the first vacant spot (just after the last occupied node)
  int n = ph->size;
  while (n > 0) {
    int p = _parent(n);

    // if item not less than parent, then we've found the right spot!
    if (ph->compare(item, ph->array[p]) >= 0) break;

    // otherwise, move up the item at node p to open up space for new item
    ph->array[n] = ph->array[p];

    // update
    n = p;  // p is the new vacant spot
  }
  ph->array[n] = item;  // store item at node n
  ph->size++;
}

// Remove the Min item
void MinHeapRemoveMin(MinHeap* ph) {
  assert(!MinHeapIsEmpty(ph));

  ph->size--;  // NOTE: we're decreasing the size first!
  int n = 0;   // the just emptied spot... must fill it with smallest child
  while (1) {
    // index of first child
    unsigned int min = _child(n, 1);  // first child (might not exist)

    if (!(min < ph->size)) break;  // if no second child, stop looking

    // if second child is smaller, choose it
    if (ph->compare(ph->array[min + 1], ph->array[min]) < 0) {
      min = min + 1;
    }

    // if smallest child is not smaller than last, stop looking
    if (!(ph->compare(ph->array[min], ph->array[ph->size]) < 0)) break;

    // move smallest child down to fill empty parent spot
    ph->array[n] = ph->array[min];

    n = min;  // now, the smallest _child spot was just emptied!
  }
  // move last element to emptied spot
  ph->array[n] = ph->array[ph->size];
  // EDIT ph->array[...] = ph->array[...];

  // mark last element as vacant
  ph->array[ph->size] = NULL;
}

// Check the (min-)heap property (the heap invariant):
//    Each node must be <= than each of its children.
// Equivalently (but easier):
//    Each node must be >= its parent.
int MinHeapCheck(MinHeap* ph) {
  // For each node other than root: compare with its parent
  for (unsigned int n = 1; n < ph->size; n++) {
    int p = _parent(n);
    if (ph->compare(ph->array[n], ph->array[p]) < 0) return 0;
  }
  return 1;
}

// Visualize the heap items as a tree
static void _HeapView(MinHeap* ph, int level, const char* edge,
                      unsigned int root) {
  if (root < ph->size) {
    _HeapView(ph, level + 1, "/", _child(root, 1));
    printf("%*s", 4 * level, edge);
    ph->print(ph->array[root]);
    printf("\n");
    _HeapView(ph, level + 1, "\\", _child(root, 2));
  }
}

// Visualize the heap both as a tree and as an array.
void MinHeapView(MinHeap* ph) {
  printf("tree:\n");
  _HeapView(ph, 0, ":", 0);  // : marks the root
  printf("array:");
  for (unsigned int i = 0; i < ph->size; i++) {
    printf(" ");
    ph->print(ph->array[i]);
  }
  printf("\nsize: %d\n", ph->size);
}
