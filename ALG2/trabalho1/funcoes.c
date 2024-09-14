//funcoes.h
#include "funcoes.h"

//INFORMACOES PARA LOGIN
const char BancoUser[] = "admin10"; 
const char SenhaUser[] = "12345";

//DEFINICAO DE VARIAVEIS PARA ESCREVER POR EXTENSO
const char unidades[][12] = {"UM ", "DOIS ", "TRES ", "QUATRO ", "CINCO ", "SEIS ", "SETE ", "OITO ", "NOVE "};
const char especiais[][12] = {"DEZ ", "ONZE ", "DOZE ", "TREZE ", "QUATORZE ", "QUINZE ", "DEZESSEIS ", "DEZESSETE ", "DEZOITO ", "DEZENOVE "};
const char dezenas[][12] = {"VINTE ", "TRINTA ", "QUARENTA ", "CINQUENTA ", "SESSENTA ", "SETENTA ", "OITENTA ", "NOVENTA "};
const char centenas[][14] = {"CEM ", "CENTO ", "DUZENTOS ", "TREZENTOS ", "QUATROCENTOS ", "QUINHENTOS ", "SEISCENTOS ", "SETECENTOS ", "OITOCENTOS ", "NOVECENTOS "};
const char milhares[][11] = {"BILHAO", "MILHAO", "MIL"};
const char milEspecial[][11] = {"BILHOES", "MILHOES", "MIL"};

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

  if (length > 18)
  {
    return 0;
  }

  if (length == 7) {
    for (int i = length; i > 1; i--) {
      input[i] = input[i - 1];
    }
    input[1] = '.';
    input[length + 1] = '\0';  
  }

  int count = 0;
  for (int i = 0; i < length; i++)
  {
    if (isdigit(input[i]))
    {
      count++;
    }
    else if (input[i] == '.' || input[i] == ',')
    {
      if (count > 3) 
      {
        return 0;
      }
      count = 0; 
    }
    else
    {
      return 0; 
    }
  }

  if (count > 3)
  {
    return 0;
  }

  return 1;
}

void EscreverPorExtenso(char num[5][4], char copy[])
{
  int conv[5] = {0};
  int partes = 0;
  int i;
  SetColor(7);
  char str[999] = "";

  for (i = 0; i < 5; i++)
  {
    if (num[i][0] != '\0')
    {
      conv[i] = atoi(num[i]);
      partes++;
    }
  }

    if (partes == 1)
    {
      conv[i + 1] = 0;
      partes = partes + 1;
    }
    
  i = 0;

  while (i < partes)
  {
    int cents = conv[i] / 100;
    int dozens = (conv[i] % 100) / 10;
    int units = (conv[i] % 10);

    if (i == partes - 1 && (conv[i] == 0 || conv[i] > 99))
    {
        conv[i] = 0;
    }

    if (conv[i] == 100)
    {
      strcat(str, centenas[0]);
    }
    else
    {
      if (cents > 0 && dozens >= 1)
      {
        strcat(str, centenas[cents]);
        strcat(str, "E ");
      }
      else if (cents > 0)
      {
        strcat(str, centenas[cents]);
      }

      if (dozens == 1 && units >= 0)
      {
        strcat(str, especiais[units]);
      }
      else
      {
        if (dozens > 1)
        {
          strcat(str, dezenas[dozens - 2]);
          if (units > 0)
          {
            strcat(str, "E ");
          }
        }
        else if (dozens == 0 && cents > 0 && units > 0)
        {
          strcat(str, "E ");
        }

        if (units > 0)
        {
          strcat(str, unidades[units - 1]);
        }
        else if (units == 0 && i == partes - 1 && dozens == 0 && cents == 0)
        {
          strcat(str, "ZERO ");
        }
      }
    }
    switch (partes)
    {
    case 5:
      if (i <= 2 && (conv[i] != 0)) 
      {
        strcat(str, (units > 1 || dozens > 0 || cents > 0) ? milEspecial[i] : milhares[i]);
        if (i == 1 && (conv[i + 1] != 0 || conv[i + 2] != 0))
        {
          strcat(str, ", ");
        }
        else if (i == 0 && (conv[i + 1] != 0 || conv[i + 2] != 0 || conv[i + 3]))
        {
          strcat(str, ", ");
        }
        else if (i == 0 && conv[i + 1] == 0 && conv[i + 2] == 0 && conv[i + 3] == 0)
        {
          strcat(str, " DE ");
        }
        else if (i == 1 && conv[i + 1] == 0 && conv[i + 2] == 0 && conv[i + 3] == 0)
        {
          strcat(str, " DE ");
        }
        else if (i != partes - 1 && i != partes - 2)
        {
          strcat(str, " ");
        }
        if (i == partes - 3 && conv[i + 1] != 0)
        {
          strcat(str, "E ");
        }
      }
      break;
    case 4:
      if (i <= 1 && conv[i] != 0)
      {
        strcat(str, (units > 1 || dozens > 0 || cents > 1) ? milEspecial[i + 1] : milhares[i + 1]);
        if (i == 0 && (conv[i + 1] != 0 || conv[i + 2] != 0))
        {
          strcat(str, ", ");
        }
        else if (i == 0 && conv[i + 1] == 0 && conv[i + 2] == 0)
        {
          strcat(str, " DE ");
        }
        else if (i == 1 && conv[i + 1] == 0)
        {
          strcat(str, " ");
        }
        if (i == partes - 3 && conv[i + 1] != 0)
        {
          strcat(str, " E ");
        }
      }
      break;
    case 3:
      if (i == 0 && conv[i] != 0)
      {
        strcat(str, milhares[i + 2]);
        strcat(str, " ");
      }
      break;
    }

    if (i == partes - 2 && conv[i] == 1 && conv[i - 1] == 0)
    {
      strcat(str, "REAL E ");
    }
    else if (i == partes - 2 && (conv[i] > 1 || conv[i - 1] != 0 || conv[i - 2] != 0 || conv[i - 3] != 0))
    {
      strcat(str, "REAIS E ");
    }
    if (i == partes - 1)
    {
      strcat(str, "CENTAVOS");
    }
    i++;
  }
  strcpy(copy, str);
  printf("%s", str);
}

