#include <bits/stdc++.h>

using namespace std;

bool vazio(deque<int> &fila)
{
    if (fila.empty())
    {
        cout << "No job for Ada?" << endl;
        return true;
    }
    return false;
}

int main()
{
    deque<int> fila;
    int n, x, rev = 0;
    string str;

    cin >> n;

    while (n--)
    {
        cin >> str; // Correção na leitura da string

        switch (str[0])
        {
        case 'r': // Reverse
            rev = !rev;
            break;

        case 'p': // Push back (ou push front, dependendo de 'rev')
            cin >> x;
            if (rev)
            {
                fila.push_front(x);
            }
            else
            {
                fila.push_back(x);
            }
            break;

        case 't': // Push front (ou push back, dependendo de 'rev')
            cin >> x;
            if (rev)
            {
                fila.push_back(x);
            }
            else
            {
                fila.push_front(x);
            }
            break;

        case 'f': // Pop front (ou back, dependendo de 'rev')
            if (!vazio(fila))
            {
                if (rev)
                {
                    cout << fila.back() << endl;
                    fila.pop_back();
                }
                else
                {
                    cout << fila.front() << endl;
                    fila.pop_front();
                }
            }
            break;

        case 'b': // Pop back (ou front, dependendo de 'rev')
            if (!vazio(fila))
            { // Corrigido para chamar a função corretamente
                if (rev)
                {
                    cout << fila.front() << endl;
                    fila.pop_front();
                }
                else
                {
                    cout << fila.back() << endl;
                    fila.pop_back();
                }
            }
            break;
        }
    }

    return 0;
}
