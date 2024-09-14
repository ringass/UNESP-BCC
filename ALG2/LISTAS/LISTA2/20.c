#include <stdio.h>

typedef struct
{
  char nome[25];
  char rg[10];
  char sex;
  int idade;
  int nascimento[3];
  float salario;
} TipoReg;

typedef struct
{
  TipoReg funcionarios[100];
  int qt;
} TipoCadastro;

// Funcao do exercicio-------------------------------------------------------------------------------------------------------------------
void ListaAniversarioSexo(TipoCadastro *p)
{
  int m, a, d;
  char sex;
  scanf("%d %d %d", &d, &m, &a);
  scanf(" %c", &sex);

  for (int i = 0; i < p->qt; i++)
  {
    if(sex == p->funcionarios[i].sex && d == p->funcionarios[i].nascimento[0] && m == p->funcionarios[i].nascimento[1] && a == p->funcionarios[i].nascimento[2]){
      printf("Funcionario[%d]: %s", i, p->funcionarios[i].nome);
    }
  }
}
//------------------------------------------------------------------------------------------------------------------

void Lefuncionarios(TipoCadastro *empresa1)
{

  int i = 0;
  scanf("%d", &empresa1->qt);

  if (empresa1->qt > 100)
  {
    empresa1->qt = 100;
  }

  for (i = 0; i < empresa1->qt; i++)
  {
    printf("Funcionario %d:\n", i + 1);

    printf("Nome: ");
    scanf("%s", empresa1->funcionarios[i].nome);

    printf("RG: ");
    scanf("%s", empresa1->funcionarios[i].rg);

    printf("Sexo (M/F): ");
    scanf(" %c", &empresa1->funcionarios[i].sex);

    printf("Idade: ");
    scanf("%d", &empresa1->funcionarios[i].idade);

    printf("Nascimento (dia mes ano): ");
    scanf("%d %d %d", &empresa1->funcionarios[i].nascimento[0], &empresa1->funcionarios[i].nascimento[1], &empresa1->funcionarios[i].nascimento[2]);

    printf("Salario: ");
    scanf("%f", &empresa1->funcionarios[i].salario);
  }
}

int main()
{
  TipoCadastro empresa1;
  int i = 0;
  Lefuncionarios(&empresa1);

  system("cls");
  for (i = 0; i < empresa1.qt; i++)
  {
    printf("\nFuncionario %d:\n", i + 1);
    printf("Nome: %s\n", empresa1.funcionarios[i].nome);
    printf("RG: %s\n", empresa1.funcionarios[i].rg);
    printf("Sexo: %c\n", empresa1.funcionarios[i].sex);
    printf("Idade: %d\n", empresa1.funcionarios[i].idade);
    printf("Nascimento: %d/%d/%d\n", empresa1.funcionarios[i].nascimento[0], empresa1.funcionarios[i].nascimento[1], empresa1.funcionarios[i].nascimento[2]);
    printf("Salario: %.2f\n", empresa1.funcionarios[i].salario);
  }
  printf("\n\nFuncao procurar funcionario por sexo e aniversario:");
  ListaAniversarioSexo(&empresa1);

  return 0;
}