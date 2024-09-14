#include <stdio.h>
#define MAX 20

typedef struct {
    char nome[20];
    int idade;
    float grade;
} A;

int main() {
    A alunos[MAX];
    int n;

    scanf("%d", &n);

    FILE *file1 = fopen("turmaA.bin", "rb");
    FILE *file2 = fopen("turmaB.bin", "rb");
    FILE *file3 = fopen("turma_completa.bin", "wb");

    if (file1 == NULL) {
        printf("Erro ao abrir o arquivo turmaA.bin.\n");
        return 1;
    } 
    if (file2 == NULL) {
        printf("Erro ao abrir o arquivo turmaB.bin.\n");
        fclose(file1);
        return 1;
    }
    if (file3 == NULL) {
        printf("Erro ao abrir o arquivo turma_completa.bin.\n");
        fclose(file1);  
        fclose(file2);  
        return 1;
    }

    while (fread(&alunos, sizeof(A), MAX, file1) > 0) {
        for (int i = 0; i < MAX; i++) {
            if (feof(file1)) break;
            fwrite(&alunos[i], sizeof(A), 1, file3);
        }
    }
    fclose(file1);

    while (fread(&alunos, sizeof(A), MAX, file2) > 0) {
        for (int i = 0; i < MAX; i++) {
            if (feof(file2)) break;
            fwrite(&alunos[i], sizeof(A), 1, file3);
        }
    }
    fclose(file2);

    fclose(file3);

    printf("Dados combinados com sucesso em 'turma_completa.bin'.\n");

    return 0;
}
