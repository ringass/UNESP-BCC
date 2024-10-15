#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);  

    int barras[1001] = {0};  
    for (int i = 0; i < N; i++) {
        int comprimento;
        scanf("%d", &comprimento);
        barras[comprimento]++;
    }

    int maiorAltura = 0, numTorres = 0;

    
    for (int i = 1; i <= 1000; i++) {
        if (barras[i] > 0) {
            numTorres++;  
            if (barras[i] > maiorAltura) {
                maiorAltura = barras[i]; 
            }
        }
    }

    
    printf("%d %d\n", maiorAltura, numTorres);

    return 0;
}
