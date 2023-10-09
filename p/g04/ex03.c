#include <assert.h>
#include <stdio.h>

/* GLOBAL VARIABLE */
size_t NUM_COMPS;

void print_result_table(int *array, size_t n, int r, int ops) {
  printf("[");
  for (size_t i = 0; i < n - 1; i++) {
    printf("%2d, ", array[i]);
  }
  printf("%2d] Result: %03d N_Ops: %03d\n", array[n - 1], r, ops);
}

int check(int* a, int n) {
  assert(n > 2);

  //printf("Procurar ternos (i,j,k)\n");

  int result = 0;

  for (int k = 2; k < n; k++) {
    for (int j = 1; j < k; j++) {
      for (int i = 0; i < j; i++) {
        if (a[k] == (a[i] + a[j])) {
          //printf("%d %d %d\n", i, j, k);
          result++;
        }
        NUM_COMPS++;
      }
    }
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

  NUM_COMPS = 0;
  r = check(a1, size);
  print_result_table(a1, size, r, NUM_COMPS);
  

  NUM_COMPS = 0;
  r = check(a2, size);
  print_result_table(a2, size, r, NUM_COMPS);

  NUM_COMPS = 0;
  r = check(a3, size);
  print_result_table(a3, size, r, NUM_COMPS);

  NUM_COMPS = 0;
  r = check(a4, size);
  print_result_table(a4, size, r, NUM_COMPS);

  NUM_COMPS = 0;
  r = check(a5, size);
  print_result_table(a5, size, r, NUM_COMPS);

  NUM_COMPS = 0;
  r = check(a6, size);
  print_result_table(a6, size, r, NUM_COMPS);

  NUM_COMPS = 0;
  r = check(a7, size);
  print_result_table(a7, size, r, NUM_COMPS);

  NUM_COMPS = 0;
  r = check(a8, size);
  print_result_table(a8, size, r, NUM_COMPS);

  NUM_COMPS = 0;
  r = check(a9, size);
  print_result_table(a9, size, r, NUM_COMPS);

  NUM_COMPS = 0;
  r = check(a10, size);
  print_result_table(a10, size, r, NUM_COMPS);

  NUM_COMPS = 0;
  r = check(a11, size);
  print_result_table(a11, size, r, NUM_COMPS);

  NUM_COMPS = 0;

  r = check(a12, size);
  print_result_table(a12, size, r, NUM_COMPS);

  NUM_COMPS = 0;
  r = check(a13, size);
  print_result_table(a13, size, r, NUM_COMPS);

  NUM_COMPS = 0;
  r = check(a14, size);
  print_result_table(a14, size, r, NUM_COMPS);

  NUM_COMPS = 0;
  r = check(a15, size);
  print_result_table(a15, size, r, NUM_COMPS);

  return 0;
}
