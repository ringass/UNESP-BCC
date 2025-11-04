#include <bits/stdc++.h>

#define MAX 100
#define INF 10e7

using namespace std;

bool flag;
int n, m;
vector<int> dist;
vector<tuple<int, int, int>> edges;

void bellmanFord(int s) {
    dist = vector<int>(MAX + 1, INF);
    dist[s] = 0;

    for (int i = 1; i <= n - 1; i++) {
        for (auto [u, v, w] : edges) {
            if (dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    flag = false;

    for (auto [u, v, w] : edges) {
        if (dist[u] + w < dist[v])
            flag = true;
    }
}

void addEdge(int u, int v, int w) {
    edges.push_back({u, v, w});
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> V = {1, 2, 3, 4, 5};
    vector<tuple<int, int, int>> A = {
        {1, 2, 3},
        {1, 3, 5},
        {2, 3, 2},
        {3, 4, -7},
        {4, 2, 1}
    };

    n = int(V.size());
    m = int(A.size());

    for (auto [u, v, w] : A)
        addEdge(u, v, w);

    bellmanFord(1);

    if (flag)
        cout << "Grafo contêm ciclo negativo!\n";
    else
        cout << "Grafo não possui ciclo negativo.\n";

    return 0;
}