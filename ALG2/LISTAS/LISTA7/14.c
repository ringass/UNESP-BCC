#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

void Countsort(int *v, int n, int *s){
    int count[n];

    for(int i = 0; i < n ; i++){
        count[i] = 0;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(v[j] < v[i]){
                count[i]++;
            }
        }
        s[count[i]] = v[i];
    }
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[10] = {5, 1, 4, 2, 8, 3, 7, 6, 9, 18};
    int n = 10;
    int arrS[10];

    print(arr, n);

    Countsort(arr, n, arrS);

    print(arrS, n);

    return 0;
}
