#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct endereco
{
    int num;
    char rua[25];
    char bairro[25];
    char cidade[25];
    char estado[25];
    char pais[25];
    int cep;
};

struct telefone
{
    int num;
    int ddd;
};

struct aniversario
{
    int dia;
    int mes;
    int ano;
};

typedef struct
{
    char nome[32];
    char email[32];
    struct endereco end;
    struct telefone tel;
    struct aniversario data;
} agenda[100];

void imprime_especifico(agenda vet, int i)
{

    printf("Nome: %s\n", vet[i].nome);
    printf("E-mail: %s\n", vet[i].email);
    printf("Data de Nascimento: %02d/%02d/%04d\n", vet[i].data.dia, vet[i].data.mes, vet[i].data.ano);
    printf("Endereco: %s, %d, %s, %s, %s, %d\n", vet[i].end.rua, vet[i].end.num, vet[i].end.bairro, vet[i].end.cidade, vet[i].end.estado, vet[i].end.cep);
    printf("=====================================\n");
}

void busca_por_p_nome(agenda vet, char *primeiro_nome, int size)
{
    int flag = 0;
    char nome_temp[32];

    for (int i = 0; i < size; i++)
    {

        strcpy(nome_temp, vet[i].nome);

        char *token = strtok(nome_temp, " ");

        if (token != NULL && strcmp(token, primeiro_nome) == 0)
        {
            imprime_especifico(vet, i);
            flag = 1;
        }
    }

    if (!flag)
    {
        printf("Nenhuma pessoa com esse primeiro nome foi encontrada\n");
    }
}

void busca_por_mes(agenda vet, int mes, int size)
{
    int flag = 0;

    for (int i = 0; i < size; i++)
    {

        if (mes == vet[i].data.mes)
        {
            imprime_especifico(vet, i);
            flag = 1;
        }
    }

    if (flag)
    {
        return;
    }
    else
    {

        printf("Nenhuma pessoa com esse mes de nascimento\n");
        return;
    }
}

void busca_por_mes_dia(agenda vet, int mes, int dia, int size)
{
    int flag = 0;

    for (int i = 0; i < size; i++)
    {

        if (mes == vet[i].data.mes && dia == vet[i].data.dia)
        {
            imprime_especifico(vet, i);
            flag = 1;
        }
    }

    if (flag)
    {
        return;
    }
    else
    {

        printf("Nenhuma pessoa com esse mes e dia de nascimento\n");
        return;
    }
}

void insere(agenda vet, int *size)
{
    int x;
    printf("Quantas pessoas deseja inserir? ");
    scanf("%d", &x);
    getchar();

    for (int i = *size; i < *size + x; i++)
    {
        printf("Nome: ");
        fgets(vet[i].nome, 32, stdin);
        vet[i].nome[strcspn(vet[i].nome, "\n")] = '\0';

        printf("E-mail: ");
        fgets(vet[i].email, 32, stdin);
        vet[i].email[strcspn(vet[i].email, "\n")] = '\0';

        printf("Data de nascimento (dd/mm/aaaa): ");
        scanf("%d/%d/%d", &vet[i].data.dia, &vet[i].data.mes, &vet[i].data.ano);
        getchar();

        printf("Endereco\n");
        printf("Rua: ");
        fgets(vet[i].end.rua, 25, stdin);
        vet[i].end.rua[strcspn(vet[i].end.rua, "\n")] = '\0';

        printf("Bairro: ");
        fgets(vet[i].end.bairro, 25, stdin);
        vet[i].end.bairro[strcspn(vet[i].end.bairro, "\n")] = '\0';

        printf("Numero: ");
        scanf("%d", &vet[i].end.num);
        getchar();

        printf("Estado: ");
        fgets(vet[i].end.estado, 25, stdin);
        vet[i].end.estado[strcspn(vet[i].end.estado, "\n")] = '\0';

        printf("Cidade: ");
        fgets(vet[i].end.cidade, 25, stdin);
        vet[i].end.cidade[strcspn(vet[i].end.cidade, "\n")] = '\0';

        printf("Pais: ");
        fgets(vet[i].end.pais, 25, stdin);
        vet[i].end.pais[strcspn(vet[i].end.pais, "\n")] = '\0';

        printf("CEP: ");
        scanf("%d", &vet[i].end.cep);
        getchar();
    }
    *size += x;
}

int retira(agenda vet, int *size, char *nome)
{
    if (*size == 0)
    {
        printf("LISTA VAZIA\n");
        return 0;
    }

    for (int i = 0; i < *size; i++)
    {
        if (strcmp(vet[i].nome, nome) == 0)
        {
            for (int j = i; j < *size - 1; j++)
            {
                vet[j] = vet[j + 1];
            }
            (*size)--;
            printf("Pessoa removida com sucesso.\n");
            return 1;
        }
    }
    printf("Pessoa não encontrada.\n");
    return 0;
}

void imprime(agenda vet, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Nome: %s\n", vet[i].nome);
        printf("E-mail: %s\n", vet[i].email);
        printf("Data de Nascimento: %02d/%02d/%04d\n", vet[i].data.dia, vet[i].data.mes, vet[i].data.ano);
        printf("Endereco: %s, %d, %s, %s, %s, %d\n", vet[i].end.rua, vet[i].end.num, vet[i].end.bairro, vet[i].end.cidade, vet[i].end.estado, vet[i].end.cep);
        printf("=====================================\n");
    }
}

int main()
{
    int e = 1, size = 0;
    agenda vetor;

    while (e != 0)
    {
        printf("\n||MENU||\n");
        printf("[1] - inserir pessoa\n");
        printf("[2] - remover pessoa\n");
        printf("[3] - procurar por primeiro nome\n");
        printf("[4] - procurar por mes do aniversario\n");
        printf("[5] - procurar por mes e dia do aniversario\n");
        printf("[6] - mostrar lista\n");
        printf("[0] - encerrar programa\n");

        printf("Digite sua escolha: ");
        scanf("%d", &e);
        getchar();

        switch (e)
        {
        case 1:
            insere(vetor, &size);
            system("cls");
            break;
        case 2:
        {
            char nome[32];
            printf("Digite o nome da pessoa que deseja remover: ");
            fgets(nome, 32, stdin);
            nome[strcspn(nome, "\n")] = '\0';
            retira(vetor, &size, nome);
            system("cls");
            break;
        }
        case 3:
        {
            char nn[32];

            printf("Digite o primeiro nome da pessoa que deseja procurar: ");
            gets(nn);
            system("cls");
            busca_por_p_nome(vetor, nn, size);
            break;
        }

        case 4:
        {
            int mes;

            printf("Digite o mes de aniversario da pessoa que deseja procurar: ");
            scanf("%d", &mes);
            system("cls");
            busca_por_mes(vetor, mes, size);
            break;
        }
        case 5:
        {
            int mes, dia;

            printf("Digite o mes e dia de aniversario da pessoa que deseja procurar(xx/xx): ");
            scanf("%d/%d", &dia, &mes);
            system("cls");
            busca_por_mes_dia(vetor, mes, dia, size);
        }
        break;
        case 6:
            system("cls");
            imprime(vetor, size);
            break;
        case 0:
            system("cls");
            printf("Obrigado por utilizar o programa\n");
            exit(0);
        default:
            printf("Opção Inválida\n");
            break;
        }
    }

    return 0;
}
