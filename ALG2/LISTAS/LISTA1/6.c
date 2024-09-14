#include <stdio.h>

int main()
{
  char p[100];
  int i = 0;

  gets(p);

  i = strlen(p);
  for (i = i - 1; i >= 0; i--)
  {
    printf("%c", p[i]);
  }
  
}