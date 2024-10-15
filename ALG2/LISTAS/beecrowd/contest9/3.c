#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int main() {

    int x;

    scanf("%d", &x);


    while(x--){
        int len;

        scanf("%d", &len);

        int vet[len], flag = 0;

        for(int i = 0; i < len; i++){
            scanf("%d", &vet[i]);
            
            if(i > 0 && i < len - 1){
                if(vet[i] != vet[i+1]){
                    flag = 1;
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