#include <bits/stdc++.h>

using namespace std;

const int MAX = 100005;

void fast()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

class dsu
{
public:
    vector<int> parent, size, cont, sum;

    dsu(int n)
    {
        parent.resize(n + MAX);
        size.resize(n + MAX);
        sum.resize(n + MAX);
        cont.resize(n + MAX);

        for (int i = 1, j = n + 1; i <= n; i++, j++)
        {
            parent[i] = j;
            parent[j] = j;
            cont[j] = 1;
            sum[j] = i;
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
        cont[a] += cont[b];
        sum[a] += sum[b];
        
        return size[a];
    }

    bool same(int u, int v)
    {
        return find(u) == find(v);
    }

    int get_size(int u)
    {
        return size[find(u)];
    }

    void move(int x, int y)
    {
        int a = find(x);
        int b = find(y);
        if (a != b)
        {
            ++cont[b];
            --cont[a];
            sum[b] += x;
            sum[a] -= x;
            parent[x] = b;
        }
    }
};

int main()
{
    fast();

    int n, m, cmd, p, q;

    while (cin >> n >> m)
    {

        dsu _dsu(n);

        for (int i = 0; i < m; i++)
        {

            cin >> cmd;

            if (cmd == 1)
            {
                cin >> p >> q;
                _dsu.merge(p, q);
            }
            else if (cmd == 2)
            {
                cin >> p >> q;
                _dsu.move(p, q);
            }
            else
            {
                cin >> p;

                cout << _dsu.cont[_dsu.find(p)] << " " << _dsu.sum[_dsu.find(p)] << "\n";
            }
        }
    }
}
