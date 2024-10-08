#include <stdio.h>

typedef struct
{
  char nome[20];
  int idade;
  float altura;
} Pessoa;

int main()
{
  FILE *file;
  Pessoa info[5];

  file = fopen("pessoas.bin", "rb");

  if (file != NULL)
  {
    printf("existe\n");
    fclose(file);
  }
  else
  {

    printf("não existe\n");
  }

  fseek(file, 0, SEEK_END);

  int qt = ftell(file)/sizeof(Pessoa); 

  fread(&info, sizeof(info), qt, file);

  for (int i = 0; i < qt; i++)
  {
    printf("Pessoa %d:\n", i + 1);
    printf("Nome: %s\n", info[i].nome);
    printf("Idade: %d\n", info[i].idade);
    printf("Altura: %.2f\n", info[i].altura);
  }

  fclose(file);

  return 0;
}