void GetTime(char p[])
{
  struct tm *hora_atual;

  time_t segundos;

  time(&segundos);

  hora_atual = localtime(&segundos);
  char Horario[50];
  sprintf(Horario, "HORA: %02d:%02d:%02d", hora_atual->tm_hour, hora_atual->tm_min, hora_atual->tm_sec);
  strcpy(p, Horario);
}

int LoginLogic()
{
  char tryName[15], senha[8];
  int i = 0;
  int x = 3;
  while (1)
  {
    desenhaQuadrado(1, 60, 12, 102, 7);
    escreveTexto(3, 75, "LOGIN PAGE", 7);

    while (x != 0)
    {
      escreveTexto(5, 65, "DIGITE SEU USERNAME:            ", 7);
      gotoxy(86, 5);
      scanf("%s", tryName);

      escreveTexto(7, 65, "DIGITE SUA SENHA:               ", 7);
      gotoxy(83, 7);
      scanf("%s", senha);

      if (strcmp(tryName, BancoUser) == 0 && strcmp(senha, SenhaUser) == 0)
      {
        return 1;
      }
      else
      {
        escreveTexto(9, 65, "LOGIN OU SENHA INCORRETOS!", 4);
        i++;
        x--;

        if (x > 0)
        {

          char tentativaMsg[50];
          sprintf(tentativaMsg, "Voce tem mais %d tentativa(s)", x);
          escreveTexto(10, 65, tentativaMsg, 7);
        }
      }

      escreveTexto(5, 86, "               ", 7);
      escreveTexto(7, 83, "               ", 7);
    }

    if (x == 0)
    {
      system("cls");
      desenhaQuadrado(1, 60, 12, 102, 7);
      escreveTexto(6, 63, "LOGIN OU SENHA INCORRETOS!", 4);
      escreveTexto(7, 63, "TODAS AS TENTATIVAS FORAM UTILIZADAS", 4);
      SetColor(7);
      gotoxy(13, 13);
      return 0;
    }
  }
}

void escreveTexto(int x, int y, char texto[], int cor)
{
  SetColor(cor);
  gotoxy(y, x);
  printf("%s", texto);
}

void inicio(int op)
{
  char vet[][30] = {"INICIAR", "SAIR (ESC)", "AJUDA (F1)"};
  int i;
  system("cls");
  desenhaQuadrado(1, 60, 10, 102, 7);
  escreveTexto(3, 65, "BEM-VINDO AO TRABALHO DE CHEQUE\n", 7);

  for (i = 0; i < 3; i++)
  {
    escreveTexto(6 + i, 75, vet[i], 7);
  }
  escreveTexto(6 + op - 1, 75, vet[op - 1], 2);
}

int menuInicio()
{
  int op;
  char t;
  op = 1;
  inicio(op);
  do
  {
    t = getch();
    if (t <= 0)
    {
      t = getch();
      if (t == baixo)
      {
        if (op != 3)
          op++;
        else
          op = 1;
        inicio(op);
      }
      else if (t == cima)
      {
        if (op != 1)
          op--;
        else
          op = 3;
        inicio(op);
      }
      else if (t == f1)
        return op = 11;
    }
    else if (t == enter)
    {
      system("cls");
      return op;
    }
    if (t == '\x1b')
    {
      system("cls");
      return 2;
    }
  } while (t != esc);
  return -1;
}

