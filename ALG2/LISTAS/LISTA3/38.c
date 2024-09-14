#include <stdio.h>
#include <stdlib.h>

#define MAX 50

typedef struct
{
    char sexo, fumante;
    int idade;
} registros;

void receberDados()
{
    int qt;
    FILE *file = fopen("resposta.bin", "ab");

    if (file == NULL)
    {
        printf("erro ao abrir o arquivo");
        return;
    }

    registros dados[MAX];
    printf("qual a quantidade de pessoas na pesquisa?\n");
    scanf("%d", &qt);

    for (int i = 0; i < qt; i++)
    {
        printf("ENTREVISTADO %d\n", i + 1);
        printf("SEXO (M/F): ");
        scanf(" %c", &dados[i].sexo);
        printf("FUMANTE? (S/N): ");
        scanf(" %c", &dados[i].fumante);
        printf("IDADE: ");
        scanf("%d", &dados[i].idade);
        fwrite(&dados[i], sizeof(registros), 1, file);
    }
    fclose(file);
}

void responder()
{
    int qt = 0;
    int total_fumantes = 0, hf = 0, mf = 0;
    int hf40 = 0, mf40 = 0;

    FILE *file = fopen("resposta.bin", "rb");
    registros dados[MAX];
    if (file == NULL)
    {
        printf("erro ao abrir o arquivo");
        return;
    }

    while (fread(&dados[qt], sizeof(registros), 1, file))
    {
        qt++;

        if (dados[qt - 1].fumante == 'S')
        {
            total_fumantes++;
            if (dados[qt - 1].sexo == 'M')
            {
                hf++;
                if (dados[qt - 1].idade < 40)
                {
                    hf40++;
                }
            }
            else if (dados[qt - 1].sexo == 'F')
            {
                mf++;
                if (dados[qt - 1].idade > 40)
                {
                    mf40++;
                }
            }
        }
    }
    fclose(file);

    if (qt > 0)
    {
        printf("O percentual de fumante eh: %.2f\n", ((float)total_fumantes / qt) * 100);
    }
    else
    {
        printf("nao ha dados de fumantes\n");
    }

    if (hf > 0)
    {
        printf("fumantes homens com menos de 40: %.2f\n", ((float)hf40 / hf) * 100);
    }
    else
    {
        printf("nao ha homens fumantes\n");
    }

    if (mf > 0)
    {
        printf("fumantes mulheres com menos de 40: %.2f\n", ((float)mf40 / mf) * 100);
    }
    else
    {
        printf("nao ha mulheres fumantes\n");
    }
}

int main(int argc, char *argv[])
{
    receberDados();
    responder();

    return 0;
}
