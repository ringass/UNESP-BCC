#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct
{
  char nome[20], rua[30], cidade[20], estado[3];
  int numero, telefone;
} dados;

void LerDados(dados n[], int *count)
{
  int x;
  printf("Digite quantos deseja cadastrar: ");
  scanf("%d", &x);
  getchar();

  for (int i = 0; i < x; i++)
  {
    printf("Digite o nome: ");
    fgets(n[i].nome, sizeof(n[i].nome), stdin);

    printf("Digite o telefone: ");
    scanf("%d", &n[i].telefone);

    printf("Digite o numero: ");
    scanf("%d", &n[i].numero);
    getchar();

    printf("Digite o estado: ");
    fgets(n[i].estado, sizeof(n[i].estado), stdin);
    getchar();

    printf("Digite a cidade: ");
    fgets(n[i].cidade, sizeof(n[i].cidade), stdin);

    getchar();
    printf("Digite a rua: ");
    fgets(n[i].rua, sizeof(n[i].rua), stdin);
  }

  *count = x;
}

int main()
{
  int n;
  int p = 0;
  dados here[MAX];

  printf("Digite a operação que deseja fazer:\n1 - criar\n2 - listar\n3 - remover\n0 - sair\n ");
  scanf("%d", &n);

  if (n == 1)
  {
    FILE *arquivo = fopen("agenda.dat", "wb");
    if (arquivo == NULL)
    {
      printf("Erro ao abrir o arquivo para escrita.\n");
      return 1;
    }
    LerDados(here, &p);

    for (int k = 0; k < p; k++)
    {
      fwrite(&here[k], sizeof(dados), 1, arquivo);
    }
    fclose(arquivo);
  }
  else if (n == 2)
  {
    FILE *arquivo = fopen("agenda.dat", "rb");
    if (arquivo == NULL)
    {
      printf("Erro ao abrir o arquivo para leitura.\n");
      return 1;
    }

    while (fread(&here[p], sizeof(dados), 1, arquivo) > 0)
    {
      printf("Nome: %sTelefone: %d\nEstado: %sCidade: %sRua: %sNumero: %d\n",
             here[p].nome, here[p].telefone, here[p].estado, here[p].cidade, here[p].rua, here[p].numero);
      p++;
    }
    fclose(arquivo);
  }
  else if (n == 3)
  {
    dados temp[MAX];
    int h;

    scanf("%d", &h);

    FILE *arquivo = fopen("agenda.dat", "rb");
    if (arquivo != NULL)
    {
      printf("existe\n");
      fclose(arquivo);
    }
    else
    {
      printf("não existe\n");
    }

    int z = 0;
    while (fread(&temp[z], sizeof(dados), 1, arquivo) == 1)
    {
      z++;
    }
    fclose(arquivo);

    arquivo = fopen("agenda.dat", "wb");
    if (arquivo == NULL)
    {
      printf("erro ao abrir o arquivo");
      return 0;
    }
    for (int i = 0; i < z; i++)
    {
      if (i != h)
      {
        fwrite(&temp[i], sizeof(dados), 1, arquivo);
      }
    }
    fclose(arquivo);
    printf("Registro removido com sucesso.\n");
  }
  else
  {
    return 0;
  }

  return 0;
}
