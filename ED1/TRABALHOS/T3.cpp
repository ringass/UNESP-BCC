// fila
//MURILO TOMAZ GONZAGA 
#include <bits/stdc++.h>

#define ull unsigned long long

using namespace std;

void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve(int n, int m)
{

    int ans = 0, i = 0, media = 0;
    ull val, soma = 0;
    queue<ull> fila;

    while (i < 30)
    {

        cin >> val;

        fila.push(val);

        soma += val;

        i++;
    }

    while (n < m)
    {

        media = ceil((double)soma / 30.0);

        n += media;

        soma -= fila.front();
        fila.pop();

        fila.push(media);
        soma += media;

        ans++;
    }

    cout << ans << "\n";
}

int main()
{

    int n, m;

    cin >> n >> m;

    solve(n, m);
}
