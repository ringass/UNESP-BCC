//MURILO TOMAZ GONZAGA 
#include <bits/stdc++.h>

#define ui unsigned int

using namespace std;

void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

typedef struct reg *No;

struct reg
{
    string info;
    int altura;
    No pEsq;
    No pDir;
};

int getAltura(No raiz)
{
    return raiz ? raiz->altura : -1;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

No criarNo(string valor)
{
    No novo = new struct reg;
    novo->info = valor;
    novo->altura = 0;
    novo->pEsq = NULL;
    novo->pDir = NULL;
    return novo;
}

int calcAltura(No raiz)
{
    return max(getAltura(raiz->pEsq), getAltura(raiz->pDir)) + 1;
}

No rDir(No raiz)
{
    No newPivot = raiz->pEsq;
    No newEsq = newPivot->pDir;

    newPivot->pDir = raiz;
    raiz->pEsq = newEsq;

    raiz->altura = calcAltura(raiz);
    newPivot->altura = calcAltura(newPivot);

    return newPivot;
}

No rEsq(No raiz)
{
    No newPivot = raiz->pDir;
    No newDir = newPivot->pEsq;

    newPivot->pEsq = raiz;
    raiz->pDir = newDir;

    raiz->altura = calcAltura(raiz);
    newPivot->altura = calcAltura(newPivot);

    return newPivot;
}

int getBalanco(No raiz)
{
    return getAltura(raiz->pEsq) - getAltura(raiz->pDir);
}

No balancear(No raiz, int balanco)
{
    if (balanco > 1)
    {
        if (getBalanco(raiz->pEsq) >= 0)
            return rDir(raiz);
        else
        {
            raiz->pEsq = rEsq(raiz->pEsq);
            return rDir(raiz);
        }
    }
    else if (balanco < -1)
    {
        if (getBalanco(raiz->pDir) <= 0)
            return rEsq(raiz);
        else
        {
            raiz->pDir = rDir(raiz->pDir);
            return rEsq(raiz);
        }
    }

    return raiz;
}

No inserirAVL(No raiz, string valor) //poderia ter feito com set, pensei depois que implementei.
{
    if (raiz == NULL)
        return criarNo(valor);

    if (valor < raiz->info)
        raiz->pEsq = inserirAVL(raiz->pEsq, valor);
    else if (valor > raiz->info)
        raiz->pDir = inserirAVL(raiz->pDir, valor);
    else
        return raiz;

    raiz->altura = calcAltura(raiz);
    int balanco = getBalanco(raiz);
    return balancear(raiz, balanco);
}

void emOrdem(No raiz) //impressao em ordem alfabetica, igual menor pro maior
{
    if (raiz != NULL)
    {
        emOrdem(raiz->pEsq);
        cout << raiz->info << "\n";
        emOrdem(raiz->pDir);
    }
}

int main()
{
    fast();
    string lin;
    No raiz = NULL;

    while (cin >> lin)
    {
        string pal = "";

        for (ui i = 0; i < lin.length(); i++)
        {
            if (isalpha(lin[i]))
            {
                pal += tolower(lin[i]);
            }
            else if (!pal.empty())
            {
                raiz = inserirAVL(raiz, pal);
                pal = "";
            }
        }
        if (!pal.empty())
        {
            raiz = inserirAVL(raiz, pal);
        }
    }

    emOrdem(raiz);

    return 0;
}
