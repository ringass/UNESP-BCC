#include <stdio.h>

int F(int n)
{
  if (n == 0)
    return 1;
  if (n == 1)
    return 2;
  return 2 * F(n - 2) * F(n - 1);
}

int main()
{ 

  printf("%d", F(4));

  return 0;
}