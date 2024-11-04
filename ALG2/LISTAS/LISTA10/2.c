#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct reg *no;

struct reg
{
    char nome[32];
    struct reg *pLink;
};

void insere(no *lista, char *nome)
{

    no p = (no)malloc(sizeof(struct reg));
    no q = *lista;

    strcpy(p->nome, nome);
    p->pLink = NULL;

    if (*lista == NULL || strcmp(nome, (*lista)->nome) < 0)
    {

        p->pLink = *lista;
        *lista = p;
    }
    else
    {
        while (q->pLink != NULL && strcmp(nome, q->pLink->nome) > 0)
        {
            q = q->pLink;
        }

        p->pLink = q->pLink;
        q->pLink = p;
    }
}

void imprime(no lista)
{

    while (lista != NULL)
    {
        printf("%s\n", lista->nome);
        lista = lista->pLink;
    }
}

int main()
{

    no lista = NULL;

    int qt = 30;

    char nome[32];

    while (qt--)
    {
        printf("NOME: ");
        gets(nome);

        insere(&lista, nome);
    }

    system("cls");
    imprime(lista);

    return 0;
}