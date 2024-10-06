//
// Joaquim Madeira, AED, September 2023
//
// Functions with different complexity orders
//
// The result of each function is the number of iterations carried out
//
// For each function, how does the number of iterations grow?
//
// 1 - Analyze the tables
// 2 - Assign a complexity order to each function
//
// 3 - Inspect the code
// 4 - For a given positive value of n, find a formula for the total number of
//     iterations
//

#include <stdio.h>

unsigned int f1(unsigned int n) {
  unsigned int r = 0;
  for (unsigned int i = 1; i <= n; i++) {
    r += 1;
  }
  return r;
}

unsigned int f2(unsigned int n) {
  unsigned int r = 0;
  for (unsigned int i = 1; i <= n; i++) {
    for (unsigned j = 1; j <= i; j++) {
      r += 1;
    }
  }
  return r;
}

unsigned int f3(unsigned int n) {
  unsigned int r = 0;
  for (unsigned int i = 1; i <= n; i++) {
    for (unsigned int j = 1; j <= n; j++) {
      r += 1;
    }
  }
  return r;
}

unsigned int f4(unsigned int n) {
  unsigned int r = 0;
  for (unsigned int i = 1; i <= n; i++) {
    for (unsigned int j = 1; j <= i; j++) {
      for (unsigned int k = 1; k <= j; k++) {
        r += 1;
      }
    }
  }
  return r;
}

unsigned int f5(unsigned int n) {
  unsigned int r = 0;
  for (unsigned int i = 1; i <= n; i++) {
    for (unsigned int j = 1; j <= n; j++) {
      for (unsigned int k = 1; k <= n; k++) {
        r += 1;
      }
    }
  }
  return r;
}

unsigned int f6(unsigned int n) {
  unsigned int r = 0;
  for (unsigned int i = n; i > 0; i /= 2) {
    r += 1;
  }
  return r;
}

unsigned int f7(unsigned int n) {
  unsigned int r = 0;
  unsigned int last = 1;
  for (unsigned int i = 1; i <= n; i++) {
    for (unsigned int j = 1; j <= last; j++) {
      r += 1;
    }
    last *= 2;
  }
  return r;
}

int main(void) {
  unsigned int n;
  unsigned int result;
  unsigned int previous;
  double ratio;

  unsigned int start_n = 25;
  unsigned int end_n = 1000;

  printf("\n f1 \n");
  printf("      n       f1(n)   f1(n)/f1(n/2)\n");
  printf("-------  ----------  --------------\n");

  for (n = start_n; n < end_n; n *= 2) {
    result = f1(n);
    printf("%7u  %10u", n, result);

    if (n > start_n) {
      ratio = (double)result / (double)previous;
      printf("  %14.5f", ratio);
    }

    printf("\n");

    previous = result;
  }

  printf("-------  ----------  --------------\n");

  printf("\n f2 \n");
  printf("      n       f2(n)   f2(n)/f2(n/2)\n");
  printf("-------  ----------  --------------\n");

  for (n = start_n; n < end_n; n *= 2) {
    result = f2(n);
    printf("%7u  %10u", n, result);

    if (n > start_n) {
      ratio = (double)result / (double)previous;
      printf("  %14.5f", ratio);
    }

    printf("\n");

    previous = result;
  }

  printf("-------  ----------  --------------\n");

  printf("\n f3 \n");
  printf("      n       f3(n)   f3(n)/f3(n/2)\n");
  printf("-------  ----------  --------------\n");

  for (n = start_n; n < end_n; n *= 2) {
    result = f3(n);
    printf("%7u  %10u", n, result);

    if (n > start_n) {
      ratio = (double)result / (double)previous;
      printf("  %14.5f", ratio);
    }

    printf("\n");

    previous = result;
  }

  printf("-------  ----------  --------------\n");

  printf("\n f4 \n");
  printf("      n       f4(n)   f4(n)/f4(n/2)\n");
  printf("-------  ----------  --------------\n");

  for (n = start_n; n < end_n; n *= 2) {
    result = f4(n);
    printf("%7u  %10u", n, result);

    if (n > start_n) {
      ratio = (double)result / (double)previous;
      printf("  %14.5f", ratio);
    }

    printf("\n");

    previous = result;
  }

  printf("-------  ----------  --------------\n");

  printf("\n f5 \n");
  printf("      n       f5(n)   f5(n)/f5(n/2)\n");
  printf("-------  ----------  --------------\n");

  for (n = start_n; n < end_n; n *= 2) {
    result = f5(n);
    printf("%7u  %10u", n, result);

    if (n > start_n) {
      ratio = (double)result / (double)previous;
      printf("  %14.5f", ratio);
    }

    printf("\n");

    previous = result;
  }

  printf("-------  ----------  --------------\n");

  printf("\n f6 \n");
  printf("      n       f6(n)    f6(n)/f6(n/2)\n");
  printf("-------  ----------  --------------\n");

  for (n = start_n; n < end_n; n *= 2) {
    result = f6(n);
    printf("%7u  %10u", n, result);

    if (n > start_n) {
      ratio = (double)result / (double)previous;
      printf("  %14.5f", ratio);
    }

    printf("\n");

    previous = result;
  }

  printf("-------  ----------  --------------\n");

  printf("\n f7 \n");
  printf("      n       f7(n)   f7(n)/f7(n/2)\n");
  printf("-------  ----------  --------------\n");

  for (n = 1; n < 33; n *= 2) {
    result = f7(n);
    printf("%7u  %10u", n, result);

    if (n > 1) {
      ratio = (double)result / (double)previous;
      printf("  %14.5f", ratio);
    }

    printf("\n");

    previous = result;
  }

  printf("-------  ----------  --------------\n");

  return 0;
}
