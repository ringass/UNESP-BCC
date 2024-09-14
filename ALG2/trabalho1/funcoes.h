// funcoes.h
#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>

#define baixo 80
#define cima 72
#define esc 27
#define enter 13
#define f1 59
#define MAX 20

extern const char BancoUser[];
extern const char SenhaUser[];

extern const char unidades[][12];
extern const char especiais[][12];
extern const char dezenas[][12];
extern const char centenas[][14];
extern const char milhares[][11];
extern const char milEspecial[][11];

void gotoxy(int x, int y);
void resizeConsole(int width, int height);
void getConsoleSize(int *width, int *height);
int wherey();
int SetColor(char color);
void SepararString(char n[5][4], char z[]);
int Validacao(char *input);
void EscreverPorExtenso(char num[5][4], char extension[]);
int LoginLogic();
void escreveTexto(int x, int y, char texto[], int cor);
void desenhaQuadrado(int x1, int y1, int x2, int y2, int cor);
void inicio(int op);
int menuInicio();
void ajuda();
int menuRepro(int line);
void Repro(int op, int line);
void GetTime(char p[]);
void LogScreen(char numero[MAX][50], char hora[MAX][50], char extenso[MAX][999], int count);
int main();

#endif
