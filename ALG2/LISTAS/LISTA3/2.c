#include <stdio.h>

int main()
{
  FILE *file;
  int numbers[5];

  file = fopen("dados.bin", "rb");
  if (file == NULL)
  {
    printf("Erro ao abrir o arquivo para escrita!\n");
    return 1;
  }

  fread(&numbers, sizeof(numbers), 5, file);
  for (int i = 0; i < 5; i++)
  {
    printf("Número %d: ", numbers[i]);
  }

  fclose(file);

  printf("Números gravados dados.bin.\n");

  return 0;
}
