#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll INF = 1e7;
ll n, m;
vector<ll> dist;
vector<tuple<ll, ll, ll>> adj;
vector<ll> parent;
ll neg = -1;

void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool bellman_ford(ll s)
{
    dist = vector<ll>(n + 1, INF);
    parent.assign(n + 1, -1);
    dist[s] = 0;

    for (ll i = 1; i <= n; i++)
    {
        neg = -1;
        for (auto [u, v, w] : adj)
        {
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                parent[v] = u;
                neg = v;
            }
        }
    }

    return (neg != -1);
}

vector<ll> build_cycle()
{

    for (int i = 0; i < n; i++)
    {
        neg = parent[neg];
    }

    vector<ll> cycle;
    ll v = neg;
    do
    {
        cycle.push_back(v);
        v = parent[v];
        
    } while (v != neg);

    cycle.push_back(neg);
    reverse(cycle.begin(), cycle.end());
    return cycle;
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

    if (!bellman_ford(1))
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
        vector<ll> cycle = build_cycle();
        for (ll v : cycle)
        {
            cout << v << " ";
        }
        cout << "\n";
    }

    return 0;
}
