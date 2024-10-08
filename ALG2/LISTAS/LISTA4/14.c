#include <stdio.h>

int main() {
    FILE *origem = fopen("matriz.txt", "r");
    int col, lin, nul;
    
    fscanf(origem, "%d %d %d", &lin, &col, &nul);
    
    int vet[lin][col];

    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            vet[i][j] = 1;
        }
    }
    
    int A, B;

    while(nul--){
        fscanf(origem,"%d %d", &A, &B);
        vet[A][B] = 0;
    }

    fclose(origem);

    FILE *saida = fopen("matriz saida.txt", "w");
    
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            fprintf(saida, "%d ", vet[i][j]);
        }
        fprintf(saida, "\n");
    }

    fclose(saida);
    return 0;
}