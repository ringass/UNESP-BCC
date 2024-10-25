#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

typedef struct Paciente *no;

struct Paciente
{
    char nome[32];
    char estado_c[24];
    struct Paciente *pLink;
};


void AdicionarPaciente(no *fila, char* nome, char* estado){

    no New = (no)malloc(sizeof(struct Paciente));
    no atual, anterior;

    strcpy(New->nome, nome);
    strcpy(New->estado_c, estado);
    New->pLink = NULL;

    if(*fila == NULL){
        *fila = New;
        return;
    }

    atual = *fila;
    anterior = NULL;
     
     char *compare;

     strcpy(compare, estado);

     strlwr(compare); 

     while (atual != NULL && 
           ((strcmp(compare, "pessimo") < 0 && strcmp(atual->estado_c, "pessimo") != 0) ||
            (strcmp(compare, "ruim") < 0 && strcmp(atual->estado_c, "ruim") == 0))) {
        anterior = atual;
        atual = atual->pLink;
    }

    if(anterior == NULL){
        New->pLink = *fila;
        *fila = New;
    }else{
        New->pLink = atual;
        anterior->pLink = New;
    }

}


void MostraFila(no fila)
{

    no p = fila;

    printf("\nFILA\n");

    if(fila == NULL){
        printf("Nao ha pessoas na fila");
    }

    while (p != NULL)
    {
        printf("Paciente: %s  ||  Estado: %s", p->nome, p->estado_c);
        p = p->pLink;
    }
}

int AtenderPaciente(no *lista){

  system("cls");
  
  no q;

  if(!*lista){
    return 0;
  }
  
  printf("Paciente atendido: %s", (*lista)->nome);

  q = *lista;

  *lista = (*lista)->pLink;
  free(q);
  return 1;
}


int main()
{
    int e;
    no fila = NULL;

    char newNome[100], newEstado[10];

    do
    {
        printf("\nMENU\n");
        printf("[1] - Adicionar Paciente\n");
        printf("[2] - Atender o proximo paciente\n");
        printf("[3] - Exibir a fila\n");
        printf("[0] - Sair\n");
        printf("DIGITE: ");
        scanf("%d", &e);

        switch (e)
        {
        case 1:
        {
            int qt;

            printf("\nQuantos pacientes deseja inserir: ");
            scanf("%d", &qt);
            getchar();
            while (qt--)
            {

                printf("\nNome do paciente: ");
                gets(newNome);
                printf("Estado do paciente: ");
                gets(newEstado);
                fflush(stdin);

                AdicionarPaciente(&fila, newNome, newEstado);
            }

            system("cls");
            break;
        }
        case 2:
        {
            AtenderPaciente(&fila);
            break;
        }
        case 3:
        {
            MostraFila(fila);
            break;
        }
        case 0:
        {
            printf("Fechando Hospital!\n");
            break;
        }
        default:
        {
            printf("Valor invalido");
        }
        }

    } while (e != 0);

    while (fila != NULL)
    {
        AtenderPaciente(&fila);
    }

    return 0;
}