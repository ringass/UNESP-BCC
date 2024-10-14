#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

char *ehprimo(int num, int *d)
{

    if (num < 2)
    {
        return "nao eh primo";
    }

    for (int i = 2; i * i <= num; i++)
    {
        (*d)++;
        if (num % i == 0)
        {
            return "nao eh primo";
        }
    }

    return "eh primo";
};

int main()
{

    int n;
    int d = 0;

    scanf("%d", &n);

    printf("%s, numero de divisoes: %d", ehprimo(n, &d), d);

        return 0;
}