#include <stdio.h>
#include <stdlib.h>

typedef struct reg *No;

struct reg
{
    int info;
    struct reg *pEsq;
    struct reg *pDir;
};

No criarNo(int valor)
{
    No novo = (No)malloc(sizeof(struct reg));
    novo->info = valor;
    novo->pEsq = NULL;
    novo->pDir = NULL;
    return novo;
}

No inserirBST(No raiz, int valor)
{
    if (raiz == NULL)
    {
        return criarNo(valor);
    }
    if (valor < raiz->info)
    {
        raiz->pEsq = inserirBST(raiz->pEsq, valor);
    }
    else if (valor > raiz->info)
    {
        raiz->pDir = inserirBST(raiz->pDir, valor);
    }
    return raiz;
}

void emOrdem(No raiz)
{
    if (raiz != NULL)
    {
        emOrdem(raiz->pEsq);
        printf("%d ", raiz->info);
        emOrdem(raiz->pDir);
    }
}

//versao roberta -> sem fila
void mostra_nivel(No raiz, int *nivel)
{
    int i, nivel1;

    for (i = 0; i <= (*nivel)*2; i++)
    {
        printf("  ");
    }
    printf("%d\n", raiz->info);
    nivel1 = (*nivel) + 1;
    if (raiz)
    {
        if (raiz->pDir != NULL)
        {
            mostra_nivel(raiz->pDir, &nivel1);
        }
        if (raiz->pEsq != NULL)
        {
            mostra_nivel(raiz->pEsq, &nivel1);
        }
    }
}

// com fila -> fazer em c

// void mostrar_bynivel(arvore raiz){
//     if(raiz == NULL){
//         return;
//     }

//     queue<arvore> fila;
//     fila.push(raiz);

//     while(!fila.empty()){
//         arvore atual = fila.front();
//         fila.pop();

//         cout << atual << "\n";

//         if(raiz->pDir != NULL){
//             fila.push(raiz->pDir);
//         }

//         if(raiz->pEsq != NULL){
//             fila.push(raiz->pEsq);
//         }


//     }

// }

void liberarArvore(No raiz)
{
    if (raiz != NULL)
    {
        liberarArvore(raiz->pEsq);
        liberarArvore(raiz->pDir);
        free(raiz);
    }
}

void preOrdem(No raiz)
{
    if (raiz != NULL)
    {
        printf("%d ", raiz->info);
        preOrdem(raiz->pEsq);
        preOrdem(raiz->pDir);
    }
}

void posOrdem(No raiz)
{
    if (raiz != NULL)
    {
        posOrdem(raiz->pEsq);
        posOrdem(raiz->pDir);
        printf("%d ", raiz->info);
    }
}

int main()
{
    No raiz = NULL;
    raiz = inserirBST(raiz, 50);
    raiz = inserirBST(raiz, 30);
    raiz = inserirBST(raiz, 70);
    raiz = inserirBST(raiz, 20);
    raiz = inserirBST(raiz, 40);

    printf("Percurso em-ordem: ");
    emOrdem(raiz);
    printf("\n");
    printf("Percurso pos-ordem: ");
    posOrdem(raiz);
    printf("\n");
    printf("Percurso pre-ordem: ");
    preOrdem(raiz);

    int nivel = 0;
    printf("\n\nPercurso por nivel:\n");
    mostra_nivel(raiz, &nivel);

    liberarArvore(raiz);
    return 0;
}