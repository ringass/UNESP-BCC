#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

typedef struct
{
    char nome[20], curso[20];
    int numero;
    float p1, p2, MT, freq;
} reg;

void receber(reg r[], int *n)
{
    int i = 0;

    printf("Quantos registros? ");
    scanf("%d", n);
    getchar();

    if (*n > MAX)
    {
        printf("Número de cadastros excede o máximo permitido.\n");
        return;
    }

    while (i < *n)
    {
        printf("Aluno %d\n", i + 1);

        printf("Nome: ");
        fgets(r[i].nome, sizeof(r[i].nome), stdin);
        r[i].nome[strcspn(r[i].nome, "\n")] = '\0';

        printf("Curso: ");
        fgets(r[i].curso, sizeof(r[i].curso), stdin);
        r[i].curso[strcspn(r[i].curso, "\n")] = '\0';

        printf("Numero: ");
        scanf("%d", &r[i].numero);

        printf("NOTA da P1: ");
        scanf("%f", &r[i].p1);

        printf("NOTA da P2: ");
        scanf("%f", &r[i].p2);

        printf("NOTA da MT: ");
        scanf("%f", &r[i].MT);

        printf("FREQUENCIA: ");
        scanf("%f", &r[i].freq);

        getchar();

        i++;
    }

    FILE *arquivo = fopen("alunos.dat", "wb");

    for (i = 0; i < *n; i++)
    {
        fwrite(&r[i], sizeof(reg), 1, arquivo);
    }

    fclose(arquivo);
}

void aprovacao()
{
    reg r;
    FILE *todos = fopen("alunos.dat", "rb");

    if (todos == NULL)
    {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    while (fread(&r, sizeof(reg), 1, todos) == 1)
    {
        float MP = (r.p1 + r.p2) / 2;
        float MF = (0.8 * MP) + (0.2 * r.MT);

        printf("Nome: %s\n", r.nome);
        printf("Curso: %s\n", r.curso);
        printf("Numero: %d\n", r.numero);
        printf("NOTA FINAL: %.2f\n", MF);
        printf("Frequência: %.2f%%\n", r.freq);

        if (MF >= 4.95 && r.freq >= 70.00)
        {
            printf("CONDIÇÃO: APROVADO\n\n");
        }
        else
        {
            printf("CONDIÇÃO: REPROVADO\n\n");
        }
    }

    fclose(todos);
}

void alterar(int num)
{
    reg r;
    int encontrado = 0;
    FILE *arquivo = fopen("alunos.dat", "rb+");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    while (fread(&r, sizeof(reg), 1, arquivo) == 1)
    {
        if (r.numero == num)
        {
            encontrado = 1;
            fseek(arquivo, -sizeof(reg), SEEK_CUR);

            printf("Novo nome: ");
            getchar();
            fgets(r.nome, sizeof(r.nome), stdin);
            r.nome[strcspn(r.nome, "\n")] = '\0';

            printf("Novo curso: ");
            fgets(r.curso, sizeof(r.curso), stdin);
            r.curso[strcspn(r.curso, "\n")] = '\0';

            printf("Nova P1: ");
            scanf("%f", &r.p1);

            printf("Nova P2: ");
            scanf("%f", &r.p2);

            printf("Nova MT: ");
            scanf("%f", &r.MT);

            printf("Nova frequência: ");
            scanf("%f", &r.freq);

            fwrite(&r, sizeof(reg), 1, arquivo);
            break;
        }
    }

    if (!encontrado)
    {
        printf("Registro não encontrado.\n");
    }

    fclose(arquivo);
}

void excluir(int num)
{
    reg r;
    FILE *arquivo = fopen("alunos.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");

    if (arquivo == NULL || temp == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    while (fread(&r, sizeof(reg), 1, arquivo) == 1)
    {
        if (r.numero != num)
        {
            fwrite(&r, sizeof(reg), 1, temp);
        }
    }

    fclose(arquivo);
    fclose(temp);

    remove("alunos.dat");
    rename("temp.dat", "alunos.dat");

    printf("Registro excluído.\n");
}

void listar()
{
    reg r;
    FILE *arquivo = fopen("alunos.dat", "rb");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    while (fread(&r, sizeof(reg), 1, arquivo) == 1)
    {
        printf("Nome: %s, Numero: %d\n", r.nome, r.numero);
    }

    fclose(arquivo);
}

int main()
{
    reg registros[MAX];
    int opcao, n, num;

    do
    {
        printf("\nMenu:\n");
        printf("1. Cadastrar alunos\n");
        printf("2. Consultar situação de alunos\n");
        printf("3. Alterar registro\n");
        printf("4. Excluir registro\n");
        printf("5. Listar alunos\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            receber(registros, &n);
            break;
        case 2:
            aprovacao();
            break;
        case 3:
            printf("Digite o número do aluno a ser alterado: ");
            scanf("%d", &num);
            alterar(num);
            break;
        case 4:
            printf("Digite o número do aluno a ser excluído: ");
            scanf("%d", &num);
            excluir(num);
            break;
        case 5:
            listar();
            break;
        case 6:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida.\n");
        }
    } while (opcao != 6);

    return 0;
}
