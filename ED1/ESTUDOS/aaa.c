// 	Árvore Binária de Busca (Ordenada)

#include <stdio.h>
#include <conio.h>
//#include <alloc.h>

typedef enum {False,True} boolean;

typedef struct no_arvore{
			int dado;
         struct no_arvore* esq;
         struct no_arvore* dir;
         } *def_arvore;


void mostra_arvore(def_arvore arvore, int *nivel)
{ int i,nivel1;

      for(i=0;i<=(*nivel)*2;i++)
         printf("  ");
      printf("%d\n",arvore->dado);
      nivel1=(*nivel)+1;
      if(arvore->dir!=NULL)
         mostra_arvore(arvore->dir,&nivel1);
      if(arvore->esq!=NULL)
         mostra_arvore(arvore->esq,&nivel1);
}

void mostra_em_ordem(def_arvore arvore)
{
    if (arvore != NULL)
    {
        mostra_em_ordem(arvore->esq);
        printf("%d  ",arvore->dado);
        mostra_em_ordem(arvore->dir);}
}

void insere_arvore(def_arvore *arvore, int valor)
{
	  def_arvore p;

     if(*arvore!=NULL)
     {
        if ((*arvore)->dado > valor)
            insere_arvore(&((*arvore)->esq),valor);
        else
           if ((*arvore)->dado < valor)
             insere_arvore(&((*arvore)->dir),valor);
        else
          printf("O numero ja existe\n");}
     else{
               p=(def_arvore)malloc(sizeof(struct no_arvore));
               p->dado = valor;
               p->esq = NULL;
               p->dir = NULL;
               *arvore=p;
     }
}

boolean busca_geral(def_arvore arvore, int valor)
{
     if (arvore==NULL)
        return False;
     return (arvore->dado == valor) || busca_geral(arvore->esq,valor)|| busca_geral(arvore->dir,valor);
}

boolean busca(def_arvore arvore, int valor)
{
     if (arvore==NULL)
      return False;
     if (arvore->dado == valor) return True;
     if (valor < arvore->dado)
     		return busca(arvore->esq,valor);
     if (valor > arvore->dado)
     		return busca(arvore->dir,valor);
}

void main(void)
{
	  def_arvore arvore;
	  int numero, nivel=0;
     char resp;

     arvore = NULL;
     printf("Insercao. Digite (-1) para concluir\n\n");
     do
     {
           printf("nro = ");
           scanf("%d",&numero);
           if(numero != -1)
             insere_arvore(&arvore,numero);
     }while (numero != -1);
     printf("\n\aA arvore binaria formada e: \n");
     mostra_arvore(arvore,&nivel);
     printf("\n\aA arvore binaria formada em_ordem: \n");
     mostra_em_ordem(arvore);
	  printf("Busca por um elemento\n");
     do{
           printf("\nNumero = ");
           scanf("%d",&numero);
           if(busca(arvore,numero))
              printf("Encontrou o no: %d \n",numero);
           else
             printf("NAO encontrou o no: %d \n",numero);
           printf("Continuar?(s/n) ");
           resp=getche();
     }while (resp !='n');
     printf("\n\n\aTecle concluir ...");
     getch();
    }