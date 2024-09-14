// Implemente um controle simples de mercadorias em uma despensa doméstica. Sobre cada

// produto podem ser armazenado um código numérico, descrição e quantidade atual. O pro-
// grama deve ter opções para entrada e retirada de produtos, bem como um relatório geral e

// um de produtos não disponíveis. Armazene os dados em arquivo binário.

#include <stdio.h>
#define MAX 20
typedef struct
{
  char nome[20], desc[200];
  int codigo, qt_atual;
} aaaaaa;

void iserir()
{
  aaaaaa r[MAX];
  FILE *arquivo = fopen("estoque.dat", "ab");

  if (arquivo == NULL)
  {
    printf("erro");
    return 0;
  }

  printf("Digite o numero de produtos que deseja inserir");
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
  {
    printf("Produto %d\n", i + 1);

    printf("Nome: ");
    fgets(r[i].nome, sizeof(r[i].nome), stdin);
    r[i].nome[strcspn(r[i].nome, "\n")] = '\0';

    printf("Descricao: ");
    fgets(r[i].desc, sizeof(r[i].desc), stdin);
    r[i].desc[strcspn(r[i].desc, "\n")] = '\0';

    printf("Codigo: ");
    scanf("%d", &r[i].codigo);

    printf("Quantidade atual: ");
    scanf("%f", &r[i].qt_atual);

    getchar();

    fwrite(&r[i], sizeof(aaaaaa), 1, arquivo);
  }

  fclose(arquivo);
  printf("Produto inserido com sucesso.\n");
};

void remover()
{
  FILE *arquivo = fopen("estoque.dat", "rb");
  FILE *tempArquivo = fopen("temp.dat", "wb");
  if (arquivo == NULL || tempArquivo == NULL)
  {
    printf("Erro ao abrir os arquivos.\n");
    return;
  }

  int codigo;
  printf("Digite o codigo do produto a ser removido: ");
  scanf("%d", &codigo);

  aaaaaa p;
  int achou = 0;

  while (fread(&p, sizeof(aaaaaa), 1, arquivo) == 1)
  {
    if (p.codigo == codigo)
    {
      printf("Produto encontrado: %s\n", p.nome);
      printf("Digite a quantidade a ser retirada: ");
      int qt;
      scanf("%d", &qt);

      if (qt <= p.qt_atual)
      {
        p.qt_atual -= qt;
        if (p.qt_atual > 0)
        {
          fwrite(&p, sizeof(aaaaaa), 1, tempArquivo);
        }
      }
      else
      {
        printf("Quantidade maior do que a disponível.\n");
      }
      achou = 1;
    }
    else
    {
      fwrite(&p, sizeof(aaaaaa), 1, tempArquivo);
    }
  }

  fclose(arquivo);
  fclose(tempArquivo);
  remove("estoque.dat");
  rename("temp.dat", "estoque.dat");

  if (achou)
  {
    printf("Produto atualizado com sucesso.\n");
  }
  else
  {
    printf("Produto não encontrado.\n");
  }
}


void relatar()
{
    FILE *arquivo = fopen("estoque.dat", "rb");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    aaaaaa p;
    printf("Relatório de Produtos:\n");

    while (fread(&p, sizeof(aaaaaa), 1, arquivo) == 1)
    {
        printf("Nome: %s, Código: %d, Quantidade: %d\n", p.nome, p.codigo, p.qt_atual);
    }

    fclose(arquivo);
}

void relatarNao()
{
    FILE *arquivo = fopen("estoque.dat", "rb");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    aaaaaa p;
    printf("Relatório de Produtos:\n");

    while (fread(&p, sizeof(aaaaaa), 1, arquivo) == 1)
    {
      if(p.qt_atual == 0){
        printf("Nome: %s, Código: %d, Quantidade: %d\n", p.nome, p.codigo, p.qt_atual);
      }
    }
    fclose(arquivo);
}

int main()
{

  int opcao;

    do
    {
        printf("\nMenu:\n");
        printf("1 - Inserir Produto\n");
        printf("2 - Remover Produto\n");
        printf("3 - Relatar Produtos\n");
        printf("4 - Relatar Produtos Não Disponíveis\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); 

        switch (opcao)
        {
        case 1:
            inserir();
            break;
        case 2:
            remover();
            break;
        case 3:
            relatar();
            break;
        case 4:
            relatarNao();
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
            break;
        }
    } while (opcao != 0);

    return 0;
}
