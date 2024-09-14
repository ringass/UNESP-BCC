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


//Funcao do exercicio-------------------------------------------------------------------------------------------------------------------
void Imposto(TipoCadastro *p) {
    for (int i = 0; i < p->qt; i++) {
        float imposto = 0.0;

        if (p->funcionarios[i].salario > 1000.00 && p->funcionarios[i].salario <= 2000.00) {
            imposto = p->funcionarios[i].salario * 0.10;
        } else if (p->funcionarios[i].salario > 2000.00 && p->funcionarios[i].salario <= 3500.00) {
            imposto = p->funcionarios[i].salario * 0.15;
        } else if (p->funcionarios[i].salario > 3500.00) {
            imposto = p->funcionarios[i].salario * 0.25;
        }

        printf("Funcionario: %s, Imposto Retido: %.2f\n", p->funcionarios[i].nome, imposto);
    }
}
//------------------------------------------------------------------------------------------------------------------
void Lefuncionarios(TipoCadastro *empresa1){

  int i = 0;
  scanf("%d", &empresa1->qt);

  if(empresa1->qt > 100){
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
  printf("\n\nFuncao exibir Imposto funcionario:");
  Imposto(&empresa1);
  return 0;
}