#include <stdio.h>
#include <stdlib.h>

typedef struct reg *no;

struct reg
{
    int info;
    struct reg *pLink;
};

void inclui_inicio(no *lista, int info)
{
    no p = (no)malloc(sizeof(struct reg));
    p->info = info;
    p->pLink = *lista;
    *lista = p;
}

void inclui_final(no *lista, int info)
{
    no p = (no)malloc(sizeof(struct reg));

    no q;

    p->info = info;
    p->pLink = NULL;

    if (*lista == NULL)
    {
        *lista = p;
    }
    else
    {
        q = *lista;

        while (q->pLink)
        {
            q = q->pLink;
        }

        q->pLink = p;
    }
}

int conta_no(no lista)
{
    int count = 0;

    no p = lista;

    while (p)
    {
        count++;
        p = p->pLink;
    }

    return count;
}

char *verifica(no lista, int n)
{
    no p = lista;

    while (p)
    {

        if (p->info == n)
        {
            return "encontrado";
            break;
        }

        p = p->pLink;
    }

    return "nao encontrado";
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

        inclui_final(&lista, x);

        printf("Deseja continuar inserindo a lista? ");
        scanf("%d", &continua);
    }

    int num;

    scanf("%d", &num);

    printf("numero de nos: %d\nvalor %d %s", conta_no(lista), num, verifica(lista, num));

    printf("\n\n");

    mostra_lista(lista);
}