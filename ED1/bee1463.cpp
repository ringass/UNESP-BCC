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
        p = "";
        for (int i = 0; i < qt; i++)
        {
            arvore atual = fila.front();
            p += atual->info;
            fila.pop();

            if (atual->pEsq != NULL)
            {
                fila.push(atual->pEsq);
            }

            if (atual->pDir != NULL)
            {
                fila.push(atual->pDir);
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
        x->pEsq = parse(a, i);
        x->pDir = parse(a, i);
    }
    else if (t != ' ')
    {
        x->pEsq = x->pDir = NULL;
    }

    return x;
}

int prio(char c)
{

    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string resolve(string str)
{
    stack<char> pilha;
    string ans;

    reverse(str.begin(), str.end());

    for (int i = 0; i < str.length(); i++)
    {
        char c = str[i];

        if (c == ' ')
            continue;

        if (isalnum(c))
        {
            ans += c;
        }

        else if (c == ')')
        {
            pilha.push(c);
        }

        else if (c == '(')
        {
            while (!pilha.empty() && pilha.top() != ')')
            {
                ans += pilha.top();
                pilha.pop();
            }
            pilha.pop();
        }

        else
        {
            while (!pilha.empty() && prio(c) < prio(pilha.top()))
            {
                ans += pilha.top();
                pilha.pop();
            }
            pilha.push(c);
        }
    }

    while (!pilha.empty())
    {
        ans += pilha.top();
        pilha.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
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
    bool flag = true;

    while (getline(cin, str))
    {
        if (!flag)
        {
            cout << endl;
        }
        flag = false;
        string temp = resolve(str);

        // cout << temp << endl; VISUALIZAR A NOTACAO POLONESA INVERSA

        int i = 0;

        A = parse(temp, i);

        mostrar_bynivel(A);

        liberarArvore(A);
    }

    return 0;
}
