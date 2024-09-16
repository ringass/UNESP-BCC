#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>


//A) para X(5,3) -> valor = 10, 15 chamadas;
//B) para X(2, 2) -> valor = 1, 1 chamada;
//C) para X(3, 5) -> é necessario que o N > M;

int X (int N, int M){
    if (N == M || M == 0)
        return 1;

    return X(N - 1,M) + X(N -1,M -1);
}

int main() {

    int z = X(3, 5);

    printf("%d", z);
    
    return 0;
}