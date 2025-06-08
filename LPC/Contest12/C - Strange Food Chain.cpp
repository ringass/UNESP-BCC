#include <bits/stdc++.h>

using namespace std;

int n;

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

    bool same(int u, int v)
    {
        return find(u) == find(v);
    }
};

int presa(int x)
{
    return n + x;
}

int predador(int x)
{
    return x + 2 * n;
}

int main()
{
    fast();

    int t;
    cin >> t;

    while (t--)
    {
        int k;
        cin >> n >> k;

        dsu d(3 * n);

        int falsos = 0;

        for (int i = 0; i < k; i++)
        {
            int d_, x, y;
            cin >> d_ >> x >> y;

            if (x > n || y > n || (d_ == 2 && x == y))
            {
                falsos++;
                continue;
            }

            if (d_ == 1)
            {

                if (d.same(x, presa(y)) || d.same(x, predador(y)))
                {
                    falsos++;
                }
                else
                {
                    d.merge(x, y);
                    d.merge(presa(x), presa(y));
                    d.merge(predador(x), predador(y));
                }
            }
            else if (d_ == 2)
            {

                if (d.same(x, y) || d.same(x, predador(y)))
                {
                    falsos++;
                }
                else
                {
                    d.merge(x, presa(y));
                    d.merge(presa(x), predador(y));
                    d.merge(predador(x), y);
                }
            }
        }

        cout << falsos << '\n';
    }

    return 0;
}