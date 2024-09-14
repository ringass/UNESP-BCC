// main.c
#include "funcoes.h"

int main()
{
  SetConsoleOutputCP(CP_UTF8);
  setlocale(LC_ALL, "Portuguese");

  system("mode 165, 45");
  SMALL_RECT WinRect = {0, 0, 165, 45};
  SMALL_RECT *WinSize = &WinRect;
  SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, WinSize);

  int continuar = 1;
  int b;
  while (continuar)
  {
    b = menuInicio();
    SetColor(7);
    if (b == 1)
    {
      break;
    }
    else if (b == 2)
    {
      printf("Saindo...\n\n");
      exit(0);
    }
    else if (b == 11 || b == 3)
    {
      ajuda();
    }
  }

  if (!LoginLogic())
  {
    return 0;
  }
  else
  {
    system("cls");
    escreveTexto(0, 0, "ACESSO CONCEDIDO!\n", 2);
    SetColor(7);
  }

  int run = 1;
  int c, x = 0, line = 0;
  char hora[MAX][50], number[MAX][50], extension[MAX][999];

  while (run)
  {
    char p[17], num[5][4];
    memset(p, '\0', sizeof(p));
    memset(num, '\0', sizeof(num));
    do
    {
      printf("Digite o valor do seu cheque separando por '.' ou ','): R$ ");
      scanf("%s", p);

      if (!Validacao(p))
      {
        system("cls");
        printf("\nEntrada Invalida. Por favor, insira apenas numeros, '.' ou ','.\n\n");
      }
    } while (!Validacao(p));

    strcpy(number[x], p);
    SepararString(num, p);
    EscreverPorExtenso(num, extension[x]);
    line = wherey();
    GetTime(hora[x]);
    x++;

    c = menuRepro(line);
    SetColor(7);
    if (c == 1)
    {
      continue;
    }
    else if (c == 2)
    {
      LogScreen(number, hora, extension, x);
      break;
    }
  }
}
