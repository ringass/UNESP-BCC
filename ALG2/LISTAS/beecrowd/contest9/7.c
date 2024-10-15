#include <stdio.h>
#include <stdlib.h>

// Estrutura para armazenar o valor e o índice original
typedef struct  {
    int index;
    int value;
}aa;

aa arr[100007];


int comp(const void *a, const void *b) {
    aa *aaA = (aa *)a;
    aa *aaB = (aa *)b;

    if (aaA->value < aaB->value)
        return -1;
    else if (aaA->value > aaB->value)
        return 1;
    else {
        
        return aaB->index - aaA->index;
    }
}

int main() {
    int n, i = 0;
    scanf("%d", &n);  

    for( i = 0; i < n; i++) {
        scanf("%d", &arr[i].value);  
        arr[i].index = i + 1;  
    }

    qsort(arr, n, sizeof(aa), comp);

    for(i = 0; i < n; i++) {
        printf("%d ", arr[i].index);
    }
    printf("\n");

    return 0;
}
