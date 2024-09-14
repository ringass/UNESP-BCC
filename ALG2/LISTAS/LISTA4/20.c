#include <stdio.h>
#include <string.h>

int main() {
    char nomearq1[15], nomearq2[15], ch1, ch2;
    
    fgets(nomearq1, sizeof(nomearq1), stdin);
    nomearq1[strcspn(nomearq1, "\n")] = '\0'; 

    fgets(nomearq2, sizeof(nomearq2), stdin);
    nomearq2[strcspn(nomearq2, "\n")] = '\0'; 

    FILE *arq1 = fopen(strcat(nomearq1, ".txt"), "r");
    FILE *arq2 = fopen(strcat(nomearq2, ".txt"), "r");
    int i = 1;

    while ((ch1 = fgetc(arq1)) != EOF && (ch2 = fgetc(arq2)) != EOF) {
        if (ch1 == ch2 && (ch1 != ' ' && ch1 != '\n')) {
            printf("%d - %c (%d)\n", i, ch1, ch1);
        }
        i++;
    }

    fclose(arq1);
    fclose(arq2);

    return 0;
}
