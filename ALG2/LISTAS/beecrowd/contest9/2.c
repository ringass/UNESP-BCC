#include <stdio.h>
#include <stdlib.h>

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

int main()
{
    int n, m;

    while (scanf("%d %d", &n, &m) != 0)
    {
        if (n == 0 && m == 0)
        {
            break;
        }

        int vet[m];
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &vet[i]);
        }

        sort(vet, m);

        int count = 0;
        for (int i = 0; i < m - 1; i++)
        {
            if (vet[i] == vet[i + 1])
            {
                count++;

                while (i < m - 1 && vet[i] == vet[i + 1])
                {
                    i++;
                }
            }
        }

        printf("%d\n", count);
    }

    return 0;
}
