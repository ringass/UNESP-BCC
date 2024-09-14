#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  char nome[20];
  int idade;
  float altura;
} Pessoa;

int main()
{
  Pessoa alunos[5];

  for (int i = 0; i < 5; i++)
  {
    printf("digite o nome: ");
    fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);
    printf("Digite a idade e depois a altura: ");
    scanf("%d", &alunos[i].idade);
    scanf("%f", &alunos[i].altura);
   while(getchar() != '\n');
  }

  FILE* arq = fopen("pessoas.bin", "wb");

  if(arq == NULL){
    printf("falha ao abrir arquivo");
    return 0;
  }

  for(int i = 0; i < 5; i++){
    fwrite(&alunos[i], sizeof(alunos), 1, arq);
  }

  fclose(arq);
}
