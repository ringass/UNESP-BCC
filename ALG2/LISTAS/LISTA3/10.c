#include <stdio.h>
#define MAX 20

typedef struct
{
  char nome[20];
  int idade;
  float grade;
} A;

int main()
{
  A alunos[MAX];
  int n;

  scanf("%d", &n);
  FILE *file = fopen("alunos.bin", "wb");

  if (file == NULL)
  {
    printf("erro ao abrir o arquivo");
    return 0;
  }

  for (int i = 0; i < n; i++)
  {
    printf("digite o nome: ");
    fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);
    printf("Digite a idade e depois a altura: ");
    scanf("%d", &alunos[i].idade);
    scanf("%f", &alunos[i].grade);
    while (getchar() != '\n')
      ;
  }

  for(int i = 0; i < n; i++){
    fwrite(&alunos[i], sizeof(alunos), 1, file);
  }

  fclose(file);

  return 0;
}