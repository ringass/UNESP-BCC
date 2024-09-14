#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

typedef struct {
    int d;
    int m;
    int a;
} dat;

typedef struct {
    float peso, altura;
    dat data;
    char olhos[20], sexo, nome[20];
} cadastros;

void cadastro(cadastros here[], int n) {
    FILE *arquivo = fopen("cadastro.dat", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo para escrita.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        fwrite(&here[i], sizeof(cadastros), 1, arquivo);
    }

    fclose(arquivo);
}

void receber(cadastros r[], int *n) {
    int i = 0;

    printf("Quantos cadastros? ");
    scanf("%d", n);
    getchar();

    if (*n > MAX) {
        printf("Número de cadastros excede o máximo permitido.\n");
        return;
    }

    while (i < *n) {
        printf("Funcionario %d\n", i + 1);

        printf("Nome: ");
        fgets(r[i].nome, sizeof(r[i].nome), stdin);
        r[i].nome[strcspn(r[i].nome, "\n")] = '\0';

        printf("Sexo (M/F): ");
        r[i].sexo = getchar();
        getchar();  

        printf("Cor dos olhos: ");
        fgets(r[i].olhos, sizeof(r[i].olhos), stdin);
        r[i].olhos[strcspn(r[i].olhos, "\n")] = '\0';

        printf("Altura: ");
        scanf("%f", &r[i].altura);

        printf("Peso: ");
        scanf("%f", &r[i].peso);

        printf("Data de nascimento (dd/mm/aaaa): ");
        scanf("%d/%d/%d", &r[i].data.d, &r[i].data.m, &r[i].data.a);
        getchar();

        i++;
    }

    cadastro(r, *n);
}

void separarM_F(cadastros here[], int n) {
    FILE *Masc = fopen("homens.dat", "wb");
    FILE *Fem = fopen("mulheres.dat", "wb");

    if (Masc == NULL || Fem == NULL) {
        printf("Erro ao abrir arquivos para escrita.\n");
        if (Masc != NULL) fclose(Masc);
        if (Fem != NULL) fclose(Fem);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (here[i].sexo == 'M') {
            fwrite(&here[i], sizeof(cadastros), 1, Masc);
        } else if (here[i].sexo == 'F') {
            fwrite(&here[i], sizeof(cadastros), 1, Fem);
        }
    }

    fclose(Masc);
    fclose(Fem);
}

int main() {
    cadastros cad[MAX];
    int n;
    receber(cad, &n);
    separarM_F(cad, n);
    return 0;
}
