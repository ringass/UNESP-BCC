#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

typedef struct
{
  int minutos;
  int horas;
  int segundos;
} t;

typedef struct
{
  int telefone;
  char cidade[20];
  t tempo;
} registro;

int main()
{
  int i, n[2];
  registro P[MAX];

  FILE *arq1 = fopen("registros1.bat", "wb");
  FILE *arq2 = fopen("registros2.bat", "wb");
  if (arq1 == NULL || arq2 == NULL)
  {
    printf("Erro ao abrir o arquivo.\n");
    return 1;
  }

  printf("Digite quantos registros deseja no arquivo 1: ");
  scanf("%d", &n[0]);

  if (n[0] > MAX)
  {
    printf("Número de registros excede o máximo permitido.\n");
    return 1;
  }

  for (i = 0; i < n[0]; i++)
  {
    printf("Telefone: ");
    scanf("%d", &P[i].telefone);
    getchar(); // Limpa o buffer
    printf("Cidade: ");
    fgets(P[i].cidade, sizeof(P[i].cidade), stdin);
    // Remove o caractere de nova linha se presente
    P[i].cidade[strcspn(P[i].cidade, "\n")] = '\0';
    printf("Digite a duração da ligação (hh:mm:ss): ");
    scanf("%d:%d:%d", &P[i].tempo.horas, &P[i].tempo.minutos, &P[i].tempo.segundos);
  }

  fwrite(P, sizeof(registro), n[0], arq1);
  fclose(arq1);

  FILE *arq1_read = fopen("registros1.bat", "rb");
  if (arq1_read == NULL)
  {
    printf("Erro ao abrir o arquivo para leitura.\n");
    return 1;
  }

  registro P1[n[0]];
  fread(P1, sizeof(registro), n[0], arq1_read);
  fclose(arq1_read);

  printf("Digite quantos registros deseja no arquivo 2: ");
  scanf("%d", &n[1]);

  if (n[1] > MAX)
  {
    printf("Número de registros excede o máximo permitido.\n");
    return 1;
  }

  for (i = 0; i < n[1]; i++)
  {
    printf("Telefone: ");
    scanf("%d", &P[i].telefone);
    getchar(); 
    printf("Cidade: ");
    fgets(P[i].cidade, sizeof(P[i].cidade), stdin);
    P[i].cidade[strcspn(P[i].cidade, "\n")] = '\0';
    printf("Digite a duração da ligação (hh:mm:ss): ");
    scanf("%d:%d:%d", &P[i].tempo.horas, &P[i].tempo.minutos, &P[i].tempo.segundos);
  }

  fwrite(P, sizeof(registro), n[1], arq2);
  fclose(arq2);

  FILE *arq2_read = fopen("registros2.bat", "rb");
  if (arq2_read == NULL)
  {
    printf("Erro ao abrir o arquivo para leitura.\n");
    return 1;
  }

  registro P2[n[1]];
  fread(P2, sizeof(registro), n[1], arq2_read);
  fclose(arq2_read);

  printf("Cidades em comum e seus telefones:\n");
  for (int i = 0; i < n[0]; i++)
  {
    for (int j = 0; j < n[1]; j++)
    {
      if (strcmp(P1[i].cidade, P2[j].cidade) == 0)
      {
        printf("Cidade: %s\n", P1[i].cidade);
        printf("Telefone da cidade '%s': %d\n", P1[i].telefone);
        printf("Telefone da cidade '%s': %d\n", P2[j].telefone);
      }
    }
  }

  return 0;
}
