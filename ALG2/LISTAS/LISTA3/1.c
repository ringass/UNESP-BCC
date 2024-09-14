#include <stdio.h>

int main() {
    FILE *file;
    int numbers[5];

    printf("Insira 5 números inteiros:\n");
    for(int i = 0; i < 5; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    file = fopen("dados.bin", "wb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para escrita!\n");
        return 1;
    }

    fwrite(numbers, sizeof(int), 5, file);

    fclose(file);

    printf("Números gravados dados.bin.\n");

    return 0;
}
