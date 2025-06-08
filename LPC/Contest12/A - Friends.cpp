#include <bits/stdc++.h>

using namespace std;

void fast()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

class dsu
{
    vector<int> parent, size;

public:
    dsu(int n)
    {

        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
        }
    }

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
            return size[a];
        }

        if (size[a] < size[b])
        {
            swap(a, b);
        }

        parent[b] = a;
        size[a] += size[b];

        return size[a];
    }
};

int main()
{

    fast();

    int T;
    cin >> T;

    while (T--)
    {
        int N, M;

        cin >> N >> M;

        dsu dsu_(N);

        int _max = 1;

        for (int i = 0; i < M; i++)
        {
            int A, B;

            cin >> A >> B;

            _max = max(_max, dsu_.merge(A, B));
        }

        cout << _max << "\n";
    }
}