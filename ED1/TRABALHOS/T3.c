#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ull unsigned long long

typedef struct reg *no;

struct reg
{
    ull val;
    struct reg *pLink;
};

typedef struct
{
    no inicio;
    no fim;
} fila;

void enqueue(fila *fila, ull valor)
{
    no novo = (no)malloc(sizeof(struct reg));
    novo->val = valor;
    novo->pLink = NULL;

    if (fila->inicio == NULL)
    {
        fila->inicio = fila->fim = novo;
    }
    else
    {
        fila->fim->pLink = novo;
        fila->fim = novo;
    }
}

ull dequeue(fila *fila)
{
    if (fila->inicio == NULL)
    {
        return -1;
    }

    no temp = fila->inicio;
    ull valor = temp->val;
    fila->inicio = temp->pLink;

    if (fila->inicio == NULL)
    {
        fila->fim = NULL;
    }

    free(temp);
    return valor;
}

ull front(fila *fila)
{
    if (fila->inicio == NULL)
    {
        exit(1);
    }

    return fila->inicio->val;
}

void inicia(fila *fila)
{
    fila->inicio = NULL;
    fila->fim = NULL;
}

void solve(int n, int m)
{
    int ans = 0, i = 0;
    ull val, soma = 0, media = 0;
    fila FILA;
    inicia(&FILA);

    while (i < 30)
    {
        scanf("%llu", &val);
        enqueue(&FILA, val);
        soma += val;
        i++;
    }

    while (n < m)
    {
        media = (ull)ceil((double)soma / 30.0);

        if (media == 0)
            break;

        n += media;

        soma -= front(&FILA);
        dequeue(&FILA);

        enqueue(&FILA, media);
        soma += media;

        ans++;
    }

    printf("%d\n", ans);
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    solve(n, m);
    return 0;
}
