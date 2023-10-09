#include <assert.h>
#include <stdio.h>

/* GLOBAL VARIABLE */

int NUM_COMPS;

void printArray(int* a, int n) {
  int i;

  for (i = 0; i < n; i++) {
    printf("%4d ", a[i]);
  }

  printf("\n");
}

int check(int* a, int n) {
  assert(n > 2);

  int result = 0;

  for (int i = 1; i < (n - 1); i++) {
    if (a[i] == (a[i - 1] + a[i + 1])) {
      result++;
    }

    NUM_COMPS++;
  }

  return result;
}

int main(void) {
  int r;

  /* TESTING */

  int a1[10] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3};

  int a2[10] = {4, 3, 3, 3, 3, 3, 3, 3, 3, 3};

  int a3[10] = {4, 5, 3, 3, 3, 3, 3, 3, 3, 3};

  int a4[10] = {4, 5, 1, 3, 3, 3, 3, 3, 3, 3};

  int a5[10] = {4, 5, 1, 2, 3, 3, 3, 3, 3, 3};

  int a6[10] = {4, 5, 1, 2, 6, 3, 3, 3, 3, 3};

  int a7[10] = {4, 5, 1, 2, 6, 8, 3, 3, 3, 3};

  int a8[10] = {4, 5, 1, 2, 6, 8, 7, 3, 3, 3};

  int a9[10] = {4, 5, 1, 2, 6, 8, 7, 9, 3, 3};

  int a10[10] = {4, 5, 1, 2, 6, 8, 7, 9, 3, 0};

  int a11[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  int a12[10] = {1, 2, 1, 4, 5, 6, 7, 8, 9, 10};

  int a13[10] = {1, 2, 1, 3, 2, 6, 7, 8, 9, 10};

  int a14[10] = {0, 2, 2, 0, 3, 3, 0, 4, 4, 0};

  int a15[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  int size = 10;

  printf(" *** TESTING ***\n");

  printArray(a1, size);

  NUM_COMPS = 0;

  r = check(a1, size);

  printf("Result = %d \t NUM_COMPS = %d \n", r, NUM_COMPS);

  printArray(a2, size);

  NUM_COMPS = 0;

  r = check(a2, size);

  printf("Result = %d \t NUM_COMPS = %d \n", r, NUM_COMPS);

  printArray(a3, size);

  NUM_COMPS = 0;

  r = check(a3, size);

  printf("Result = %d \t NUM_COMPS = %d \n", r, NUM_COMPS);

  printArray(a4, size);

  NUM_COMPS = 0;

  r = check(a4, size);

  printf("Result = %d \t NUM_COMPS = %d \n", r, NUM_COMPS);

  printArray(a5, size);

  NUM_COMPS = 0;

  r = check(a5, size);

  printf("Result = %d \t NUM_COMPS = %d \n", r, NUM_COMPS);

  printArray(a6, size);

  NUM_COMPS = 0;

  r = check(a6, size);

  printf("Result = %d \t NUM_COMPS = %d \n", r, NUM_COMPS);

  printArray(a7, size);

  NUM_COMPS = 0;

  r = check(a7, size);

  printf("Result = %d \t NUM_COMPS = %d \n", r, NUM_COMPS);

  printArray(a8, size);

  NUM_COMPS = 0;

  r = check(a8, size);

  printf("Result = %d \t NUM_COMPS = %d \n", r, NUM_COMPS);

  printArray(a9, size);

  NUM_COMPS = 0;

  r = check(a9, size);

  printf("Result = %d \t NUM_COMPS = %d \n", r, NUM_COMPS);

  printArray(a10, size);

  NUM_COMPS = 0;

  r = check(a10, size);

  printf("Result = %d \t NUM_COMPS = %d \n", r, NUM_COMPS);

  printArray(a11, size);

  NUM_COMPS = 0;

  r = check(a11, size);

  printf("Result = %d \t NUM_COMPS = %d \n", r, NUM_COMPS);

  printArray(a12, size);

  NUM_COMPS = 0;

  r = check(a12, size);

  printf("Result = %d \t NUM_COMPS = %d \n", r, NUM_COMPS);

  printArray(a13, size);

  NUM_COMPS = 0;

  r = check(a13, size);

  printf("Result = %d \t NUM_COMPS = %d \n", r, NUM_COMPS);

  printArray(a14, size);

  NUM_COMPS = 0;

  r = check(a14, size);

  printf("Result = %d \t NUM_COMPS = %d \n", r, NUM_COMPS);

  printArray(a15, size);

  NUM_COMPS = 0;

  r = check(a15, size);

  printf("Result = %d \t NUM_COMPS = %d \n", r, NUM_COMPS);

  return 0;
}
