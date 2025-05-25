#include <bits/stdc++.h>
using namespace std;

const int INF = 10e9 + 5;;

void fast()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void dijkstra(int start, vector<vector<pair<int, int>>>& adj, vector<int>& dist, vector<int>& parent)
{

    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    
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
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
}

vector<int> r_path(int end, vector<int>& parent)
{
    vector<int> path;
    for (int i = end; i != -1; i = parent[i])
    {
        path.push_back(i);
    }

    reverse(path.begin(), path.end());
    return path;
}

int main()
{

    fast();
    
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);
    vector<int> dist(n + 1, INF);
    vector<int> parent(n + 1, -1);

    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dijkstra(1, adj, dist, parent);

    if (dist[n] == INF)
    {
        cout << -1 << '\n';
    }
    else
    {
        vector<int> path = r_path(n, parent);

        for (int node : path)
        {
            cout << node << ' ';
        }
        cout << '\n';
    }

    return 0;
}
