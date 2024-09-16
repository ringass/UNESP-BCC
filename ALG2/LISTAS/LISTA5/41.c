#include <stdio.h>

void listar_subconjuntos(char conjunto[], char subconjunto[], int n, int indice, int inicio) {
    
    if (indice == 2) {
        printf("[%c, %c]\n", subconjunto[0], subconjunto[1]);
        return;
    }

   
    for (int i = inicio; i < n; i++) {
        
        subconjunto[indice] = conjunto[i];
        
        listar_subconjuntos(conjunto, subconjunto, n, indice + 1, i + 1);
    }
}

int main() {
    char conjunto[] = {'A', 'C', 'E', 'K'};
    int n = sizeof(conjunto) / sizeof(conjunto[0]);
    char subconjunto[2];  

    listar_subconjuntos(conjunto, subconjunto, n, 0, 0);

    return 0;
}
