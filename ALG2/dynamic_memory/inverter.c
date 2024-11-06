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

void inclui_ordenadamente(no *lista, int num){
    no p = (no)malloc(sizeof(struct reg));

    p->info = num;

    if(*lista == NULL || num <= (*lista)->info){
        p->pLink = *lista;
        *lista = p;
    }else{
        no q = *lista, r;

        while(q != NULL && q->info < num){
            r = q;
            q = q->pLink;
        }

        p->pLink = q;
        r->pLink = p;
    }
}

int excluir_elemento(no *lista, int num){

    if(*lista == NULL || num < (*lista)->info){
        return 0;

    }else if(num == (*lista)->info){

        no q = *lista;
        *lista = (*lista)->pLink;
        free(q);

        return 1;

    }else{

        no q = *lista;
        no r = *lista;

        while (q->pLink != NULL && q->info < num)
        {
            r = q;
            q = q->pLink; 
        }


        if(q->pLink == NULL || q->info != num){
            return 0;
        }

        r->pLink = q->pLink;
        free(q);
        return 1;
    }
}

void inverter (no *lista) {
  no p, q, r;
  if (*lista == NULL || (*lista)->pLink==NULL)
    return;

  p = *lista;
  q = (*lista)->pLink;
  p->pLink = NULL;
  
  while (q != NULL){
      r = q;
      q = q->pLink;
      r->pLink = p;
      p = r;
  }

  *lista = r;  
}

void copiar (no *lista, no *copy){

    no p = *lista;

    *copy = NULL;

    if(*lista == NULL){
        return;
    }

    while(p != NULL){
        inclui_final(copy, p->info);
        p = p->pLink;
    }
}


int main()
{
    int continua = 1, x;

    no lista = NULL;
    no copy = NULL;
    no lista2 = NULL;

    while (continua)
    {

        scanf("%d", &x);

        inclui_ordenadamente(&lista, x);

        printf("Deseja continuar inserindo a lista? ");
        scanf("%d", &continua);
    }

    
    int num;

    scanf("%d", &num);

    printf("numero de nos: %d\nvalor %d %s", conta_no(lista), num, verifica(lista, num));

    printf("\n\n");

    mostra_lista(lista);

    printf("\ninvertida");

    inverter(&lista);
    mostra_lista(lista);

    printf("\n\ncopy:");

    copiar(&lista, &copy);
    mostra_lista(copy);

    printf("\ninvertendo a copia:");
    inverter(&copy);
    mostra_lista(copy);
}