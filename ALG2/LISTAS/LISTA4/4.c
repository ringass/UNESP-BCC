#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char p[100], ch;
    int frases, car, lin;

    frases = lin = car = 0;

    
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
        if(ch == '\n'){
          lin++;
          frases++;
        }else if(ch == ' '){
          frases++;
        }else{
          car++;
        }
    }

  
    printf("frases: %d\nlinhas: %d\ncaracteres: %d\n", frases++, lin, car);

    fclose(arq);

    return 0;
}
