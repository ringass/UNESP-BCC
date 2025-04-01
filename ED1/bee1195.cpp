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

void inOrder(arvore AA){
    if(AA != NULL){
        inOrder(AA->pEsq);
        cout << " " << AA->info;
        inOrder(AA->pDir);
    }
}

void preOrder(arvore AA){
    if(AA != NULL){
        cout << " " << AA->info;
        preOrder(AA->pEsq);
        preOrder(AA->pDir);
    }
}

void postOrder(arvore AA){
    if(AA != NULL){
        postOrder(AA->pEsq);
        postOrder(AA->pDir);
        cout << " " << AA->info;
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
    int n;
    cin >> n;

    for(int j = 0; j < n; j++)
    {

        arvore A = NULL;

        int qt;

        cin >> qt;

        for (int i = 0; i < qt; i++)
        {
            int val;

            cin >> val;

            A = inserirBST(A, val);
        }

        cout << "Case " << j+1 << ":\n";
        cout << "Pre.:";
        preOrder(A); cout << "\n";

        cout << "In..:";
        inOrder(A);
        cout << "\n";

        cout << "Post:";
        postOrder(A);
        cout << "\n";

        liberarArvore(A);

        cout << "\n";
    }

    return 0;
}