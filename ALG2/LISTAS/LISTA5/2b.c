#include <stdio.h>

int F(int i)
{
  if (i == 0)
    return 0;
  if (i == 1)
    return 1;
  return F(i - 1) + F(i - 2);
}

int main()
{
  printf("%d", F(6));

  
  int fib[7] = {0};
  fib[0] = 0;
  fib[1] = 1;
  printf("\n%d %d", fib[0], fib[1]);
  for(int i = 2; i <= 6; i++){
    fib[i] = fib[i-1] + fib[i-2];
    printf(" %d", fib[i]);
  }

  printf("\n%d", fib[6]);
}