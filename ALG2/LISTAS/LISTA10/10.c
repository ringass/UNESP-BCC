#include <stdio.h>
#include <stdlib.h>

typedef struct reg *no;

struct reg
{
    int info;
    struct reg *pLink;
};


void verifica(no lista, int n)
{
    no p = lista;
    int i = 0;

    while (p)
    {

        if (p->info == n)
        {
            printf("encontrado na posicao: %d", i);
            return;
        }

        i++;
        p = p->pLink;
    }

    printf("erro");
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

void inclui_ordenadamente(no *lista, int num){
    no p = (no)malloc(sizeof(struct reg));

    p->info = num;

    if(*lista == NULL || num <= (*lista)->info){
        p->pLink = *lista;
        *lista = p;
    }else{
        no q = *lista, r;

        while(q!= NULL && q->info < num){
            r = q;
            q = q->pLink;
        }

        p->pLink = q;
        r->pLink = p;
    }
}

int main()
{
    int continua = 1, x;

    no lista = NULL;

    while (continua)
    {

        scanf("%d", &x);

        inclui_ordenadamente(&lista, x);

        printf("Deseja continuar inserindo a lista? ");
        scanf("%d", &continua);
    }

    int n;

    scanf("%d", &n);

    verifica(lista, n);


}