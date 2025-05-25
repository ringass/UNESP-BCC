#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll INF = 1e18;


void fast()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void dijkstra(ll start, vector<vector<pair<ll, ll>>> &adj, vector<ll> &dist)
{

    dist[start] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;

    pq.push({0, start});

    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u])
            continue;

        for (auto [v, w] : adj[u])
        {
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main()
{

    fast();

    ll n, m, P, G;
    cin >> n >> m >> P >> G;

    vector<vector<pair<ll, ll>>> adj(n + 1);
    vector<ll> distP(n + 1, INF), distG(n + 1, INF);
    vector<ll> ans;

    for (ll i = 0; i < m; ++i)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dijkstra(P, adj, distP);
    dijkstra(G, adj, distG);

    for (ll i = 1; i <= n; i++)
    {

        if (i == P)
        {
            continue;
        }

        if ((2 * distG[i] == distP[i]) && (distP[G] + distG[i] == distP[i]))
        {
            ans.push_back(i);
        }
    }

    if(ans.empty()){
        cout << "*\n";
    }else{
        for(ll i : ans){
            cout << i << " ";
        }
        cout << "\n";
    }

    return 0;
}
