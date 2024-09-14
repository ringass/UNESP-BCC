#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10
typedef struct
{
  char sexo, civil[15];
  int idade, dependentes, grau;
  float salario, patrimonio, cal;
} reg;

typedef struct{
  reg registros[MAX]; 
}regiao;

void ordenar(regiao *here, int n) {
  reg temp;
  for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (here->registros[j].idade > here->registros[j+1].idade) {
                temp = here->registros[j];
                here->registros[j] = here->registros[j+1];
                here->registros[j+1] = temp;
            }
        }
    }
}

void receber(regiao *here)
{
    int n, i = 1;

    printf("Quantos registros? ");
    scanf("%d", &n);
    getchar(); 
    if (n > MAX) {
        printf("Número de registros excede o máximo permitido.\n");
        return;
    }

    while (n--) {
        reg *r = &here->registros[i - 1]; 
        
        printf("Funcionario %d\n", i);
        
        printf("Sexo (M/F): ");
        r->sexo = getchar();
        getchar();

        printf("Estado civil: ");
        fgets(r->civil, sizeof(r->civil), stdin);
        r->civil[strcspn(r->civil, "\n")] = '\0'; 
        
        printf("Idade: ");
        scanf("%d", &r->idade);
        
        printf("Número de dependentes: ");
        scanf("%d", &r->dependentes);
        
        printf("Grau de escolaridade (0-10): ");
        scanf("%d", &r->grau);
        
        printf("Salário: ");
        scanf("%f", &r->salario);
        
        printf("Patrimônio: ");
        scanf("%f", &r->patrimonio);
        
        printf("Calculo adicional (float): ");
        scanf("%f", &r->cal);

        getchar(); 

        i++;
    }

    ordenar(&here, n);
}

void salvar(const char *nome, regiao *here, int n) {
    FILE *file = fopen(nome, "wb");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }
    fwrite(&n, sizeof(int), 1, file); 
    fwrite(here->registros, sizeof(reg), n, file); 
    fclose(file);
}

void transferirFinal(const char *arquivoFinal) {
    FILE *finalFile = fopen(arquivoFinal, "wb");
    if (finalFile == NULL) {
        perror("Erro ao abrir o arquivo final");
        exit(EXIT_FAILURE);
    }

    reg Registros[MAX * 3];
    int total = 0;

    for (int i = 0; i < 3; i++) {
        char nome[20];
        sprintf(nome, "regiao%d.dat", i + 1);
        FILE *tempFile = fopen(nome, "rb");
        if (tempFile == NULL) {
            perror("Erro");
            exit(EXIT_FAILURE);
        }

        int n;
        fread(&n, sizeof(int), 1, tempFile); 
        fread(&Registros[total], sizeof(reg), n, tempFile); 
        total += n;
        fclose(tempFile);
    }

    ordenar(Registros, total);

    fwrite(&total, sizeof(int), 1, finalFile); 
    fwrite(Registros, sizeof(reg), total, finalFile); 

    fclose(finalFile);
}

int main()
{
  regiao rr[3];
  int count[3];

  for (int i = 0; i < 3; i++)
  {
    printf("Digite o numero de registros na regiao %d: ", i+1);
    scanf("%d", &count[i]);

    receber(&rr[i]);
    char nome[10];
    sprintf(nome, "regiao%d.dat", i + 1);
    salvar(nome, &rr[i], count[i]);
  }
    transferirFinal("final.dat");

  return 0;
}