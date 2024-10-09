#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX 150

typedef struct
{
    char nome[32];
    char estado_c[24];
    int prioridade;
} fichas;

void receber(fichas *paciente, int *qt)
{
    fichas new;
    int len, cadastro;

    printf("Quantos pacientes deseja inserir: ");
    scanf("%d", &len);
    getchar();

    for (int i = 0; i < len; i++)
    {
        cadastro = 1;

        printf("Digite o nome do paciente: ");
        gets(new.nome);

        printf("Digite o estado do paciente: ");
        gets(new.estado_c);

        if (strcmp(new.estado_c, "pessimo") == 0)
        {
            new.prioridade = 3;
        }
        else if (strcmp(new.estado_c, "ruim") == 0)
        {
            new.prioridade = 2;
        }
        else if (strcmp(new.estado_c, "regular") == 0)
        {
            new.prioridade = 1;
        }
        else
        {
            cadastro = 0;
        }

        if (cadastro)
        {
            int dentro = 1;

            for (int j = *qt; j > 0; j--)
            {
                if (new.prioridade > paciente[j - 1].prioridade)
                {
                    paciente[j] = paciente[j - 1];
                }
                else
                {
                    paciente[j] = new;
                    dentro = 0;
                    break;
                }
            }

            if (dentro)
            {
                paciente[0] = new;
            }

            (*qt)++;
        }
        else
        {
            printf("Impossivel cadastrar o usuario com esse tipo de estado\n\n");
            continue;
        }
        printf("\n");
    }
}

void chamarPaciente(fichas *pacientes, int *qt)
{
    if (*qt == 0)
    {
        printf("Nenhum paciente na fila.\n");
        return;
    }
    
    printf("Chamando paciente: %s (Estado: %s)\n", pacientes[0].nome, pacientes[0].estado_c);

    for (int i = 1; i < *qt; i++)
    {
        pacientes[i - 1] = pacientes[i];
    }
    (*qt)--;
}

// void Consultar(fichas *pacientes, int *qt)
// {
//     for (int i = 0; i < *qt; i++)
//     {
//         printf("Chamando paciente: %s (Estado: %s)\n", pacientes[i].nome, pacientes[i].estado_c);
//     }
//     printf("\n\n\n\n\n");
// }

int main()
{
    int qt = 0, r = 1;
    fichas pacientes[MAX];
    
    while(r){
    receber(pacientes, &qt);

    //Consultar(pacientes, &qt);

    while (qt > 0)
    {
        chamarPaciente(pacientes, &qt);
    }
    
    printf("1 - continuar / 0 - parar: ");
    scanf("%d", &r);
}
    return 0;
}