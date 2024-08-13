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

const char BancoUser[] = "admin10";
const char SenhaUser[] = "12345";
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
void inicio(int op);
int menuInicio();
void ajuda();

int main()
{
  SetConsoleOutputCP(CP_UTF8);
  setlocale(LC_ALL, "Portuguese");
  char p[17], num[5][4];

  memset(p, '\0', sizeof(p));
  memset(num, '\0', sizeof(num));


  int continuar = 1;
  int b;
  while(continuar){
    b = menuInicio();
    SetColor(7);
    if(b == 1){
      break;
    }else if(b == 2){
      
      printf("Saindo...\n\n");
      exit(0);
    }else if(b == 11 || b == 3){
      ajuda();
    }
  }

 
  if(!LoginLogic()){
    system("cls");
    printf("ACESSO NEGADO NEGAOOOOOOOOOOOOO\n\n");
    return 0;
  }else{
    system("cls");
    printf("ACESSO CONCEDIDO NEGAOOOOOOOOO\n\n");
  }

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
  EscreverPorExtenso(num);
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
        else if (units == 0 && i == partes - 1 && dozens == 0)
        {
          printf("ZERO ");
        }
      }
    }


    switch (partes)
    {
    case 5:
      if (i <= 2 && (conv[i] != 0 || conv[i+1] != 0))
      {
        printf("%s", (units > 1 || dozens > 0 || cents > 0) ? milEspecial[i] : milhares[i]);
        if (conv[i + 1] != 0 && i < 2)
        {
          printf(", ");
        }
        else if (i == 0 && conv[i + 1] == 0 && conv[i + 2] == 0)
        {
          printf(" DE ");
        }
        else if(i != partes - 1 && i != partes - 2)
        {
          printf(" ");
        }
      }
      break;
    case 4:
      if (i <= 1 && (conv[i] != 0 || conv[i+1] != 0))
      {
        printf("%s", (units > 1 || dozens > 0 || cents > 1) ? milEspecial[i + 1] : milhares[i + 1]);
      }
      if (i == 0 && conv[i + 1] != 0)
      {
        printf(", ");
      }
      else if (i == 0 && conv[i + 1] == 0)
      {
        printf(" DE ");
      }
      break;
    case 3:
      if (i == 0)
      {
        printf("%s", milhares[i + 2]);
      }
      break;
    }

    if(partes == 2 && i == 0 && units == 1){
      printf("REAL E ");
    }else if (i == partes - 2)
    {
      printf("REAIS E ");
    }
    if (i == partes - 1)
    {
      printf("CENTAVOS\n");
    }
    i++;
  }
}


int LoginLogic(){
  char tryName[15], senha[8];
  int i = 0;
  int x = 3;
  printf("DIGITE SEU USERNAME: ");
  scanf("%s", tryName);
  printf("DIGITE SUA SENHA: ");
  scanf("%s", senha);

  while(x != 0 && !(strcmp(tryName, BancoUser) == 0 && strcmp(senha, SenhaUser) == 0) ){
    printf("%d tentativa, voce tem mais %d tentativas\n", i+1, x);
    printf("DIGITE SEU USERNAME: ");
    scanf("%s", tryName);
    printf("DIGITE SUA SENHA: ");
    scanf("%s", senha);
  i++;
  x--;
}

if(x == 0){
  return 0;
}else{
  return 1;
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

  escreveTexto(3, 85, "BEM-VINDO AO TRABALHO DE CHEQUE", 7);

  for (i = 0; i < 3; i++)
  {
    escreveTexto(6 + i, 95, vet[i], 7);
  }
  escreveTexto(6 + op - 1, 95, vet[op - 1], 2);
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

    if(t == '\x1b'){
      system("cls");
      return 2;
    }
  } while (t != esc);
  return -1;
}

void ajuda()
{ 
    system("cls");
    printf("                                ::::: AJUDA :::::\n");
    printf("O programa funciona transformando seu numero em seu valor por extenso na lingua portuguesa\n");
    printf("\n1- Nao esqueca de separar as centenas de milhar e centenas por pontos\n");
    printf("\n2- Nao esqueca de adicionar os centavos e os separar por virgulas ou pontos\n");
    printf("\n3- Para iniciar o programa sera necessario realizar login\n");
    printf("   -> A senha para entrar no programa eh ""12345"" e o username eh ""admin10"" \n");
    printf("\nATENCAO:\n");
    printf("                   ::::: PRESSIONE ESC PARA VOLTAR AO MENU :::::\n");

    int t;
    while (1) { 
        t = _getch(); 
        if (t == esc) { 
            break; 
        }
    }
    main();
}





