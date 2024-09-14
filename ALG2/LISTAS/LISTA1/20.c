#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

void func(const char p[], char z[]) {
    int i = 0, j = 0;

    while (p[i] != '\0') {
        if (!isspace(p[i])) {
            z[j] = p[i];
            j++;
        }
        i++;
    }
    z[j] = '\0';
}

int main() {
    char frase[MAX];
    char frase2[MAX];

    gets(frase);

    func(frase, frase2);
    puts(frase2);
    return 0;
}
