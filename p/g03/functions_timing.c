//
// Joaquim Madeira, AED, September 2023
//
// Functions with different complexity orders
//
// The result of each function is the number of iterations carried out
//
// For each function, how does execution time grow?
//
// 1 - Analyze the tables
// 2 - Assign a complexity order to each function
// 3 - Compare with the results obtatined for the iterations count
//
// 4 - Extrapolate execution times for larger values of n
//

#include <stdio.h>

#include "elapsed_time.h"

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

  double start_time;
  double finish_time;
  double exec_time;
  double prev_exec_time;
  double ratio;

  unsigned int start_n = 10;
  unsigned int end_n = 10000000;

  printf("\n f1 \n");
  printf("          n    time1(n)   time1(n)/time1(n/10)\n");
  printf("-----------  ----------  ---------------------\n");

  for (n = start_n; n <= end_n; n *= 10) {
    //
    // call function
    //
    start_time = cpu_time();
    for (int i = 0; i < 1000; i++) {
      f1(n);
    }
    finish_time = cpu_time();

    exec_time = finish_time - start_time;
    exec_time = exec_time / 1000.0;

    printf("%11d  %9.3e", n, exec_time);

    if (n > start_n) {
      ratio = exec_time / prev_exec_time;
      printf("  %21.5e", ratio);
    }

    printf("\n");

    prev_exec_time = exec_time;
  }

  printf("-----------  ----------  ---------------------\n");

  printf("\n f2 \n");
  printf("          n    time2(n)   time2(n)/time2(n/10)\n");
  printf("-----------  ----------  ---------------------\n");

  for (n = start_n; n <= end_n / 100; n *= 10) {
    //
    // call function
    //
    start_time = cpu_time();
    f2(n);
    finish_time = cpu_time();

    exec_time = finish_time - start_time;

    printf("%11d  %9.3e", n, exec_time);

    if (n > start_n) {
      ratio = exec_time / prev_exec_time;
      printf("  %21.5e", ratio);
    }

    printf("\n");

    prev_exec_time = exec_time;
  }

  printf("-----------  ----------  ---------------------\n");

  printf("\n f3 \n");
  printf("          n    time3(n)   time3(n)/time3(n/10)\n");
  printf("-----------  ----------  ---------------------\n");

  for (n = start_n; n <= end_n / 100; n *= 10) {
    //
    // call function
    //
    start_time = cpu_time();
    f3(n);
    finish_time = cpu_time();

    exec_time = finish_time - start_time;

    printf("%11d  %9.3e", n, exec_time);

    if (n > start_n) {
      ratio = exec_time / prev_exec_time;
      printf("  %21.5e", ratio);
    }

    printf("\n");

    prev_exec_time = exec_time;
  }

  printf("-----------  ----------  ---------------------\n");

  printf("\n f4 \n");
  printf("          n    time4(n)   time4(n)/time4(n/10)\n");
  printf("-----------  ----------  ---------------------\n");

  for (n = start_n; n <= end_n / 10000; n *= 10) {
    //
    // call function
    //
    start_time = cpu_time();
    f4(n);
    finish_time = cpu_time();

    exec_time = finish_time - start_time;

    printf("%11d  %9.3e", n, exec_time);

    if (n > start_n) {
      ratio = exec_time / prev_exec_time;
      printf("  %21.5e", ratio);
    }

    printf("\n");

    prev_exec_time = exec_time;
  }

  printf("-----------  ----------  ---------------------\n");

  printf("\n f5 \n");
  printf("          n    time5(n)   time5(n)/time5(n/10)\n");
  printf("-----------  ----------  ---------------------\n");

  for (n = start_n; n <= end_n / 10000; n *= 10) {
    //
    // call function
    //
    start_time = cpu_time();
    f5(n);
    finish_time = cpu_time();

    exec_time = finish_time - start_time;

    printf("%11d  %9.3e", n, exec_time);

    if (n > start_n) {
      ratio = exec_time / prev_exec_time;
      printf("  %21.5e", ratio);
    }

    printf("\n");

    prev_exec_time = exec_time;
  }

  printf("-----------  ----------  ---------------------\n");

  printf("\n f6 \n");
  printf("          n    time6(n)   time6(n)/time6(n/10)\n");
  printf("-----------  ----------  ---------------------\n");

  for (n = start_n; n <= end_n; n *= 10) {
    //
    // call function
    //
    start_time = cpu_time();
    f6(n);
    finish_time = cpu_time();

    exec_time = finish_time - start_time;

    printf("%11d  %9.3e", n, exec_time);

    if (n > start_n) {
      ratio = exec_time / prev_exec_time;
      printf("  %21.5e", ratio);
    }

    printf("\n");

    prev_exec_time = exec_time;
  }

  printf("-----------  ----------  ---------------------\n");

  printf("\n f7 \n");
  printf("          n    time7(n)    time7(n)/time7(n/2)\n");
  printf("-----------  ----------  ---------------------\n");

  for (n = 1; n < 33; n *= 2) {
    //
    // call function
    //
    start_time = cpu_time();
    f7(n);
    finish_time = cpu_time();

    exec_time = finish_time - start_time;

    printf("%11d  %9.3e", n, exec_time);

    if (n > 1) {
      ratio = exec_time / prev_exec_time;
      printf("  %21.5e", ratio);
    }

    printf("\n");

    prev_exec_time = exec_time;
  }

  printf("-----------  ----------  ---------------------\n");

  printf("\n\n");

  return 0;
}
