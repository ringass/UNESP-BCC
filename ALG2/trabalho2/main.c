#include <conio.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define upleft "\u256D"
#define upright "\u256E"
#define botleft "\u2570"
#define botright "\u256F"
#define hline "\u2500"
#define vline "\u2502"
#define baixo 80
#define cima 72
#define esc 27
#define enter 13
#define f1 59


void gotoxy(int x, int y) {
  COORD pos = {x, y};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int SetColor(char color) {
  HANDLE h;
  h = GetStdHandle(STD_OUTPUT_HANDLE);
  return SetConsoleTextAttribute(h, color);
}

void getConsoleSize(int *width, int *height) {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

  *width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
  *height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

void resizeConsole(int width, int height) {
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

  COORD bufferSize = {width, height};
  SetConsoleScreenBufferSize(hConsole, bufferSize);

  SMALL_RECT windowSize = {0, 0, width - 1, height - 1};
  SetConsoleWindowInfo(hConsole, TRUE, &windowSize);
}

void DisplayText(int x, int y, char text[], int color) {
  SetColor(color);
  gotoxy(y, x);
  printf("%s", text);
}

void HelpScreen() { 
  system("cls"); 
  }

void BoxDraw(int xI, int xF, int yI, int yF, int color) {
  int i;

  gotoxy(yI, xI);
  printf("%s", upleft);
  for (i = 1; i < (yF - yI); i++) {
    printf("%s", hline);
  }
  printf("%s", upright);

  for (i = xI + 1; i < xF; i++) {
    gotoxy(yI, i);
    printf("%s", vline);
    gotoxy(yF, i);
    printf("%s", vline);
  }

  gotoxy(yI, xF);
  printf("%s", botleft);
  for (i = 1; i < (yF - yI); i++) {
    printf("%s", hline);
  }
  printf("%s", botright);
}

void MenuDisplay(int op) {
    char v[][30] = { "Inserir", "Alterar", "Remover", "Consultar", "Ajuda(F1)", "Sair(Esc)" };
    int i;

    for (i = 0; i < 6; i++) {
        int len = strlen(v[i]) + 4;

        if (i == op - 1) {    
            int co = (op == 6 ? 4 : 1);

            DisplayText(8 + (i * 3), 4, v[i], co); 
            BoxDraw(7 + (i * 3), 9 + (i * 3), 2, 2 + len, co); 
        } else {
            DisplayText(8 + (i * 3), 4, v[i], 7);
            BoxDraw(7 + (i * 3), 9 + (i * 3), 2, 2 + len, 7);
        }
    }

    gotoxy(0, 29);
}

int MenuLogic() {
    int op = 1;  
    char t;

    DisplayText(3, 20, "PROJETO BLABLABLA", 7);
    BoxDraw(1, 27, 0, 50, 9);

    MenuDisplay(op);

    do {
        t = getch();

        if (t == baixo) {
            if (op < 6)
                op++;
            else
                op = 1;
            MenuDisplay(op);

        } else if (t == cima) {
            if (op > 1)
                op--;
            else
                op = 6;
            MenuDisplay(op);

        } else if (t == f1) {
            return op = 11;  
        } else if (t == enter) {
            return op;  
        } else if (t == esc) {
            system("cls");
            return -1;
        }
    } while (t != esc);

    return -1;
}


int main() {

  SetConsoleOutputCP(CP_UTF8);
  system("cls");

  int continuar = 1;
  int b;

  while(continuar){
    b = MenuLogic();
    SetColor(7);

    if(b == 1){
      //func para inserir em algum arquivo
      break;
    }else if(b == 2){
      //func para alterar de algum arquivo
      break;
    }else if(b == 3){
      //func para remover de algum arquivo
      break;
    }else if(b == 4){
      //func para consultar de algum arquivo
      break;
    }else if(b == 5 || b == 11){
      //func para abrir arquivo ajuda.txt e mostrar no cmd
      break;
    }
    else if( b == 6){
      printf("SAINDO DO PROGRAMA VALEUU FIO\n\n");
      exit(1);
    }
  }

  return 0;
}
