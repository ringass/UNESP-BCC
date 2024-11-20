#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct reg *no;
typedef struct tag *op;


struct tag
{
  char nome[32];
  struct tag *prox;
};

struct reg
{
  char partido[32];
  op deputados;
  struct reg *pLink;
};

void criarPartido(no *lista, char *newPartido)
{
  no p = (no)malloc(sizeof(struct reg));
  strcpy(p->partido, newPartido);
  p->deputados = NULL;

  if (*lista == NULL)
  {
    p->pLink = p;
    *lista = p;
  }
  else
  {
    no q = *lista;
    while (q->pLink != *lista)
    {
      q = q->pLink;
    }
    q->pLink = p;
    p->pLink = *lista;
  }
}

void inserir_deputado(no *lista, char *newName, char *Partido)
{
  op p = (op)malloc(sizeof(struct tag));
  strcpy(p->nome, newName);
  p->prox = NULL;

  no q = *lista;

  do
  {
    if (strcmp(q->partido, Partido) == 0)
    {
      if (q->deputados == NULL)
      {
        q->deputados = p;
      }
      else
      {
        op x = q->deputados;
        while (x->prox != NULL)
        {
          x = x->prox;
        }
        x->prox = p;
      }
      return;
    }
    q = q->pLink;
  } while (q != *lista);

  printf("Partido %s não encontrado!\n", Partido);
}

void excluir_deputado(no *lista, char *nome, char *Partido)
{
  no q = *lista;

  do
  {
    if (strcmp(q->partido, Partido) == 0)
    {
      op atual = q->deputados, anterior = NULL;

      while (atual != NULL)
      {
        if (strcmp(atual->nome, nome) == 0)
        {
          if (anterior == NULL)
          {
            q->deputados = atual->prox;
          }
          else
          {
            anterior->prox = atual->prox;
          }
          free(atual);
          printf("Deputado %s removido do partido %s.\n", nome, Partido);
          return;
        }
        anterior = atual;
        atual = atual->prox;
      }
    }
    q = q->pLink;
  } while (q != *lista);

  printf("Deputado %s não encontrado no partido %s.\n", nome, Partido);
}

void alterar_partido(no *lista, char *nome, char *novoPartido, char *velhoPartido)
{
  excluir_deputado(lista, nome, velhoPartido);
  inserir_deputado(lista, nome, novoPartido);
}

void consultar_partido(no lista, char *Partido)
{
  no q = lista;

  do
  {
    if (strcmp(q->partido, Partido) == 0)
    {
      printf("Partido: %s\n", Partido);
      op x = q->deputados;
      while (x != NULL)
      {
        printf("  - %s\n", x->nome);
        x = x->prox;
      }
      return;
    }
    q = q->pLink;
  } while (q != lista);

  printf("Partido %s não encontrado.\n", Partido);
}

void consulta_geral(no lista)
{
  if (lista == NULL)
  {
    printf("Nenhum partido cadastrado.\n");
    return;
  }

  no q = lista;

  do
  {
    printf("Partido: %s\n", q->partido);
    op x = q->deputados;
    while (x != NULL)
    {
      printf("  - %s\n", x->nome);
      x = x->prox;
    }
    q = q->pLink;
  } while (q != lista);
}

int main()
{
  no lista = NULL;

  int continua = 1;

  while (continua)
  {
    printf("\nMenu\n");
    printf("[1] - Criar partido\n");
    printf("[2] - Inserir deputado\n");
    printf("[3] - Excluir deputado\n");
    printf("[4] - Alterar partido\n");
    printf("[5] - Consultar partido\n");
    printf("[6] - Consulta geral\n");
    printf("[0] - Sair\n");

    int opcao;

    printf("SELECIONE: ");

    scanf("%d", &opcao);


    switch (opcao)
    {
    case 1:
    {
      char nomePartido[32];
      printf("Digite o nome do partido: ");
      scanf(" %31[^\n]", nomePartido);
      criarPartido(&lista, nomePartido);
      system("cls");
      break;
    }
    case 2:
    {
      char nomeDeputado[32], nomePartido[32];
      printf("Digite o nome do deputado: ");
      scanf(" %31[^\n]", nomeDeputado);
      printf("Digite o nome do partido: ");
      scanf(" %31[^\n]", nomePartido);
      inserir_deputado(&lista, nomeDeputado, nomePartido);
      system("cls");
      break;
    }
    case 3:
    {
      char nomeDeputado[32], nomePartido[32];
      printf("Digite o nome do deputado: ");
      scanf(" %31[^\n]", nomeDeputado);
      printf("Digite o nome do partido: ");
      scanf(" %31[^\n]", nomePartido);
      excluir_deputado(&lista, nomeDeputado, nomePartido);
      system("cls");
      break;
    }
    case 4:
    {
      char nomeDeputado[32], novoPartido[32], velhoPartido[32];
      printf("Digite o nome do deputado: ");
      scanf(" %31[^\n]", nomeDeputado);
      printf("Digite o nome do novo partido: ");
      scanf(" %31[^\n]", novoPartido);
      printf("Digite o nome do partido antigo: ");
      scanf(" %31[^\n]", velhoPartido);
      alterar_partido(&lista, nomeDeputado, novoPartido, velhoPartido);
      system("cls");
      break;
    }
    case 5:
    {
      char nomePartido[32];
      printf("Digite o nome do partido: ");
      scanf(" %31[^\n]", nomePartido);
      system("cls");
      consultar_partido(lista, nomePartido);
      getch();
      system("cls");
      break;
    }
    case 6:
    {
      system("cls");
      consulta_geral(lista);
      getch();
      system("cls");
      break;
    }
    case 0:
    {
      continua = 0;
      break;
    }
    default:
    {
      printf("Opção inválida.\n");
      break;
    }
    }

    printf("\n");
  }
}
