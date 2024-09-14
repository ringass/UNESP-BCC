// Faça um programa que leia o arquivo texto “texto.txt” e grave todas as palavras iniciadas

// com vogais no arquivo texto “vogais.txt”. O programa deve também mostrar na tela o ar-
// quivo “texto.txt”, durante a procura das palavras, e o número de palavras gravadas em

// “vogais.txt”.

#include <stdio.h>
#include <string.h>

int main()
{
  FILE *origem = fopen("texto.txt", "r");
  FILE *vogal = fopen("vogais.txt", "w");

  if (origem == NULL)
  {
    printf("erro origem");
    return 1;
  }
  else if (vogal == NULL)
  {
    printf("erro vogal");
    return 1;
  }

  char ch[100];
  int count = 0;


  while ((fscanf(origem, "%s", ch)) != EOF)
  {
    
    printf("%s", ch);

    char a = (toupper(ch[0]);

    if ( a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U')
    {
      fprintf(vogal, "%s\n", ch);
      count++;
    }
  }

  printf("%d vogais", count);

  fclose(origem);
  fclose(vogal);

  return 0;
}