void ajuda()
{
  system("cls");

  desenhaQuadrado(1, 2, 20, 78, 7);

  escreveTexto(3, 30, "::::: AJUDA :::::", 7);
  escreveTexto(5, 4, "O programa funciona transformando seu numero", 7);
  escreveTexto(6, 4, "em seu valor por extenso na lingua portuguesa.", 7);
  escreveTexto(8, 4, "1- Nao esqueca de separar as centenas de milhar", 7);
  escreveTexto(9, 4, "e centenas por pontos.", 7);
  escreveTexto(11, 4, "2- Nao esqueca de adicionar os centavos e", 7);
  escreveTexto(12, 4, "os separar por virgulas ou pontos.", 7);
  escreveTexto(14, 4, "3- Para iniciar o programa sera necessario", 7);
  escreveTexto(15, 4, "realizar login.", 7);
  escreveTexto(16, 6, "-> A senha para entrar no programa eh ::::12345::::", 7);
  escreveTexto(17, 6, "-> O username eh ::::admin10::::", 7);
  escreveTexto(19, 17, "::::: PRESSIONE ESC PARA VOLTAR AO MENU :::::", 7);

  int t;
  while (1)
  {
    t = _getch();
    if (t == esc)
    {
      break;
    }
  }
  main();
}

void desenhaQuadrado(int x1, int y1, int x2, int y2, int cor)
{
  char linha[100];
  for (int i = 0; i < (y2 - y1 + 1); i++)
  {
    linha[i] = '*';
  }
  linha[y2 - y1 + 1] = '\0';

  escreveTexto(x1, y1, linha, cor);

  for (int i = x1 + 1; i < x2; i++)
  {
    escreveTexto(i, y1, "*", cor);
    escreveTexto(i, y2, "*", cor);
  }

  escreveTexto(x2, y1, linha, cor);
}
void Repro(int op, int line)
{
  char vet[][30] = {"SIM", "NAO"};
  int i;
  

  desenhaQuadrado(line + 2, 60, line + 9, 90, 7);

  escreveTexto(line + 4, 67, "REPETIR PROCESSO?", 7);

  for (i = 0; i < 2; i++)
  {
    escreveTexto(line + 6 + i, 73, vet[i], 7);
  }

  escreveTexto(line + 6 + op - 1, 73, vet[op - 1], 2);
}

int menuRepro(int line)
{
  int op = 1;
  char t;
  
  Repro(op, line);

  do
  {
    t = getch();
    if (t <= 0)
    {
      t = getch();
      if (t == baixo)
      {
        if (op != 2)
          op++;
        else
          op = 1;
        
        Repro(op, line);
      }
      else if (t == cima)
      {
        if (op != 1)
          op--;
        else
          op = 2;
        Repro(op, line);
      }
    }
    else if (t == enter)
    {
      system("cls");
      return op;
    }
    if (t == esc)
    {
      system("cls");
      return 2;
    }
  } while (t != esc);
  
  return -1;
}


void LogScreen(char numero[MAX][50], char hora[MAX][50], char extenso[MAX][999], int count)
{
  int x, y;
  getConsoleSize(&x, &y);
  for(int i = 0; i < count; i++){
    for(int j = 0; j < x; j++){
      printf("*");
    }
    printf("\n");
    printf("%s\n", hora[i]);
    printf("Valor Monetario em numerais -> %s\n", numero[i]);
    printf("Valor por Extenso -> %s\n", extenso[i]);
    printf("\n");
  }
  for(int j = 0; j < x; j++){
      printf("*");
  }
}


void gotoxy(int x, int y)
{
  COORD pos = {x, y};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int SetColor(char color)
{
  HANDLE h;
  h = GetStdHandle(STD_OUTPUT_HANDLE);
  return SetConsoleTextAttribute(h, color);
}

void getConsoleSize(int *width, int *height)
{
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  int columns, rows;

  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

  columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
  rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

  *width = columns;
  *height = rows;
}

void resizeConsole(int width, int height)
{
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

  COORD bufferSize = {width, height};
  SetConsoleScreenBufferSize(hConsole, bufferSize);

  SMALL_RECT windowSize = {0, 0, width - 1, height - 1};
  SetConsoleWindowInfo(hConsole, TRUE, &windowSize);
}

int wherey()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;    
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);    
    return csbi.dwCursorPosition.Y;
}