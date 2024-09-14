#include <stdio.h>
#include <time.h>
#include <windows.h>

int contR = 0, contI = 0;

int F(int i) {
  if (i == 0)
    return 0;

  if (i == 1)
    return 1;

  contR++;
  return F(i - 1) + F(i - 2);
}

int main() {
  clock_t t;

  t = clock();
  printf("%d\n", F(6));
  t = clock() - t;
  printf("recursivo tempo: %f\n", ((float)t) / CLOCKS_PER_SEC);

  int fib[7] = {0};
  fib[0] = 0;
  fib[1] = 1;

  t = clock();
  for (int i = 2; i <= 6; i++) {
    fib[i] = fib[i - 1] + fib[i - 2];
    contI++;
  }
  printf("%d\n\n", fib[6]);
  t = clock() - t;
  printf("iterativo tempo: %f\n", ((float)t) / CLOCKS_PER_SEC);

  printf("iterativo chamadas: %d, recursivo chamadas %d", contI, contR);
}