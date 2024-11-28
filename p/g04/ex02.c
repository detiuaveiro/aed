#include <assert.h>
#include <stdio.h>

/* GLOBAL VARIABLE */
size_t NUM_OPS;

void print_result_table(float *array, size_t n, int r, int ops) {
  printf("[");
  for (size_t i = 0; i < n - 1; i++) {
    printf("%5.1f, ", array[i]);
  }
  printf("%5.1f] Result: %02d N_Ops: %02d\n", array[n - 1], r, ops);
}

int isGeometricSeq(float *a, int n) {
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
  int r = 0;

  float a1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  float a2[10] = {1, 2, 4, 4, 5, 6, 7, 8, 9, 10};
  float a3[10] = {1, 2, 4, 8, 5, 6, 7, 8, 9, 10};
  float a4[10] = {1, 2, 4, 8, 16, 6, 7, 8, 9, 10};
  float a5[10] = {1, 2, 4, 8, 16, 32, 7, 8, 9, 10};
  float a6[10] = {1, 2, 4, 8, 16, 32, 64, 8, 9, 10};
  float a7[10] = {1, 2, 4, 8, 16, 32, 64, 128, 9, 10};
  float a8[10] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 10};
  float a9[10] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

  size_t size = 10;

  NUM_OPS = 0;
  r = isGeometricSeq(a1, size);
  print_result_table(a1, size, r, NUM_OPS);

  NUM_OPS = 0;
  r = isGeometricSeq(a2, size);
  print_result_table(a2, size, r, NUM_OPS);

  NUM_OPS = 0;
  r = isGeometricSeq(a3, size);
  print_result_table(a3, size, r, NUM_OPS);

  NUM_OPS = 0;
  r = isGeometricSeq(a4, size);
  print_result_table(a4, size, r, NUM_OPS);

  NUM_OPS = 0;
  r = isGeometricSeq(a5, size);
  print_result_table(a5, size, r, NUM_OPS);

  NUM_OPS = 0;
  r = isGeometricSeq(a6, size);
  print_result_table(a6, size, r, NUM_OPS);

  NUM_OPS = 0;
  r = isGeometricSeq(a7, size);
  print_result_table(a7, size, r, NUM_OPS);

  NUM_OPS = 0;
  r = isGeometricSeq(a8, size);
  print_result_table(a8, size, r, NUM_OPS);

  NUM_OPS = 0;
  r = isGeometricSeq(a9, size);
  print_result_table(a9, size, r, NUM_OPS);

  return 0;
}
