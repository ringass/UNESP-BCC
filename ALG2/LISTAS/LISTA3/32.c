#include <stdio.h>
#include <string.h>
#define MAX 150

typedef struct {
    char curso[25], nome[20];
    int matricula;
} alunos;

void pesquisas() {
    alunos vet[MAX];
    int i = 0, escolha;
    char pesqNome[20];
    int pesqMatricula;

    FILE* arquivo = fopen("alunos.dat", "rb");
    if (arquivo == NULL) {
        printf("Nao foi possivel abrir o arquivo\n");
        return;
    }

    while (fread(&vet[i], sizeof(alunos), 1, arquivo) == 1) {
        i++;
    }
    fclose(arquivo);

    do {
        printf("\nPESQUISAR\n1 - POR MATRÍCULA\n2 - POR NOME\n0 - VOLTAR AO MENU PRINCIPAL\n");
        scanf("%d", &escolha);

        if (escolha == 1) {
            do {
                printf("Digite o RA (ou número negativo para voltar): ");
                scanf("%d", &pesqMatricula);

                if (pesqMatricula < 0) break;

                int encontrado = 0;
                for (int j = 0; j < i; j++) {
                    if (pesqMatricula == vet[j].matricula) {
                        printf("Nome: %s, Curso: %s, RA: %d\n", vet[j].nome, vet[j].curso, vet[j].matricula);
                        encontrado = 1;
                        break;
                    }
                }

                if (!encontrado) {
                    printf("Aluno com matrícula %d não encontrado.\n", pesqMatricula);
                }
            } while (pesqMatricula >= 0);

        } else if (escolha == 2) {
            do {
                printf("Digite o nome (ou 'FIM' para voltar): ");
                scanf("%s", pesqNome);

                if (strcmp(pesqNome, "FIM") == 0) break;

                int encontrado = 0;
                for (int j = 0; j < i; j++) {
                    if (strcmp(pesqNome, vet[j].nome) == 0) {
                        printf("Nome: %s, Curso: %s, RA: %d\n", vet[j].nome, vet[j].curso, vet[j].matricula);
                        encontrado = 1;
                        break;
                    }
                }

                if (!encontrado) {
                    printf("Aluno com nome %s não encontrado.\n", pesqNome);
                }
            } while (strcmp(pesqNome, "FIM") != 0);

        } else if (escolha != 0) {
            printf("Opção inválida. Tente novamente.\n");
        }
    } while (escolha != 0);
}

int main() {
    int x;

    do {
        printf("\nMENU PRINCIPAL\n");
        printf("1 - Pesquisar Aluno\n");
        printf("0 - Fim\n");
        scanf("%d", &x);

        switch (x) {
        case 1:
            pesquisas();
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
            break;
        }
    } while (x != 0);

    return 0;
}
