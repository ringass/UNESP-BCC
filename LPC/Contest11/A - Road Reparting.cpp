#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;
using edge = pair<int, pair<int, int>>;

const int maxN = 1e5 + 1;
const int maxM = 2e5 + 1;

int N, M, a, b, c;
int ds[maxN];
long long sum = 0;
edge edges[maxM];

void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int find(int u)
{
    if (ds[u] < 0)
        return u;
    return ds[u] = find(ds[u]);
}

bool merge(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v)
        return false;
    if (ds[u] < ds[v])
        swap(u, v);
    ds[v] += ds[u];
    ds[u] = v;
    return true;
}

int main()
{      
    fast();
    cin >> N >> M;
    fill(ds + 1, ds + N + 1, -1);

    for (int i = 0; i < M; i++)
    {
        cin >> a >> b >> c;
        edges[i] = make_pair(c, make_pair(a, b));
    }

    sort(edges, edges + M);

    for (int i = 0; i < M; i++)
    {
        int cost = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        if (merge(u, v))
        {
            sum += cost;
            N--;
        }
    }

    if (N == 1)
    {
        cout << sum << "\n";
    }
    else
    {
        cout << "IMPOSSIBLE\n";
    }

    return 0;
}
