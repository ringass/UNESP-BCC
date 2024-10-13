#include <stdio.h>
#include <stdlib.h>

void merge(int *x, int *large, int large_size, int *small, int small_size) {
    int i = 0, j = 0, k = 0;

    while (i < large_size && j < small_size) 
    {
        if (large[i] <= small[j]) 
        {
            x[k++] = large[i++];
        } 
        else 
        {
            x[k++] = small[j++];
        }
    }

    while (i < large_size) 
    {
        x[k++] = large[i++];
    }

    while (j < small_size) 
    {
        x[k++] = small[j++];
    }
}

void insercaoIntercalada(int *x, int n) 
{
    if (n <= 1) 
    {
        return;
    }

    int ind = (n - 1) / 2;
    int *large = (int *)malloc((ind + 1) * sizeof(int));
    int *small = (int *)malloc((ind + 1) * sizeof(int));
    
    int large_idx = 0, small_idx = 0;
    for (int i = 0; i < n - 1; i += 2) 
    {
        if (x[i] > x[i + 1]) 
        {
            large[large_idx++] = x[i];
            small[small_idx++] = x[i + 1];
        } 
        else 
        {
            large[large_idx++] = x[i + 1];
            small[small_idx++] = x[i];
        }
    }

    if (n % 2 != 0) 
    {
        small[small_idx++] = x[n - 1];
    }

    insercaoIntercalada(large, large_idx);
    insercaoIntercalada(small, small_idx);

    merge(x, large, large_idx, small, small_idx);

    free(large);
    free(small);
}

void imprimeVet(int *vet, int n) 
{
    printf("Vet = {");
    for (int i = 0; i < n; i++) 
    {
        if (i == n - 1) 
        {
            printf("%d}", vet[i]);
        } 
        else 
        {
            printf("%d, ", vet[i]);
        }
    }
    printf("\n");
}

int main() 
{
    int n;
    printf("Insira o tamanho do vetor: ");
    do 
    {
        scanf("%d", &n);
    } while (n <= 0);

    int *vet = (int*)malloc(sizeof(int) * n);

    printf("Insira os elementos do vetor: ");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &vet[i]);
    }

    printf("\nVetor original:\n");
    imprimeVet(vet, n);

    insercaoIntercalada(vet, n);

    printf("\nVetor ordenado:\n");
    imprimeVet(vet, n);

    free(vet);
}
