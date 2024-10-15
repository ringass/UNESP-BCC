#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    int tam; 
} presentes;


int compare(const void *a, const void *b)
{
    presentes *presenteA = (presentes *)a;
    presentes *presenteB = (presentes *)b;

    
    return presenteB->tam - presenteA->tam;
}

int main()
{
    int n;
    scanf("%d", &n); 

    while (n--)
    {
        int numPresentes, possiveis, altura, largura, comprimento;
        scanf("%d %d", &numPresentes, &possiveis); 

        presentes gift[numPresentes];

        for (int i = 0; i < numPresentes; i++)
        {
            scanf("%d %d %d %d", &gift[i].id, &altura, &largura, &comprimento);
            gift[i].tam = altura * largura * comprimento; 
        }

        
        qsort(gift, numPresentes, sizeof(presentes), compare);

        
        for (int i = 0; i < possiveis; i++)
        {
            printf("%d%s", gift[i].id, (i != possiveis - 1) ? " " : "\n");
        }
    }

    return 0;
}
