#include <bits/stdc++.h>

using namespace std;

typedef struct reg *arvore;

struct reg
{
    int info;
    struct reg *pEsq;
    struct reg *pDir;
};

arvore criarNo(int valor)
{
    arvore novo = (arvore)malloc(sizeof(struct reg));
    novo->info = valor;
    novo->pEsq = NULL;
    novo->pDir = NULL;
    return novo;
}

arvore inserirBST(arvore raiz, int valor)
{
    if (raiz == NULL)
    {
        return criarNo(valor);
    }
    if (valor < raiz->info)
    {
        raiz->pEsq = inserirBST(raiz->pEsq, valor);
    }
    else if (valor > raiz->info)
    {
        raiz->pDir = inserirBST(raiz->pDir, valor);
    }
    return raiz;
}

void mostrar_bynivel(arvore raiz)
{
    if (raiz == NULL)
    {
        return;
    }

    queue<arvore> fila;
    fila.push(raiz);
    int x = 0;

    while (!fila.empty())
    {
        int qt = fila.size();
        int min = 1000000;

        for (int i = 0; i < qt; i++)
        {
            arvore atual = fila.front();
            fila.pop();

            if(atual->info < min){
                min = atual->info;
            }

            if (atual->pDir != NULL)
            {
                fila.push(atual->pDir);
            }

            if (atual->pEsq != NULL)
            {
                fila.push(atual->pEsq);
            }
        }
        cout << x << " " << min << endl;
        x++;
    }
}

void liberarArvore(arvore raiz)
{
    if (raiz != NULL)
    {
        liberarArvore(raiz->pEsq);
        liberarArvore(raiz->pDir);
        free(raiz);
    }
}

void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    fast();

    arvore A = NULL;

    int qt;

    cin >> qt;

    for (int i = 0; i < qt; i++)
    {
        int val;

        cin >> val;

        A = inserirBST(A, val);
    }

    mostrar_bynivel(A);

    liberarArvore(A);

    return 0;
}