#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int bin(char v[], int e, int d, char x) {
    if (e > d) {
        return -1; 
    }
    
    int m = (e + d) / 2; 
    if (v[m] == x) {
        return m+1; 
    } else if (v[m] < x) {
        return bin(v, m + 1, d, x);
    } else {
        return bin(v, e, m - 1, x); 
}
}


int main() {

    char v[15] = "aaaaaaaaaaaaap";

    printf("%d", bin(v, 0, 14, 'p'));


    return 0;
}