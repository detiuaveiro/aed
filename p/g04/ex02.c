#include <assert.h>
#include <stdio.h>

/* GLOBAL VARIABLE */

int NUM_OPS;

void printArray(float* a, int n) {
  for (int i = 0; i < n; i++) {
    printf("%f ", a[i]);
  }

  printf("\n");
}

int isGeometricSeq(float* a, int n) {
  assert(n > 2);

  NUM_OPS++;
  float r = a[1] / a[0];

  for (int i = 2; i < n; i++) {
    NUM_OPS++;
    if (a[i] != (r * a[i - 1])) {
      return 0;
    }
  }

  return 1;
}

int main(void) {
  int r;

  /* TESTING */

  float a1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  float a2[10] = {1, 2, 4, 4, 5, 6, 7, 8, 9, 10};

  float a3[10] = {1, 2, 4, 8, 5, 6, 7, 8, 9, 10};

  float a4[10] = {1, 2, 4, 8, 16, 6, 7, 8, 9, 10};

  float a5[10] = {1, 2, 4, 8, 16, 32, 7, 8, 9, 10};

  float a6[10] = {1, 2, 4, 8, 16, 32, 64, 8, 9, 10};

  float a7[10] = {1, 2, 4, 8, 16, 32, 64, 128, 9, 10};

  float a8[10] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 10};

  float a9[10] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

  int size = 10;

  printf(" *** TESTING ***\n");

  printArray(a1, size);

  NUM_OPS = 0;

  r = isGeometricSeq(a1, size);

  printf("Result = %d \t NUM_OPS = % d \n ", r, NUM_OPS);

  printArray(a2, size);

  NUM_OPS = 0;

  r = isGeometricSeq(a2, size);

  printf("Result = %d \t NUM_OPS = % d \n ", r, NUM_OPS);

  printArray(a3, size);

  NUM_OPS = 0;

  r = isGeometricSeq(a3, size);

  printf("Result = %d \t NUM_OPS = % d \n ", r, NUM_OPS);

  printArray(a4, size);

  NUM_OPS = 0;

  r = isGeometricSeq(a4, size);

  printf("Result = %d \t NUM_OPS          = % d \n ", r, NUM_OPS);

  printArray(a5, size);

  NUM_OPS = 0;

  r = isGeometricSeq(a5, size);

  printf("Result = %d \t NUM_OPS         = % d \n ", r, NUM_OPS);

  printArray(a6, size);

  NUM_OPS = 0;

  r = isGeometricSeq(a6, size);

  printf("Result = %d \t NUM_OPS         = % d \n ", r, NUM_OPS);

  printArray(a7, size);

  NUM_OPS = 0;

  r = isGeometricSeq(a7, size);

  printf("Result = %d \t NUM_OPS          = % d \n ", r, NUM_OPS);

  printArray(a8, size);

  NUM_OPS = 0;

  r = isGeometricSeq(a8, size);

  printf("Result = %d \t NUM_OPS         = % d \n ", r, NUM_OPS);

  printArray(a9, size);

  NUM_OPS = 0;

  r = isGeometricSeq(a9, size);

  printf("Result = %d \t NUM_OPS         = % d \n ", r, NUM_OPS);

  return 0;
}
