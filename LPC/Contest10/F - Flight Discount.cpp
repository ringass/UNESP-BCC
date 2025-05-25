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

void dijkstra(int start, vector<vector<pair<int, int>>>& adj, vector<vector<ll>>& dist)
{

    dist[start][0] = 0;
    priority_queue<tuple<ll, int, bool>, vector<tuple<ll, int, bool>>, greater<>> pq;
    
    pq.push({0, start, 0});

    while (!pq.empty())
    {
        auto [d, u, cupom] = pq.top();
        pq.pop();

        if (d > dist[u][cupom])
            continue;

        for (auto [v, w] : adj[u])
        {
            if (d + w < dist[v][cupom]) //padrao, sem promocao nessa bomba
            {
                dist[v][cupom] = d + w;

                pq.push({dist[v][cupom], v, cupom});

            }

            if(!cupom){ //com promoçao nessa bomba

                ll promo = w/2;

                if(dist[v][1] > d + promo){
                    dist[v][1] = d + promo;
                    pq.push({dist[v][1], v, 1});
                }

            }
        }
    }
}


int main()
{

    fast();
    
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);
    vector<vector<ll>> dist(n + 1, vector<ll>(2, INF));

    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    dijkstra(1, adj, dist);

    
    cout << dist[n][1] << "\n";

    return 0;
}
