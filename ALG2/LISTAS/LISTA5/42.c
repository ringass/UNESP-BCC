#include <stdio.h>

void imprime_combinacao(int *combinacao, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", combinacao[i]);
    }
    printf("\n");
}


void gera_combinacoes(int start, int *combinacao, int len, int pos) {
    
    if (pos == len) {
        imprime_combinacao(combinacao, len);
        return;
    }

    for (int i = start; i <= 60; i++) {
        combinacao[pos] = i;
        gera_combinacoes(i + 1, combinacao, len, pos + 1);
    }
}

int main() {
    int combinacao[6];
    gera_combinacoes(1, combinacao, 6, 0);

    return 0;
}
