#include <stdio.h>
#include <stdlib.h>

#define MAX_INFO 100
#define MAX_DATA 20

typedef struct {
    int chave;
    char informacao[MAX_INFO];
    char data[MAX_DATA];
} Registro;

int main() {
    FILE *arquivoFonte = fopen("FONTE.dat", "rb");
    FILE *arquivoNovo = fopen("FONTENOVA.dat", "wb");

    if (arquivoFonte == NULL) {
        perror("Erro ao abrir o arquivo FONTE");
        return EXIT_FAILURE;
    }
    if (arquivoNovo == NULL) {
        perror("Erro ao abrir o arquivo FONTENOVA");
        fclose(arquivoFonte);
        return EXIT_FAILURE;
    }

    Registro registro;

    while (fread(&registro, sizeof(Registro), 1, arquivoFonte) == 1) {
        fwrite(&registro, sizeof(Registro), 1, arquivoNovo);
    }

    fclose(arquivoFonte);
    fclose(arquivoNovo);

  return 0;
}