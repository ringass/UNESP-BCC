#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

void sort(int v[], int len)
{
    int flag = 1;
    while (flag != 0)
    {
        flag = 0;
        for (int i = 0; i < len - 1; i++)
        {
            if (v[i] > v[i + 1])
            {
                int aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                flag = 1;
            }
        }
    }
}


int main() {

    int x;

    while(scanf("%d", &x) != EOF){

        int *vet = (int*)malloc(x * sizeof(int));


        for(int i = 0; i < x; i++){
            scanf("%d", &vet[i]);
        }

        sort(vet, x);

        for(int i = 0; i < x; i++){
            char s[5];
            
            sprintf(s, "%d", vet[i]);

            int p = 4-strlen(s);

            for(int j = 0; j < p; j++){
                printf("0");
            }

            printf("%s\n", s);

        }
        
        free(vet);
    }


    return 0;
}