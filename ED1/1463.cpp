#include <bits/stdc++.h>

using namespace std;

typedef struct reg *arvore;

struct reg
{
    char info;
    arvore pEsq;
    arvore pDir;
};

arvore criarNo(char valor)
{
    arvore novo = new struct reg;
    novo->info = valor;
    novo->pEsq = NULL;
    novo->pDir = NULL;
    return novo;
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
    string p = "";
    while (!fila.empty())
    {
        int qt = fila.size();

        for (int i = 0; i < qt; i++)
        {
            arvore atual = fila.front();
            p += atual->info;
            fila.pop();

            if (atual->pDir != NULL)
            {
                fila.push(atual->pDir);
            }

            if (atual->pEsq != NULL)
            {
                fila.push(atual->pEsq);
            }
        }
        cout << "Nivel " << x << ": " << p << endl;
        x++;
    }
}

void liberarArvore(arvore raiz)
{
    if (raiz != NULL)
    {
        liberarArvore(raiz->pEsq);
        liberarArvore(raiz->pDir);
        delete raiz;
    }
}

void inOrder(arvore AA)
{
    if (AA != NULL)
    {
        inOrder(AA->pEsq);
        cout << " " << AA->info;
        inOrder(AA->pDir);
    }
}

arvore parse(string a, int &i)
{
    char t = a[i++];
    arvore x = criarNo(t);

    if (t == '+' || t == '*' || t == '/' || t == '-')
    {
        cout << i << endl;
        x->pEsq = parse(a, i);
        cout << i << endl;
        x->pDir = parse(a, i);
    }
    else if(t != ' ')
    {
        x->pEsq = x->pDir = NULL;
    }

    return x;
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
    string str = "";

    cin >> str;

    int i = 0;
    A = parse(str, i);

    inOrder(A);

    // mostrar_bynivel(A);

    liberarArvore(A);

    return 0;
}
