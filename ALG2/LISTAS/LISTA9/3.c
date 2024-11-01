#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
    no q;
    
    strcpy(p->nome, nome);
    p->pLink = NULL;

    if (*lista == NULL)
    {
        *lista = p;
        p->pLink = *lista;
    }
    else
    {
        q = *lista;
        while (q->pLink != *lista)
        {
            q = q->pLink;
        }
        q->pLink = p;
        p->pLink = *lista;
    }
}

void seleciona(no *lista, int tipo_contagem)
{
    no atual = *lista;
    no anterior = NULL;
    int num;

    
    if (tipo_contagem == 1)
    {
        
        atual = *lista;
    }
    else if (tipo_contagem == 2)
    {
        
        int posicao = rand() % 15 + 1;
        for (int i = 0; i < posicao; i++)
        {
            atual = atual->pLink;
        }
        printf("Soldado sorteado: %s\n", atual->nome);
    }
    else if (tipo_contagem == 3)
    {
        getchar();
        char nome[32];
        printf("Digite o nome do soldado: ");
        gets(nome);

        while (stricmp(atual->nome, nome) != 0)
        {
            atual = atual->pLink;
            if (atual == *lista)
            {
                printf("Nao ha soldado com esse nome. Iniciando no primeiro\n");
                atual = *lista;
                break;
            }
        }
    }

    
    num = rand() % 15 + 1; 
    printf("Numero sorteado para contagem: %d\n", num);

    
    while (atual->pLink != atual)
    {
        
        for (int i = 0; i < num; i++)
        {
            anterior = atual;
            atual = atual->pLink;
        }

        
        printf("Soldado eliminado: %s\n", atual->nome);
        anterior->pLink = atual->pLink; 

        free(atual); 
        atual = anterior->pLink; 
    }

    printf("\nSoldado sobrevivente: %s\n", atual->nome);
}

int main()
{
    no lista = NULL;
    int continua = 1;
    char nome[32];

    while (continua)
    {
        printf("Digite o nome do soldado: ");
        scanf(" %31[^\n]", nome);
        insere(&lista, nome);

        printf("Deseja inserir mais um soldado (1 - Sim, 0 - Nao): ");
        scanf("%d", &continua);
    }

    int contagem;

    printf("Digite o número de contagem: ");
    scanf("%d", &contagem);

    printf("[1] - Comeca no primeiro\n");
    printf("[2] - Escolher aleatoriamente\n");
    printf("[3] - Escolher pelo nome\n");
    printf("[0] - Sair");

    if(contagem == 0){
        exit(1);
    }

    system("cls");
    seleciona(&lista, contagem);

    return 0;
}
