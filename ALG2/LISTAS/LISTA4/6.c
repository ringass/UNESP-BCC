#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char p[100], ch;
    char conteudo1[10000], conteudo2[10000]; 
    int i = 0, j = 0;

    
    printf("Digite o nome do primeiro arquivo (sem extensão .txt): ");
    scanf("%s", p);

    FILE *arq1 = fopen(strcat(p, ".txt"), "r");

   
    printf("Digite o nome do segundo arquivo (sem extensão .txt): ");
    scanf("%s", p);

    FILE *arq2 = fopen(strcat(p, ".txt"), "r");

    
    FILE *arq3 = fopen("new.txt", "w");

    while ((ch = fgetc(arq1)) != EOF && i < 10000)
    {
        conteudo1[i] = ch;
        i++;
    }
    conteudo1[i] = '\0'; 

   
    while ((ch = fgetc(arq2)) != EOF && j < 10000)
    {
        conteudo2[j] = ch;
        j++;
    }
    conteudo2[j] = '\0'; 

    
    fputs(conteudo1, arq3);
    fputs("\n\n", arq3); 
    fputs(conteudo2, arq3);

    
    fclose(arq1);
    fclose(arq2);
    fclose(arq3);

    printf("alteramos o 'new.txt'\n");

    return 0;
}
