#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>

const char unidades[][12] = {"UM ", "DOIS ", "TRÊS ", "QUATRO ", "CINCO ", "SEIS ", "SETE ", "OITO ", "NOVE "};
const char especiais[][12] = {"DEZ ", "ONZE ", "DOZE ", "TREZE ", "QUATORZE ", "QUINZE ", "DEZESSEIS ", "DEZESSETE ", "DEZOITO ", "DEZENOVE "};
const char dezenas[][12] = {"VINTE ", "TRINTA ", "QUARENTA ", "CINQUENTA ", "SESSENTA ", "SETENTA ", "OITENTA ", "NOVENTA "};
const char centenas[][14] = {"CEM ", "CENTO ", "DUZENTOS ", "TREZENTOS ", "QUATROCENTOS ", "QUINHENTOS ", "SEISCENTOS ", "SETECENTOS ", "OITOCENTOS ", "NOVECENTOS "};
const char milhares[][10] = {"BILHÃO", "MILHÃO", "MIL"};
const char milEspecial[][11] = {"BILHÕES", "MILHÕES", "MIL"};

void SepararString(char n[5][4], char z[]);
int Validacao(char *input);

int main()
{
  setlocale(LC_ALL, "Portuguese");
  char p[17], num[5][4];
  int i = 0;

  memset(num, '\0', sizeof(num));

  while (!Validacao(p))
  {
    printf("Digite o valor do seu cheque separando centenas por '.' e centavos por ','): R$ ");
    scanf("%s", p);

    if (!Validacao(p))
    {
      printf("\nEntrada Invalida. Por favor, insira apenas numeros, '.' ou ','.\n\n");
    }
  };

  SepararString(num, p);
  int conv[5];
  int partes = 0;

  for (i = 0; i < 5; i++)
  {
    if (num[i][0] != '\0')
    {
      conv[i] = atoi(num[i]);
      partes++;
    }
  }
  i = 0;
  while (i < partes)
  {
    int cents = conv[i] / 100;
    int dozens = (conv[i] % 100) / 10;
    int units = (conv[i] % 10);

    if (i == partes - 2 && (cents != 0 || dozens != 0 || units != 0) && i != 0)
    {
      printf("E ");
    }

    if (conv[i] == 100)
    {
      printf("%s", centenas[0]);
    }
    else
    {
      if (cents > 0 && dozens >= 1)
      {
        printf("%sE ", centenas[cents]);
      }
      else if (cents > 0)
      {
        printf("%s", centenas[cents]);
      }

      if (dozens == 1 && units >= 0)
      {
        printf("%s", especiais[units]);
      }
      else
      {
        if (dozens > 1)
        {
          printf("%s", dezenas[dozens - 2]);
          if (units > 0)
          {
            printf("E ");
          }
        }
        else if (dozens == 0 && cents > 0 && units > 0)
        {
          printf("E ");
        }

        if (units > 0)
        {
          printf("%s", unidades[units - 1]);
        }
        else if (units == 0 && i == partes - 1)
        {
          printf("ZERO ");
        }
      }
    }
    switch (partes)
    {
    case 5:
      if (i <= 2 && conv[i] != 0)
      {
        printf("%s", (units > 1 || dozens > 0 || cents > 0) ? milEspecial[i] : milhares[i]);
        if (conv[i + 1] != 0 && i < 2)
        {
          printf(", ");
        }else{
          printf(" ");
        }
      }

      break;
    case 4:
      if (i <= 1 && conv[i] != 0)
      {
        printf("%s", (units > 1 || dozens > 0 || cents > 1) ? milEspecial[i + 1] : milhares[i + 1]);
      }

      if (i == 0 && conv[i + 1] != 0)
      {
        printf(", ");
      }

      break;
    case 3:
      if (i == 0)
      {
        printf("%s", milhares[i + 2]);
      }
      break;
    }

    if (i == partes - 2)
    {
      printf("REAIS E ");
    }

    if (i == partes - 1)
    {
      printf("CENTAVOS");
    }

    i++;
  }

  return 0;
}

void SepararString(char n[5][4], char z[])
{
  char *token;
  int i = 0;

  token = strtok(z, ".,");
  while (token != NULL && i < 5)
  {
    strncpy(n[i], token, 3);
    n[i][3] = '\0';
    i++;
    token = strtok(NULL, ".,");
  }
}

int Validacao(char *input)
{
  int length = strlen(input);
  for (int i = 0; i < length; i++)
  {
    if (!isdigit(input[i]) && input[i] != '.' && input[i] != ',')
    {
      return 0;
    }
  }
  return 1;
}
