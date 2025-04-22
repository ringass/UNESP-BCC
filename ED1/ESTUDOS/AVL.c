#include <stdio.h>
#include <stdlib.h>

typedef struct reg *No;

struct reg
{
    int info;
    int altura;
    struct reg *pEsq;
    struct reg *pDir;
};

typedef struct teg *no_fila;

struct teg
{
    No val;
    struct teg *plink;
};

typedef struct
{
    no_fila inicio;
    no_fila fim;
} Fila;

void inicializa_fila(Fila *f)
{
    f->inicio = f->fim = NULL;
    ;
}

void enqueue(Fila *f, No raiz)
{

    no_fila new = (no_fila)malloc(sizeof(struct teg));

    new->val = raiz;

    new->plink = NULL;

    if (f->fim == NULL)
    {
        f->fim = f->inicio = new;
        return;
    }

    f->fim->plink = new;
    f->fim = new;
}

No dequeue(Fila *f)
{

    if (f->fim == NULL)
    {
        return NULL;
    }

    no_fila temp;

    temp = f->inicio;
    No val = temp->val;

    f->inicio = temp->plink;

    if (f->inicio == NULL)
    {
        f->fim = NULL;
    }

    free(temp);

    return val;
}


int getAltura(No raiz)
{
    if (raiz == NULL)
    {
        return -1;
    }

    return raiz->altura;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

No criarNo(int valor)
{
    No novo = (No)malloc(sizeof(struct reg));
    novo->info = valor;
    novo->altura = 0;
    novo->pEsq = NULL;
    novo->pDir = NULL;
    return novo;
}

int calcAltura(No raiz)
{

    return max(getAltura(raiz->pEsq), getAltura(raiz->pDir)) + 1;
}

//rota para a direita
//nó selecionado vira filho da direita de seu nó esquerdo (newpivot) e recebe por fim o filho da direita do newpivot como seu novo filho esquerdo;

No rDir(No raiz)
{

    No newPivot = raiz->pEsq;
    No newEsq = newPivot->pDir;

    newPivot->pDir = raiz;
    raiz->pEsq = newEsq;

    raiz->altura = calcAltura(raiz);
    newPivot->altura = calcAltura(newPivot);

    return newPivot;
}

//rota para a esquerda
//nó selecionado vira filho da esquerda de seu nó direito (newpivot) e recebe por fim o filho esquerdo do newpivot como seu novo filho direito;
No rEsq(No raiz)
{

    No newPivot = raiz->pDir;
    No newDir = newPivot->pEsq;

    newPivot->pEsq = raiz;
    raiz->pDir = newDir;

    raiz->altura = calcAltura(raiz);
    newPivot->altura = calcAltura(newPivot);

    return newPivot;
}

int getBalanco(No raiz)
{

    if (raiz == NULL)
    {
        return 0;
    }

    return  getAltura(raiz->pDir) - getAltura(raiz->pEsq);
}

No balancear(No raiz, int balanco)
{

    if (balanco < -1) // desequilibrada para a esquerda
    {
        if (getBalanco(raiz->pEsq) <= 0) // caso o nó esteja balanceado ou desbalanceado para a esquerda
        {                                // caso de rotação simples à direita
            return rDir(raiz);
        }
        else
        { // rotação dupla direita
            raiz->pEsq = rEsq(raiz->pEsq);
            return rDir(raiz);
        }
    }
    else if (balanco > 1) // desequilibrada para a direita
    {
        if (getBalanco(raiz->pDir) >= 0) // caso o nó esteja balanceado ou desbalanceado para a direita
        {                                // rotação simples à esquerda
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

    raiz->altura = calcAltura(raiz);

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
// void mostra_nivel(No raiz, int *nivel)
// {
//     int i, nivel1;

//     for (i = 0; i <= (*nivel) * 2; i++)
//     {
//         printf("  ");
//     }
//     printf("%d\n", raiz->info);
//     nivel1 = (*nivel) + 1;
//     if (raiz)
//     {
//         if (raiz->pDir != NULL)
//         {
//             mostra_nivel(raiz->pDir, &nivel1);
//         }
//         if (raiz->pEsq != NULL)
//         {
//             mostra_nivel(raiz->pEsq, &nivel1);
//         }
//     }
// }

void liberarNo(No raiz)
{
    if (raiz != NULL)
    {
        liberarNo(raiz->pEsq);
        liberarNo(raiz->pDir);
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


void mostrar_nivel(No raiz)
{

    if (raiz == NULL)
    {
        return;
    }

    Fila f;
    inicializa_fila(&f);

    enqueue(&f, raiz);

    while (f.inicio != NULL)
    {

        int nivel = 0;

        no_fila temp = f.inicio;

        while (temp != NULL)
        {
            nivel++;
            temp = temp->plink;
        }

        for (int i = 0; i < nivel; i++)
        {

            No atual = dequeue(&f);

            printf("%d ", atual->info);

            if (atual->pEsq != NULL)
            {
                enqueue(&f, atual->pEsq);
            }

            if (atual->pDir != NULL)
            {
                enqueue(&f, atual->pDir);
            }
        }

        printf("\n");
    }
}

int excluirNode(No *raiz, int x)
{

    if (*raiz == NULL)
    {
        return 0;
    }

    if (x > (*raiz)->info)
    {
        return excluirNode(&(*raiz)->pDir, x);
    }
    else if (x < (*raiz)->info)
    {
        return excluirNode(&(*raiz)->pEsq, x);
    }
    else
    {
        No temp = *raiz;

        if ((*raiz)->pEsq == NULL && (*raiz)->pDir == NULL)
        {
            free(*raiz);
            *raiz = NULL;
        }
        else if ((*raiz)->pEsq == NULL)
        {
            *raiz = (*raiz)->pDir;
            free(temp);
        }
        else if ((*raiz)->pDir == NULL)
        {
            *raiz = (*raiz)->pEsq;
            free(temp);
        }
        else
        {
            No p = (*raiz)->pDir;
            No q = NULL;
            while (p->pEsq != NULL)
            {
                q = p;
                p = p->pEsq;
            }

            (*raiz)->info = p->info;

            if (q != NULL)
            {
                return excluirNode(&q->pEsq, p->info);
            }
            else
            {
                (*raiz)->pDir = p->pDir;
            }

            free(p);
        }
    }

    (*raiz)->altura = calcAltura(*raiz);

    int balanco = getBalanco(*raiz);

    (*raiz) = balancear(*raiz, balanco);

    return 1;
}

int main()
{
    No raiz = NULL;
    raiz = inserirAVL(raiz, 12);
    raiz = inserirAVL(raiz, 4);
    raiz = inserirAVL(raiz, 8);
    raiz = inserirAVL(raiz, 2);
    raiz = inserirAVL(raiz, 6);

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
    mostrar_nivel(raiz);

    printf("\nquantidade de niveis: %d", treeNiveis(raiz));

    excluirNode(&raiz, 4);

    printf("Percurso em-ordem apos remocao: ");
    emOrdem(raiz);
    printf("\n");



    // nivel = 0;
    // printf("Percurso por nivel apos remocao:\n");
    // mostra_nivel(raiz, &nivel);

    liberarNo(raiz);
    return 0;
}