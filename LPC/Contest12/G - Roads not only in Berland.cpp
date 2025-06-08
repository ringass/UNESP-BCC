#include <bits/stdc++.h>

using namespace std;

void fast()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

const int MAX = 1005;

vector<vector<int>> adj;
vector<pair<int, int>> del;
int parent[MAX], rank_[MAX];

int find(int u)
{
    if (parent[u] != u)
    {
        parent[u] = find(parent[u]);
    }

    return parent[u];
}

int merge(int u, int v)
{

    int a = find(u);
    int b = find(v);

    if (a == b)
    {
        return false;
    }

    if (rank_[a] < rank_[b])
    {
        swap(a, b);
    }

    parent[b] = a;
    rank_[a] += rank_[b];

    return true;
}

int main()
{

    memset(rank_, 0, sizeof rank_);

    fast();

    int n, a, b;

    cin >> n;

    adj.resize(n + 3);

    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }

    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;

        adj[a].push_back(b);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            if(!merge(i, adj[i][j]))
                del.push_back({i, adj[i][j]});
        }
    }

    cout << del.size() << "\n";

    for (int i = 1; i <= n; i++)
    {

        for (int j = i + 1; j <= n; j++)
        {

            if (merge(i, j))
            {

                pair<int, int> pi = del.front();

                cout << pi.first << " " << pi.second << " " << i << " " << j << "\n";
                del.erase(del.begin());
            }
        }
    }
}