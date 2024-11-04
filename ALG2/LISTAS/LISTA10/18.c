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

void exclui(no *lista, int x) {
    no q, r = NULL;

    if(!*lista){
        return;
    }

    q = *lista;
    int i = 0;

    if (x == 0) {  
        *lista = q->pLink;  
        free(q);
        return;
    }

    
    while(q != NULL && i < x){
        r = q;
        q = q->pLink;
        i++;
    }


    if(q == NULL){
        return;
    }

    r->pLink = q->pLink;


    free(q);
    return;

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

    exclui(&lista, 3);

    printf("\n");
    mostra_lista(lista);



}