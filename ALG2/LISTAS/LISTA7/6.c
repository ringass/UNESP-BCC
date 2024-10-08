#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

void sort(int v[], int len)
{

  int flag = 1;

  while (flag != 0)
  {
    flag = 1;

    for (int i = 0; i < len; i++)
    {
      flag = 0;
      if (v[i] > v[i + 1])
      {
        int aux = v[i];
        v[i] = v[i + 1];
        v[i + 1] = aux;
        flag = 1;
      }
    }
  }
}

int main()
{

  int n, x;
  scanf("%d", &n);

  int *v = (int *)malloc(n * sizeof(int));

  for (int i = 0; i < n; i++)
  {
    scanf("%d", &v[i]);
  }

  sort(v, n);

  int count, maior = 0, maiornum = 0;

  for (int i = 0, j = 0; i < n; i++)
  {

    if (v[i] == v[i + 1])
    {
      count++;
    }

    if (count > maior)
    {
      maior = count;
      maiornum = v[i + 1];
    }
    else if (count == maior && v[i + 1] != v[i])
    {
      maior = count;

      if (v[i] < maiornum)
      {
        maiornum = v[i];
      }
      
    }
  }

  printf("%d", maiornum);
  return 0;
}