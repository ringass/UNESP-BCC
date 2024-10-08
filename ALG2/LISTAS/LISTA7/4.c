#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

void Insercao(int n, float *vet)
{
  float aux;
  int i, j;
  for (i = 1; i < n; i++)
  {
    aux = vet[i];
    j = i - 1;
    while (j >= 0 && aux > vet[j])
    {
      vet[j + 1] = vet[j];
      j = j - 1;
    }
    vet[j + 1] = aux;
  }
}

int main()
{

  float v[10] = {7, 9, 5 ,4, 10, 15, 25, 90, 1, 32};

  Insercao(10, v);

  for(int i = 0; i < 10; i++){
    printf("%.2f ", v[i]);
  }

  return 0;
}