#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int bin(int v[], int e, int d, int x) {
    if (e > d) {
        return -1; 
    }
    
    int m = (e + d) / 2; 
    if (v[m] == x) {
        return m; 
    } else if (v[m] < x) {
        return bin(v, m + 1, d, x);
    } else {
        return bin(v, e, m - 1, x); 
}
}


int main() {

    int v[15];

    for(int i = 0; i < 15; i++){
      v[i] = i;
    }

    printf("%d", bin(v, 0, 15, 5));


    return 0;
}