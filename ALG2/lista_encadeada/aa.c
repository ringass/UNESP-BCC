#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct Paciente *no;

struct Paciente {
    char nome[32];
    char estado_c[24];
    int idade;
    struct Paciente *pLink;
};


int prioridadeEstado(const char *estado) {
    if (strcmp(estado, "pessimo") == 0) return 3;
    if (strcmp(estado, "ruim") == 0) return 2;
    if (strcmp(estado, "regular") == 0) return 1;
    return 0;
}


void AdicionarPaciente(no *fila, char *nome, char *estado, int idade) {
    no New = (no)malloc(sizeof(struct Paciente));
    strcpy(New->nome, nome);
    strcpy(New->estado_c, estado);
    New->idade = idade;
    New->pLink = NULL;

    if (*fila == NULL) {
        *fila = New;
        return;
    }

    no atual = *fila;
    no anterior = NULL;

    int prioridadeNovo = prioridadeEstado(estado);

    
    while (atual != NULL) {
        char copia[20];

        strcpy(copia, atual->estado_c);

        strlwr(copia);

        int prioridadeAtual = prioridadeEstado(copia);

        if (prioridadeAtual > prioridadeNovo ||
            (prioridadeAtual == prioridadeNovo && atual->idade >= idade)) {
            anterior = atual;
            atual = atual->pLink;
        } else {
            break;
        }
    }

    if (anterior == NULL) {
        New->pLink = *fila;
        *fila = New;
    } else {
        New->pLink = atual;
        anterior->pLink = New;
    }
}

void MostraFila(no fila) {
    no p = fila;

    printf("\nFILA\n");

    if (fila == NULL) {
        printf("Nao ha pessoas na fila\n");
        return;
    }

    while (p != NULL) {
        printf("Paciente: %s  ||  Estado: %s  ||  Idade: %d\n", 
               p->nome, strlwr(p->estado_c), p->idade);
        p = p->pLink;
    }
}


int AtenderPaciente(no *lista) {
    if (*lista == NULL) {
        printf("Nao ha pacientes para atender.\n");
        return 0;
    }

    no q = *lista;
    printf("\nPaciente atendido: %s\n", q->nome);

    *lista = q->pLink;
    free(q);
    return 1;
}

int main() {
    int e;
    no fila = NULL;

    char newNome[32], newEstado[24];
    int idade;

    do {
        printf("\nMENU\n");
        printf("[1] - Adicionar Paciente\n");
        printf("[2] - Atender o proximo paciente\n");
        printf("[3] - Exibir a fila\n");
        printf("[0] - Sair\n");
        printf("DIGITE: ");
        scanf("%d", &e);

        switch (e) {
            case 1: {
                int qt;
                printf("\nQuantos pacientes deseja inserir: ");
                scanf("%d", &qt);
                getchar(); 

                while (qt--) {
                    system("cls");
                    printf("\nNome do paciente: ");
                    fgets(newNome, sizeof(newNome), stdin);
                    newNome[strcspn(newNome, "\n")] = '\0'; 
                    
                    printf("Estado do paciente (regular, ruim, péssimo): ");
                    fgets(newEstado, sizeof(newEstado), stdin);
                    newEstado[strcspn(newEstado, "\n")] = '\0'; 

                    printf("Idade do paciente: ");
                    scanf("%d", &idade);
                    getchar(); 

                    AdicionarPaciente(&fila, newNome, newEstado, idade);
                }

                break;
            }
            case 2: {
                system("cls");
                AtenderPaciente(&fila);
                break;
            }
            case 3: {
                system("cls");
                MostraFila(fila);
                break;
            }
            case 0: {
                system("cls");
                printf("Fechando Hospital!\n");
                break;
            }
            default: {
                printf("Valor invalido\n");
            }
        }
    } while (e != 0);

    
    while (fila != NULL) {
        AtenderPaciente(&fila);
    }

    return 0;
}
