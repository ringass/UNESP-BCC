#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

void frases()
{
}

int main()
{
  FILE *arq = fopen("aaaa.txt", "r");

  char ch;
  int let[256] = {0}, car, lin, pal = 1, flag = 0;

  car = 0;
  lin = 1;

  while ((ch = fgetc(arq)) != EOF)
  {
    if (ch == '\n')
    { 
      lin++;
      pal++;
    }
    else if (ch == ' ')
    {
      if (flag)
      {
        pal++;
        flag = 0;
      }
    }
    else
    {
      car++;
      if (isalpha(ch))
      {
        let[tolower(ch)]++;
      }
      if (!flag)
      {
        flag = 1;
      }
    }
  }

  printf("%d linhas\n", lin);
  printf("%d caracteres\n", car);
  printf("%d palavras\n\n", pal);

  for (int i = 0; i < 256; i++)
  {
    if (let[i] != 0)
    {
      printf("%c aparece %d vezes\n", i, let[i]);
    }
  }

    return 0;
}