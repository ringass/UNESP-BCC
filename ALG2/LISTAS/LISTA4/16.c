#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    FILE *arq = fopen("nao.txt", "r");
    FILE *arq1 = fopen("sim.txt", "w");
    int formatar = 1, Nformatar = 0;
    char linha[60];

    while (fgets(linha, sizeof(linha), arq))
    {
        linha[strcspn(linha, "\n")] = '\0';

        if (strcmp(linha, ".pp") == 0)
        {
            formatar = 1;
            continue;
        }
        else if (strcmp(linha, ".dS") == 0)
        {
            Nformatar = 1;
            continue;
        }
        else if (strcmp(linha, ".dE") == 0)
        {
            Nformatar = 0;
            continue;
        }

        if (Nformatar)
        {
            fprintf(arq1, "%s\n", linha);
            continue;
        }

        if (formatar)
        {

            char linha_formatada[62];

            while (strlen(linha) > 0)
            {
                int tamanho = 0;

                if (strlen(linha) > 60)
                {
                    tamanho = strlen(linha);
                }
                else
                {
                    tamanho = 60;
                }

                strncpy(linha_formatada, linha, tamanho);
                

                fprintf(arq1, "   %s   \n", linha_formatada );

                if (strlen(linha) > tamanho) {
                    memmove(linha, linha + tamanho, strlen(linha) - tamanho + 1);
                } else {
                    linha[0] = '\0';
                }
            }
        }
    }
    fclose(arq);
    fclose(arq1);
    return 0;
}