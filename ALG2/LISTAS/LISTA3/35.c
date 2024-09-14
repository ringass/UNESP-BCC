#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100
#include <Windows.h>

struct dt {
    int dia;
    int mes;
};

typedef struct {
    char nome[25];
    struct dt niver;
    int tel;
} contatos;

void inserir(contatos *agenda, int *x) {
    int qt;

    printf("Digite a quantidade que deseja inserir: ");
    scanf("%d", &qt);
    getchar(); // Para capturar o '\n' deixado pelo scanf

    if (*x + qt > MAX) {
        printf("Limite máximo de contatos excedido.\n");
        return;
    }

    for (int i = *x; i < *x + qt; i++) {
        printf("Contato %d\n", i + 1 - *x);
        printf("Nome: ");
        fgets(agenda[i].nome, sizeof(agenda[i].nome), stdin);
        agenda[i].nome[strcspn(agenda[i].nome, "\n")] = '\0'; 

        printf("Telefone: ");
        scanf("%d", &agenda[i].tel);

        printf("Aniversario(dd/mm): ");
        scanf("%d/%d", &agenda[i].niver.dia, &agenda[i].niver.mes);
        getchar(); 
    }

    *x += qt;
}

void remover(contatos *agenda, int *qt) {
    char cp[25];

    printf("Digite o nome do contato a ser removido: ");
    fgets(cp, sizeof(cp), stdin);
    cp[strcspn(cp, "\n")] = '\0'; 

    for (int i = 0; i < *qt; i++) {
        if (strcmp(cp, agenda[i].nome) == 0) {
            for (int j = i; j < *qt - 1; j++) {
                agenda[j] = agenda[j + 1];
            }
            (*qt)--;
            printf("Contato removido com sucesso.\n");
            return;
        }
    }

    printf("Contato nao encontrado.\n");
}

void porNome(contatos *agenda, int qt) {
    char cp[25];
    int achou = 0;
    printf("Digite o nome do contato a ser pesquisado: ");
    fgets(cp, sizeof(cp), stdin);
    cp[strcspn(cp, "\n")] = '\0'; 

    for (int i = 0; i < qt; i++) {
        if (strcmp(cp, agenda[i].nome) == 0) {
            printf("Nome: %s \n", agenda[i].nome);
            printf("Telefone: %d \n", agenda[i].tel);
            printf("Aniversario(dd/mm): %d/%d \n", agenda[i].niver.dia, agenda[i].niver.mes);
            achou = 1;
        }
    }
    if(!achou){
    printf("Contato nao encontrado.\n");
    }else{
    sleep(1000);
    }
}

void Listartodos(contatos *agenda, int qt) {
  int achou = 0;
    for (int i = 0; i < qt; i++) {
        printf("Contato %d\n", i + 1);
        printf("Nome: %s \n", agenda[i].nome);
        printf("Telefone: %d \n", agenda[i].tel);
        printf("Aniversario(dd/mm): %d/%d \n", agenda[i].niver.dia, agenda[i].niver.mes);
        achou = 1;
    }

    if(!achou){
    printf("Nenhum contato.\n");
    }else{
    sleep(1000);
    }
}

void ListarInicial(contatos *agenda, int qt) {
    char a;
  int achou = 0;
    printf("Digite a letra inicial: ");
    scanf(" %c", &a); 
    getchar(); 

    for (int i = 0; i < qt; i++) {
        if (tolower(a) == tolower(agenda[i].nome[0])) { 
            printf("Contato %d\n", i + 1);
            printf("Nome: %s \n", agenda[i].nome);
            printf("Telefone: %d \n", agenda[i].tel);
            printf("Aniversario(dd/mm): %d/%d \n", agenda[i].niver.dia, agenda[i].niver.mes);
            achou = 1;
        }
    }
    if(!achou){
    printf("Nenhum contato com essa inicial.\n");
    }else{
    sleep(1000);
    }
}

void ListarNiver(contatos *agenda, int qt) {
    int d, m;
    int achou = 0;
    printf("Digite o mês e o dia do aniversário (mm/dd): ");
    scanf("%d/%d", &m, &d);
    getchar(); 

    for (int i = 0; i < qt; i++) {
        if (d == agenda[i].niver.dia && m == agenda[i].niver.mes) {
            printf("Contato %d\n", i + 1);
            printf("Nome: %s \n", agenda[i].nome);
            printf("Telefone: %d \n", agenda[i].tel);
            printf("Aniversario(dd/mm): %d/%d \n", agenda[i].niver.dia, agenda[i].niver.mes);
            achou = 1;
        }
    }

    if(!achou){
    printf("Nenhum contato faz aniversario nesse dia.\n");
    }else{
    sleep(1000);
    }
}

void verificarFile(contatos *r, int *p) {
    FILE *arquivo = fopen("agenda.dat", "rb");

    if (arquivo == NULL) {
        printf("arquivo nao existe ainda\n");
        *p = 0;
        return;
    }

    int count = 0;
    while (fread(&r[count], sizeof(contatos), 1, arquivo) == 1) {
        count++;
    }
    fclose(arquivo);
    *p = count;
}

void salvarArquivo(contatos *r, int p) {
    FILE *arquivo = fopen("agenda.dat", "wb");

    if (arquivo == NULL) {
        printf("erro ao abrir o arquivo\n");
        return;
    }

    fwrite(r, sizeof(contatos), p, arquivo);
    printf("sucesso ao salvar\n");
    fclose(arquivo);
}

int main() {
    int opcao, x = 0;
    contatos agenda[MAX];
    verificarFile(agenda, &x);

    do {
        printf("\nMenu:\n");
        printf("1 - Inserir Contato\n");
        printf("2 - Remover Contato\n");
        printf("3 - Pesquisar por Nome\n");
        printf("4 - Listar todos\n");
        printf("5 - Listar com filtro da inicial\n");
        printf("6 - Listar os aniversariantes\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); 

        system("cls"); 

        switch (opcao) {
            case 1:
                inserir(agenda, &x);
                break;
            case 2:
                remover(agenda, &x);
                break;
            case 3:
                porNome(agenda, x);
                break;
            case 4:
                Listartodos(agenda, x);
                break;
            case 5:
                ListarInicial(agenda, x);
                break;
            case 6:
                ListarNiver(agenda, x);
                break;
            case 0:
                printf("Saindo...\n");
                salvarArquivo(agenda, x);
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}
