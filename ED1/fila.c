#include <stdio.h>
#include <stdlib.h>

typedef struct reg *No;

struct reg
{
    int info;
    struct reg *pLink;
};

typedef struct
{
    No inicio;
    No fim;
} Fila;

void inicializaFila(Fila *f)
{
    f->inicio = f->fim = NULL;
}

void enqueue(Fila *f, int valor)
{
    No novo = (No)malloc(sizeof(struct reg));
    novo->info = valor;
    novo->pLink = NULL;

    if (f->fim == NULL)
    {
        f->inicio = f->fim = novo;
    }
    else
    {
        f->fim->pLink = novo;
        f->fim = novo;
    }
}

int dequeue(Fila *f)
{
    if (f->inicio == NULL)
    {
        printf("Fila vazia!\n");
        return -1;
    }
    No temp = f->inicio;
    int valor = temp->info;
    f->inicio = temp->pLink;

    if (f->inicio == NULL)
    {
        f->fim = NULL;
    }

    free(temp);
    return valor;
}

int front(Fila *f)
{
    if (f->inicio == NULL)
    {
        printf("Fila vazia!\n");
        return -1;
    }
    return f->inicio->info;
}

int main()
{

    Fila f;
    inicializaFila(&f);

    enqueue(&f, 10);
    enqueue(&f, 20);
    enqueue(&f, 30);

    printf("Front: %d\n", front(&f));     
    printf("Dequeue: %d\n", dequeue(&f)); 
    printf("Front: %d\n", front(&f));     
}
