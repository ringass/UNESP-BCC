#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll INF = 1e7;
ll n, m;
vector<ll> dist;
vector<tuple<ll, ll, ll>> adj;

void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void bellman_ford(ll s)
{
    dist = vector<ll>(n + 1, INF);
    dist[s] = 0;

    for (ll i = 1; i <= n - 1; i++)
    {
        for (auto [u, v, w] : adj)
        {
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }
}

int main()
{
    fast();
    cin >> n >> m;

    ll u, v, w;

    for (ll i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        adj.push_back({u, v, w});
    }

    bellman_ford(1);

    for (ll v = 1; v <= n; v++)
    {
        if (dist[v] == INF)
            cout << 30000 << " ";
        else
            cout << dist[v] << " ";
    }

    return 0;
}