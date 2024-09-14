#include <stdio.h>
#define MAX 50

void receber(int v[], int x)
{
  FILE *arquivo = fopen("numeros.bin", "wb");

  if (arquivo == NULL)
  {
    printf("erro");
  }
  fwrite(&v, sizeof(int), x, arquivo);
  fclose(arquivo);
}

void copiarPar(int v[], int x)
{
  FILE *arquivo = fopen("numeros.bin", "rb");
  FILE *arquivo2 = fopen("pares.bin", "wb");

  if (arquivo == NULL)
  {
    printf("erro");
    return;
  }
  if (arquivo2 == NULL)
  {
    printf("erro");
    fclose(arquivo);
    return;
  }

  fread(&v, sizeof(v), x, arquivo);
  fclose(arquivo);

  for (int i = 0; i < x; i++)
  {
    if (v[i] % 2 == 0)
    {
      fwrite(&v[i], sizeof(int), 1, arquivo2);
    }
  }

  fclose(arquivo);
}
int main()
{
  int v[MAX], n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    printf("Numero %d: ", i + 1);
    scanf("%d", &v[i]);
  }

  receber(v, n);
  copiarPar(v, n);
}