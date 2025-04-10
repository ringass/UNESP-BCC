#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define median_q -1

void fast()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int main()
{
    fast();

    int t;
    cin >> t;

    while (t--)
    {

        priority_queue<int> fila_de_maiores;
        priority_queue<int, vector<int>, greater<int>> fila_de_menores;

        while (true)
        {
            int n;
            cin >> n;

            if (n == 0)
                break;

            if (n != median_q)
            {

                if (fila_de_maiores.empty() || n <= fila_de_maiores.top())
                {
                    fila_de_maiores.push(n);
                }
                else
                {
                    fila_de_menores.push(n);
                }

                if (fila_de_maiores.size() > fila_de_menores.size() + 1)
                {
                    fila_de_menores.push(fila_de_maiores.top());
                    fila_de_maiores.pop();
                }
                else if (fila_de_menores.size() > fila_de_maiores.size())
                {
                    fila_de_maiores.push(fila_de_menores.top());
                    fila_de_menores.pop();
                }
            }
            else
            {
                int mediana = fila_de_maiores.top();
                cout << mediana << "\n";
                fila_de_maiores.pop();

                if (fila_de_maiores.size() < fila_de_menores.size())
                {
                    fila_de_maiores.push(fila_de_menores.top());
                    fila_de_menores.pop();
                }
            }
        }
    }

    return 0;
}
