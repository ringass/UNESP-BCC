#include <stdio.h>

int main() {
    FILE *file;

    file = fopen("dados.bin", "rb");

    if (file != NULL) {
        
        printf("existe\n");
        fclose(file); 
    } else {
        
        printf("não existe\n");
    }

    return 0;
}
