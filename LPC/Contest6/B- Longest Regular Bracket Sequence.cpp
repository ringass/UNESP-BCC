#include <bits/stdc++.h>
using namespace std;

void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve(string str)
{

    int maxtam = 0, count = 0;
    stack<int> pilha;
    pilha.push(-1);

    for (int i = 0; i < str.length(); i++)
    {

        if (str[i] == '(')
        {
            pilha.push(i);
        }
        else
        {
            pilha.pop();

            if (!pilha.empty())
            {
                int tam;
                tam = i - pilha.top();

                if (tam > maxtam)
                {
                    maxtam = tam;
                    count = 1;
                }
                else if (tam == maxtam)
                {
                    count++;
                }
            }
            else
            {
                pilha.push(i);
            }
        }
    }

    (maxtam == 0) ? cout << "0 1\n" : cout << maxtam << " " << count << '\n';
}

int main()
{

    string str;

    cin >> str;

    solve(str);
}