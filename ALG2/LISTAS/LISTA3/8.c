#include <stdio.h>

typedef struct
{
  char nome[20];
  int idade;
  float altura;
} Pessoa;

int main()
{
  FILE *file, *temp;
  Pessoa info[5];

  file = fopen("pessoas.bin", "rb");
  temp = fopen("temp.bin", "wb");

  if (file != NULL)
  {
    printf("existe\n");
    fclose(file);
  }
  else
  {

    printf("não existe\n");
  }
  
  fread(info, sizeof(info), 5, file);
  fclose(file);

  for (int i = 0; i < 5; i++)
  {
    if(i!=1){
      fwrite(&info[i], sizeof(info[i]), 1, temp); 
    }
  }

  fclose(temp);
  remove("pessoas.bin");
  rename("temp.bin", "pessoas.bin");

  return 0;
}
