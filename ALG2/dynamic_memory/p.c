#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>


int compare(const void* a, const void* b) {
   return (*(int*)a - *(int*)b);
}

int main() {

    int x;

    scanf("%d", &x);


    while(x--){
        int len;

        scanf("%d", &len);

        int vet[len], flag = 0, i = 0;

        for(i = 0; i < len; i++){
            scanf("%d", &vet[i]);
        }

        qsort(vet, len, sizeof(int), compare);

        for(i = 0; i < len; i++){
          if(i >= 1 && i <= len - 1){
                if(vet[i] != vet[i-1]){
                    flag = 1;
                    break;
                }
            }
        }


        if(flag || len == 1){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    
    }


    return 0;
}