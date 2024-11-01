#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX 20
struct data
{
    int dia, mes, ano;
};

struct horario
{
    int hr, min, sec;
};

typedef struct
{
    char text[200];
    struct data dt;
    struct horario hora;
} compromissos;


void inserir(compromissos *agenda){
    
    for(int i = 0; i < 20; i++){
        
        strcpy(agenda[i].text, "Compromisso de teste gerado aleatoriamente." ) ;
        agenda[i].dt.dia = rand() % 20 + 1;
        agenda[i].dt.mes = rand() % 12 + 1;
        agenda[i].dt.ano = rand() % 9 + 2016;
        agenda[i].hora.hr = rand() % 23;
        agenda[i].hora.min = rand() % 59;
        agenda[i].hora.sec = rand() % 59;
    }
}

void imprimir(compromissos *agenda)
{
    printf("========Lista de Compromissos========\n");

    for (int i = 0; i < 20; i++)
    {
        printf("Compromisso %d:\n", i + 1);
        printf("Data: %02d/%02d/%04d\n", agenda[i].dt.dia, agenda[i].dt.mes, agenda[i].dt.ano);
        printf("Horario: %02d:%02d:%02d\n", agenda[i].hora.hr, agenda[i].hora.min, agenda[i].hora.sec);
        printf("Texto: %s\n\n", agenda[i].text);
    }
}


int main()
{

    srand(time(NULL));

    compromissos vetor[MAX];

    inserir(vetor);
    imprimir(vetor);


    return 0;
}