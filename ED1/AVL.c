#include <stdio.h>
#include <stdlib.h>

typedef struct reg *No;

struct reg
{
    int info;
    int nivel;
    struct reg *pEsq;
    struct reg *pDir;
};

int getNivel(No raiz)
{
    if (raiz == NULL)
    {
        return -1;
    }

    return raiz->nivel;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

No criarNo(int valor)
{
    No novo = (No)malloc(sizeof(struct reg));
    novo->info = valor;
    novo->nivel = 0;
    novo->pEsq = NULL;
    novo->pDir = NULL;
    return novo;
}

int calcNivel(No raiz)
{

    return max(getNivel(raiz->pEsq), getNivel(raiz->pDir)) + 1;
}

No rDir(No raiz)
{

    No newPivot = raiz->pEsq;
    No newEsq = newPivot->pDir;

    newPivot->pDir = raiz;
    raiz->pEsq = newEsq;

    raiz->nivel = calcNivel(raiz);
    newPivot->nivel = calcNivel(newPivot);

    return newPivot;
}

No rEsq(No raiz)
{

    No newPivot = raiz->pDir;
    No newDir = newPivot->pEsq;

    newPivot->pEsq = raiz;
    raiz->pDir = newDir;

    raiz->nivel = calcNivel(raiz);
    newPivot->nivel = calcNivel(newPivot);

    return newPivot;
}

int getBalanco(No raiz)
{

    //

    if (raiz == NULL)
    {
        return 0;
    }

    return getNivel(raiz->pEsq) - getNivel(raiz->pDir);
}

No balancear(No raiz, int balanco)
{

    if (balanco > 1) // desequilibrada para a esquerda
    {
        if (getBalanco(raiz->pEsq) >= 0) // caso o no esteja balanceado ou desbalanceado para a esquerda
        { // caso de rotação simples à direita
            return rDir(raiz);
        }
        else
        { // rotação dupla direita
            raiz->pEsq = rEsq(raiz->pEsq);
            return rDir(raiz);
        }
    }
    else if (balanco < -1) // desequilibrada para a direita
    {
        if (getBalanco(raiz->pDir) <= 0) // caso o no esteja balanceado ou desbalanceado para a direita
        { // rotação simples à esquerda
            return rEsq(raiz);
        }
        else // rotação dupla esquerda
        {
            raiz->pDir = rDir(raiz->pDir);
            return rEsq(raiz);
        }
    }

    return raiz;
}

No inserirAVL(No raiz, int valor)
{
    if (raiz == NULL)
    {
        return criarNo(valor);
    }
    if (valor < raiz->info)
    {
        raiz->pEsq = inserirAVL(raiz->pEsq, valor);
    }
    else if (valor > raiz->info)
    {
        raiz->pDir = inserirAVL(raiz->pDir, valor);
    }

    raiz->nivel = calcNivel(raiz);

    int balanco = getBalanco(raiz); // verifica o balanceamento

    return balancear(raiz, balanco);
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

// versao roberta -> sem fila
void mostra_nivel(No raiz, int *nivel)
{
    int i, nivel1;

    for (i = 0; i <= (*nivel) * 2; i++)
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

int treeNiveis(No node)
{
    if (node == NULL)
        return 0;
    else
        return 1 + (treeNiveis(node->pEsq) + treeNiveis(node->pDir));
}

int main()
{
    No raiz = NULL;
    raiz = inserirAVL(raiz, 1);
    raiz = inserirAVL(raiz, 2);
    raiz = inserirAVL(raiz, 3);
    raiz = inserirAVL(raiz, 4);
    raiz = inserirAVL(raiz, 5);

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

    printf("\nquantidade de niveis: %d", treeNiveis(raiz));

    liberarArvore(raiz);
    return 0;
}