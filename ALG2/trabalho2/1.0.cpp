#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char nome[30];
    char tipo[20];
    char regiao[20];
    int geracao[20];
    int excluido;
    
} pokemon;

void cadastrar(FILE *arquivo) {
    pokemon p;
    printf("ID: ");
    scanf("%d", &p.id);
    printf("Nome: ");
    scanf("%s", p.nome);
    printf("Tipo: ");
    scanf("%s", p.tipo);
    printf("Geracao: ");
    scanf("%d", &p.geracao);
    printf("Regiao: ");
    scanf("%s", &p.regiao);
    
    p.excluido = 0;

    fseek(arquivo, 0, SEEK_END); 
    fwrite(&p, sizeof(pokemon), 1, arquivo); 
}

void listar(FILE *arquivo) {
    pokemon p;
    rewind(arquivo); 
    while (fread(&p, sizeof(pokemon), 1, arquivo)) {
        if (!p.excluido) { 
            printf("\n ID: %d\n Nome: %s\n Tipo: %s\n Geracao: %s\n Regiao: %s\n\n",
                   p.id, p.nome, p.tipo, p.geracao, p.regiao);
        }
    }
}

int main() {
    FILE *arquivo = fopen("pokemons.dat", "rb+");
    if (!arquivo) {
        arquivo = fopen("pokemons.dat", "wb+");
    }

    int opcao;
    do {
        printf("1. Cadastrar Pokemon\n2. Listar Pokemons\n0. Sair\nEscolha uma opcao: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                cadastrar(arquivo);
                break;
            case 2:
                listar(arquivo);
                break;
        }
    } while (opcao != 0);

    fclose(arquivo);
    return 0;
}
