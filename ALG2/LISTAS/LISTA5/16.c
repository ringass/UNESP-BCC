#include <stdio.h>

int F(int m, int n)
{
  if (m == 0)
  {
    return n + 1;
  }
  else if (n == 0 && m != 0)
  {
    return F(m - 1, 1);
  }
  
  return F(m-1, F(m, n-1));
}

int main()
{

  printf("%d", F(2, 2));

  return 0;
}