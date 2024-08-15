#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>
#include <Windows.h>
#include <conio.h>


#define upleft
#define botleft
#define upright '╮'
#define botright
#define baixo 80
#define cima 72
#define esc 27
#define enter 13
#define f1 59


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

void getConsoleSize(int *width, int *height) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, rows;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    *width = columns;
    *height = rows;
}

void resizeConsole(int width, int height) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    
    COORD bufferSize = {width, height};
    SetConsoleScreenBufferSize(hConsole, bufferSize);

    SMALL_RECT windowSize = {0, 0, width - 1, height - 1};
    SetConsoleWindowInfo(hConsole, TRUE, &windowSize);
}


const char BancoUser[] = "1";
const char SenhaUser[] = "1";
const char unidades[][12] = {"UM ", "DOIS ", "TRES ", "QUATRO ", "CINCO ", "SEIS ", "SETE ", "OITO ", "NOVE "};
const char especiais[][12] = {"DEZ ", "ONZE ", "DOZE ", "TREZE ", "QUATORZE ", "QUINZE ", "DEZESSEIS ", "DEZESSETE ", "DEZOITO ", "DEZENOVE "};
const char dezenas[][12] = {"VINTE ", "TRINTA ", "QUARENTA ", "CINQUENTA ", "SESSENTA ", "SETENTA ", "OITENTA ", "NOVENTA "};
const char centenas[][14] = {"CEM ", "CENTO ", "DUZENTOS ", "TREZENTOS ", "QUATROCENTOS ", "QUINHENTOS ", "SEISCENTOS ", "SETECENTOS ", "OITOCENTOS ", "NOVECENTOS "};
const char milhares[][11] = {"BILHAO", "MILHAO", "MIL"};
const char milEspecial[][11] = {"BILHOES", "MILHOES", "MIL"};


void SepararString(char n[5][4], char z[]);
int Validacao(char *input);
void EscreverPorExtenso(char num[5][4]);
int LoginLogic();
void escreveTexto(int x, int y, char texto[], int cor);
void desenhaQuadrado(int x1, int y1, int x2, int y2, int cor);
void inicio(int op);
int menuInicio();
void ajuda();


int main()
{
  SetConsoleOutputCP(CP_UTF8);
  setlocale(LC_ALL, "Portuguese");
  char p[17], num[5][4];
  system("mode 165,25");   
  SMALL_RECT WinRect = {0, 0, 165, 25};
  SMALL_RECT* WinSize = &WinRect;
  SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, WinSize);

  memset(p, '\0', sizeof(p));
  memset(num, '\0', sizeof(num));

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
    printf("ACESSO CONCEDIDO NEGAOOOOOOOOO\n\n");
  }

int continuar = 1;
while(!continuar){
  do
  {
    printf("Digite o valor do seu cheque separando centenas por '.' e centavos por ','): R$ ");
    scanf("%s", p);


    if (!Validacao(p))
    {
      printf("\nEntrada Invalida. Por favor, insira apenas numeros, '.' ou ','.\n\n");
    }
  } while (!Validacao(p));
  SepararString(num, p);

  int x, y;

  EscreverPorExtenso(num);
  getConsoleSize(&x, &y);

  printf("largura: %d, altura: %d", x, y);


}
}

int Reprocessamento(int n){
  desenhaQuadrado(1, 60, 12, 102, 7);
}


