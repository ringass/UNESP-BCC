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

    int get_size(int u)
    {
        return size[find(u)];
    }
};

int main()
{
    fast();

    int t;
    cin >> t;

    for (int k = 1; k <= t; k++)
    {
        string s;
        cin >> s;

        int q;
        cin >> q;

        dsu d(s.size());

        vector<pair<int, char>> v;

        for (int i = 0; i < q; i++)
        {
            int x, y;
            cin >> x >> y;

            if (x == 2)
            {
                v.push_back({y, s[y]});
                s[y] = '#';
            }
            else
            {
                v.push_back({y, '0'});
            }
        }

        for (int i = 0; i < s.size() - 1; i++)
        {
            if (s[i] == '#' || s[i + 1] == '#')
                continue;

            if (s[i] == s[i + 1])
                d.merge(i, i + 1);
        }

        vector<int> result;

        for (int i = v.size() - 1; i >= 0; i--)
        {
            int x = v[i].first;
            char ch = v[i].second;

            if (ch == '0')

            {
                result.push_back(d.get_size(x));
            }
            else
            {
                s[x] = ch;

                if (x + 1 < s.size() && s[x + 1] != '#' && s[x + 1] == s[x])
                    d.merge(x, x + 1);

                if (x - 1 >= 0 && s[x - 1] != '#' && s[x - 1] == s[x])
                    d.merge(x, x - 1);
            }
        }

        reverse(result.begin(), result.end());

        cout << "Case " << k << ":\n";
        for (int ans : result)
        {
            cout << ans << "\n";
        }
    }
}
