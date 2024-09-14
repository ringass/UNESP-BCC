// Elabore um programa que leia dois arquivos binários (“salbruto.bin” e “desc.bin”) contendo,

// respectivamente, os salários brutos e os descontos de até 100 funcionários. Para cada regis-
// tro, deve-se calcular o salário líquido (salário bruto – descontos) e gravá-lo no arquivo texto

// “salliq.txt”.

#include <stdio.h>
#define MAX 100

typedef struct
{
  double bruto, desc;
} funcionarios;

int main()
{
  funcionarios func[MAX];

  FILE *arq1 = fopen("salbruto.bin", "rb");
  FILE *arq2 = fopen("desc.bin", "rb");

   if (!arq1)
    {
        printf("Erro ao abrir o arquivo salbruto.bin.\n");
        exit(1);
    }

    FILE *arq2 = fopen("desc.bin", "rb");
    if (!arq2)
    {
        printf("Erro ao abrir o arquivo desc.bin.\n");
        fclose(arq1);
        exit(1);
    }
    
  int i = 0;

  while (fread(&func[i].bruto, sizeof(double), 1, arq1) == 1 && fread(&func[i].desc, sizeof(double), 1, arq2) == 1)
  {
    i++;
  }

  fclose(arq1);
  fclose(arq2);

  FILE *final = fopen("salliq.txt", "w");
  if (!final)
  {
    printf("Erro na abertura do arquivo");
    exit(1);
  }

  for (int j = 0; j < i; j++)
  {
    double salliq = func[j].bruto - func[j].desc;
    fprintf(final, "SALARIO LIQUIDO DO FUNCIONARIO 1: %.2lf\n", salliq);
  }
  fclose(final);
};
