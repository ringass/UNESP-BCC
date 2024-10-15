#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int main() {

    int qt;

    scanf("%d", &qt);

    char A[qt+1];

    for(int i = 0; i < qt; i++){
        A[i] = 'a';
    }
    A[qt+1] = '\0';
    A[qt] = '\0';

    printf("Ent%so eh N%st%sl!", A, A, A);



    return 0;
}