void SepararString(char n[5][4], char z[])
{
  char *token;
  int i = 0, count = 0;


  token = strtok(z, ".,");
  while (token != NULL && i < 5)
  {
    count++;
    strncpy(n[i], token, 3);
    n[i][3] = '\0';
    i++;
    token = strtok(NULL, ".,");
  }
  if (isdigit(n[count - 1][2]))
  {
    n[count - 1][2] = '\0';
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


void EscreverPorExtenso(char num[5][4])
{
  int conv[5];
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


  for (int i = 0; i < partes; i++)
  {
    if (partes == 1)
    {
      conv[i + 1] = 0;
      partes = partes + 1;
    }
  }


  i = 0;


  while (i < partes)
  {
    int cents = conv[i] / 100;
    int dozens = (conv[i] % 100) / 10;
    int units = (conv[i] % 10);


   


    if (conv[i] == 100)
    {
      strcat( str, centenas[0]);
      printf("%s", centenas[0]);
    }
    else
    {


      if (cents > 0 && dozens >= 1)
      {
        strcat( str, centenas[cents]);
        strcat(str, "E ");
        printf("%sE ", centenas[cents]);
      }
      else if (cents > 0)
      {
        strcat( str, centenas[cents]);
        printf("%s", centenas[cents]);
      }


      if (dozens == 1 && units >= 0)
      {
        strcat( str, especiais[units]);
        printf("%s", especiais[units]);
      }
      else
      {
        if (dozens > 1)
        {
          strcat( str, dezenas[dozens - 2]);
          printf("%s", dezenas[dozens - 2]);
          if (units > 0)
          {
            strcat( str, "E ");
            printf("E ");
          }
        }
        else if (dozens == 0 && cents > 0 && units > 0)
        {
          strcat( str, "E ");
          printf("E ");
        }


        if (units > 0)
        {
          strcat( str, unidades[units - 1]);
          printf("%s", unidades[units - 1]);
        }
        else if (units == 0 && i == partes - 1 && dozens == 0)
        {
          strcat( str, "ZERO ");
          printf("ZERO ");
        }
      }
    }

    switch (partes)
    {
    case 5:
      if (i <= 2 && (conv[i] != 0)) //|| conv[i + 1] != 0))
      {
        strcat( str, (units > 1 || dozens > 0 || cents > 0) ? milEspecial[i] : milhares[i]);
        printf("%s", (units > 1 || dozens > 0 || cents > 0) ? milEspecial[i] : milhares[i]);
        
        if (i == 1 && (conv[i+1] != 0 || conv[i+2] != 0))
        {
          strcat( str, ", ");
          printf(", ");
        }else if(i == 0 && (conv[i+1] != 0 || conv[i+2] != 0 || conv[i+3]) ){
          strcat( str, ", ");
          printf(", ");
        }
        else if (i == 0 && conv[i + 1] == 0 && conv[i + 2] == 0 && conv[i+3] == 0)
        {
          strcat( str, " DE ");
          printf(" DE ");
        }
        else if (i != partes - 1 && i != partes - 2)
        {
          strcat(str, " ");
          printf(" ");
        }
        if(i == partes - 3 && conv[i+1] != 0){
          strcat(str, "E ");
          printf("E ");
        }
      }
      break;
    case 4:
      if (i <= 1 && (conv[i] != 0))
      {
        strcat( str, (units > 1 || dozens > 0 || cents > 1) ? milEspecial[i + 1] : milhares[i + 1]);
        printf("%s", (units > 1 || dozens > 0 || cents > 1) ? milEspecial[i + 1] : milhares[i + 1]);
      if (i == 0 && (conv[i + 1] != 0|| conv[i+2] != 0))
      {
        strcat( str, ", ");
        printf(", ");
      }
      else if (i == 0 && conv[i + 1] == 0 && conv[i+2] == 0)
      {
        strcat( str, " DE ");
        printf(" DE ");
      }else if(i == 1 && conv[i+1] == 0){
        strcat( str, " ");
        printf(" ");
      }
      if (i == partes - 3 && conv[i+1] != 0)
      {
        strcat(str, " E ");
        printf(" E ");
      }
      }
      break;
    case 3:
      if (i == 0 && conv[i] != 0)
      {
        strcat(str, milhares[i + 2]);
        printf("%s ", milhares[i + 2]);
        strcat(str, " ");
      }
      break;
    }

    if (i == partes - 2 && conv[i] == 1 && conv[i-1] == 0)
    {
      strcat(str, "REAL E ");
      printf("REAL E ");
    }
    else if (i == partes - 2 && (conv[i] > 1 || conv[i-1] != 0 || conv[i-2] != 0 || conv[i-3] != 0))
    {
      strcat(str, "REAIS E ");
      printf("REAIS E ");
    }
    if (i == partes - 1)
    {
      strcat(str, "CENTAVOS");
      printf("CENTAVOS\n");
    }
    i++;
  }
  printf("%s", str);
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


void ajuda() {
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
    escreveTexto(16, 6, "-> A senha para entrar no programa eh 12345", 7);
    escreveTexto(17, 6, "e o username eh admin10.", 7);
    escreveTexto(19, 17, "::::: PRESSIONE ESC PARA VOLTAR AO MENU :::::", 7);

    int t;
    while (1) {
        t = _getch();
        if (t == esc) {
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


