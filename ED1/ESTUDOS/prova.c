#include <stdio.h>
#include <stdlib.h>

typedef struct reg *arvore;

struct reg
{
    int info;
    struct reg *pEsq;
    struct reg *pDir;
};

typedef struct teg *no_fila;

struct teg
{
    arvore val;
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

void enqueue(Fila *f, arvore raiz)
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

arvore dequeue(Fila *f)
{

    if (f->fim == NULL)
    {
        return NULL;
    }

    no_fila temp;

    temp = f->inicio;
    arvore val = temp->val;

    f->inicio = temp->plink;

    if (f->inicio == NULL)
    {
        f->fim = NULL;
    }

    free(temp);

    return val;
}

arvore criar_bst(int x)
{

    arvore new = (arvore)malloc(sizeof(struct reg));

    new->info = x;
    new->pEsq = NULL;
    new->pDir = NULL;

    return new;
}

void inserir_bst(arvore *raiz, int val)
{

    if ((*raiz) == NULL)
    {

        (*raiz) = criar_bst(val);
        return;
    }

    if (val < (*raiz)->info)
    {
        inserir_bst(&(*raiz)->pEsq, val);
    }
    else if (val > (*raiz)->info)
    {
        inserir_bst(&(*raiz)->pDir, val);
    }
}

void mostrar_nivel(arvore raiz)
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

            arvore atual = dequeue(&f);

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

void mostrar_nivel2(arvore raiz)
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

        arvore atual = dequeue(&f);

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
}


typedef struct pp *no_pilha;

struct pp{
    int info;
    struct pp *plink;
};

typedef struct{
    no_pilha topo;
}Pilha;


void inicializa_pilha(Pilha *p){
    p->topo = NULL;
}

void push(Pilha *pil, int val){

    no_pilha new = (no_pilha)malloc(sizeof(struct pp));

    new->info = val;
    new->plink = pil->topo;
    pil->topo = new;
}

int pop(Pilha *pil){

    if(pil->topo == NULL){
        printf("vazio");
        return -1;
    }

    no_pilha temp = pil->topo;

    int val = temp->info;

    pil->topo = temp->plink;

    free(temp);
    return val;
}


void pre_ordem(arvore raiz){
    if(raiz != NULL){

        printf("%d ", raiz->info);
        pre_ordem(raiz->pEsq);
        pre_ordem(raiz->pDir);

    }
}


void em_ordem(arvore raiz){
    if(raiz != NULL){

        em_ordem(raiz->pEsq);
        printf("%d ", raiz->info);
        em_ordem(raiz->pDir);

    }
}

void pos_ordem(arvore raiz){
    if(raiz != NULL){

        pos_ordem(raiz->pEsq);
        pos_ordem(raiz->pDir);
        printf("%d ", raiz->info);

    }
}

int main()
{

    arvore raiz = NULL;

    inserir_bst(&raiz, 12);
    inserir_bst(&raiz, 4);
    inserir_bst(&raiz, 2);
    inserir_bst(&raiz, 8);
    inserir_bst(&raiz, 6);
    inserir_bst(&raiz, 16);

    // mostrar_nivel(raiz);
    // printf("\n");
    // mostrar_nivel2(raiz);

    printf("PRE ");
    pre_ordem(raiz);
    
    printf("\nEM ");
    em_ordem(raiz);
    
    printf("\nPOS ");
    pos_ordem(raiz);


    printf("\n");

    Pilha p;
    inicializa_pilha(&p);

    push(&p, 1);
    push(&p, 4);

    printf("%d\n", pop(&p));
    printf("%d", pop(&p));
    
}
