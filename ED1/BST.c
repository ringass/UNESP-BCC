#include <stdio.h>
#include <stdlib.h>

typedef struct reg *No;

struct reg {
    int info;
    struct reg *pEsq;
    struct reg *pDir;
};

No criarNo(int valor) {
    No novo = (No)malloc(sizeof(struct reg));
    novo->info = valor;
    novo->pEsq = NULL;
    novo->pDir = NULL;
    return novo;
}

No inserirBST(No raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }
    if (valor < raiz->info) {
        raiz->pEsq = inserirBST(raiz->pEsq, valor);
    } else if (valor > raiz->info) {
        raiz->pDir = inserirBST(raiz->pDir, valor);
    }
    return raiz;
}

void emOrdem(No raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->pEsq);
        printf("%d ", raiz->info);
        emOrdem(raiz->pDir);
    }
}

void liberarArvore(No raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->pEsq);
        liberarArvore(raiz->pDir);
        free(raiz);
    }
}

void preOrdem(No raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->info);
        preOrdem(raiz->pEsq);
        preOrdem(raiz->pDir);
    }
}

void posOrdem(No raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->pEsq);
        posOrdem(raiz->pDir);
        printf("%d ", raiz->info);
    }
}

int main() {
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

    liberarArvore(raiz);
    return 0;
}