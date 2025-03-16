#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n, altura;

    cin >> n;

    stack<int> pilha;

    for (int i = 0; i < n; i++)
    {

        cin >> altura;

        if (pilha.empty())
        {
            pilha.push(altura % 2);
        }
        else
        {
            if (altura % 2 == pilha.top())
            {
                pilha.pop();
            }
            else
            {
                pilha.push(altura % 2);
            }
        }
    }

    if(pilha.size() > 1){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }
}