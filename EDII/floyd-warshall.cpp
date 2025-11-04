#include <bits/stdc++.h>

#define MAX 100
#define INF 10e7

using namespace std;

int n, m;
int adj[MAX + 1][MAX + 1], dist[MAX + 1][MAX + 1];

void floydWarshall() {
    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++) {
            if (u != v) {
                if (adj[u][v] != 0)
                    dist[u][v] = adj[u][v];
                else
                    dist[u][v] = INF;
            }
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int u = 1; u <= n; u++) {
            for (int v = 1; v <= n; v++) {
                if (dist[u][k] + dist[k][v] < dist[u][v])
                    dist[u][v] = dist[u][k] + dist[k][v];
            }
        }
    }
}

void addEdge(int u, int v, int w) {
    adj[u][v] = w;
    adj[v][u] = w;
}

void initGraph() {
    for (int u = 1; u <= n; u++) {
        for (int v = u; v <= n; v++) {
            adj[u][v] = 0;
            adj[v][u] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> V = {1, 2, 3, 4, 5};
    vector<tuple<int, int, int>> A = {
        {1, 2, 5},
        {1, 4, 9},
        {1, 5, 1},
        {2, 3, 2},
        {3, 4, 6},
        {4, 5, 2}
    };

    n = int(V.size());
    m = int(A.size());

    for (auto [u, v, w] : A)
        addEdge(u, v, w);

    floydWarshall();

    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++)
            cout << dist[u][v] << " ";

        cout << "\n";
    }

    return 0;
}