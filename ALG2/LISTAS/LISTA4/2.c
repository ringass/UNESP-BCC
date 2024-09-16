#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char p[100], ch;
    int vog, con;

    vog = con = 0;

    
    printf("Digite o nome do arquivo (sem extensão .txt): ");
    scanf("%s", p);

    
    FILE *arq = fopen(strcat(p, ".txt"), "r");

    
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    while ((ch = fgetc(arq)) != EOF)
    {
        if (isalpha(ch))  
        {
            if (toupper(ch) == 'A' || toupper(ch) == 'E' || toupper(ch) == 'I' || toupper(ch) == 'O' || toupper(ch) == 'U')
            {
                vog++;  
            }
            else
            {
                con++; 
            }
        }
    }

  
    printf("Vogais: %d\nConsoantes: %d\n", vog, con);
    
    fclose(arq);

    return 0;
}
