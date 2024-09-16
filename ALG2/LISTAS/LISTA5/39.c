#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

void pares(int n, int i){
    
    if(n < 0){
        return;
    }
    
    if(i % 2 == 1 || i == 2){
        printf("%d ", i);
    }

    return pares(n-1, i+1);    
}


int main() {

    pares(5, 0);
    
    return 0;
}