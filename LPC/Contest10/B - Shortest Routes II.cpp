#include <bits/stdc++.h>

using namespace std;
#define ll long long

const long long INF = 1e15;

void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve(ll n, ll m, ll q)
{

    vector<vector<ll>> g(n + 1);

    for (ll i = 0; i <= n; ++i)
    {
        g[i].resize(n + 1);
    }

    for (ll i = 1; i <= n; ++i)
    {
        for (ll j = i + 1; j <= n; ++j)
        {
            g[i][j] = g[j][i] = INF;
        }
    }

    for (ll i = 0; i < m; ++i)
    {
        ll u, v, c;

        cin >> u >> v >> c;

        g[u][v] = g[v][u] = min(g[u][v], c);
    }

    for (ll k = 1; k <= n; ++k)
    {
        for (ll i = 1; i <= n; ++i)
        {
            for (ll j = 1; j <= n; ++j)
            {

                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }

    for (ll i = 0; i < q; ++i)
    {
        ll u, v;

        cin >> u >> v;

        if (g[u][v] == INF)
            g[u][v] = -1;

        cout << g[u][v] << "\n";
    }
}

int main()
{
    fast();

    ll n, m, q;

    cin >> n >> m >> q;

    solve(n, m, q);
}