#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int buscabinaria2(int x, int n, int v[])
{   
    int m;
    int e = -1, d = n;
while (e < d-1)
{
    m = (e + d) / 2;
if (v[m] < x)
    e = m;
else
    d = m;
}
return d;
}

int main()
{   
    int v[15] = {0};

    for(int i = 0; i < 15; i++){
        v[i] = i;
    }

    printf("%d", buscabinaria2(5, 15, v));
    return 0;
}