#include <assert.h>
#include <stdio.h>

size_t N_CALLS;

size_t recursive(size_t n) {
  assert(n > 0);

  if (n == 1) {
    return 1;
  }

  N_CALLS += 2;
  return n + recursive(n / 2) + recursive((n + 1) / 2);
}

int main(void) {
  size_t n = 0, r = 0;
  printf("Valor de n (inteiro nao-negativo): ");
  scanf("%ld", &n);
  printf("\nCalculo do valor da recorrencia 2:\n\n");

  for (size_t i = 1; i <= n; i++) {

    N_CALLS = 0;

    r = recursive(i);

    printf("T\(%3ld) = %6ld", i, r);

    printf(" --- Numero de chamadas recursivas = %3ld\n", N_CALLS);
  }

  printf("\n\n");

  return 0;
}