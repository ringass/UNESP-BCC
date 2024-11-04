#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct reg *no;

struct reg {
    int info;
    struct reg *pLink;
};

void inclui_inicio(no *lista, int info){
    no p = (no) malloc(sizeof(struct reg));

    p->info = info;

    p->pLink = *lista;

    *lista = p;
}

void inclui_depois(no *lista, int info, int x) {
    no p = (no)malloc(sizeof(struct reg));
    p->info = info;
    p->pLink = NULL;

    no q = *lista;
    int i = 0;

    
    if (*lista == NULL || x == 0) {
        p->pLink = *lista;
        *lista = p;
        return;
    }

    
    while (q != NULL && i < x - 1) {
        q = q->pLink;
        i++;
    }

    
    if (q != NULL) {
        p->pLink = q->pLink;
        q->pLink = p;
    }
}

void mostra_lista(no lista)
{
    no p = lista;
    printf("\nElementos da lista: ");
    while (p)
    {
        printf("%d ", p->info);
        p = p->pLink;
    }
}

int main()
{

    int continua = 1, x;

    no lista = NULL;

    while (continua)
    {

        scanf("%d", &x);

        inclui_inicio(&lista, x);

        printf("Deseja continuar inserindo a lista? ");
        scanf("%d", &continua);
    }

    
    mostra_lista(lista);

    printf("\n");

    inclui_depois(&lista, 50, 4);

    printf("\n");
    mostra_lista(lista);



}