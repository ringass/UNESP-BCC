#include <bits/stdc++.h>
using namespace std;

struct e
{
    int u;
    int v;
    int w;
};
typedef struct e Edge;

struct sub
{
    int p;
    int r;
};
typedef struct sub Subset;

Subset subs[100001];
Edge edgs[200001];

void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int log2(long long val)
{
    int res = -1;
    while (val)
    {
        val >>= 1;
        res++;
    }
    return res;
}

int find(int x)
{
    if (subs[x].p != x)
        subs[x].p = find(subs[x].p);
    return subs[x].p;
}

void _union(int a, int b)
{
    int ra = find(a);
    int rb = find(b);
    if (subs[ra].r < subs[rb].r)
    {
        subs[ra].p = rb;
    }
    else if (subs[rb].r < subs[ra].r)
    {
        subs[rb].p = ra;
    }
    else
    {
        subs[rb].p = ra;
        subs[ra].r++;
    }
}

bool cmp(Edge x, Edge y)
{
    return x.w < y.w;
}

int main()
{   

    fast();

    int t, n, m, i, cnt;

    cin >> t;

    while (t--)
    {

        cin >> n >> m;

        for (i = 1; i <= m; i++)
        {
            long long temp;
            
            cin >> edgs[i].u >> edgs[i].v;
            cin >> temp;

            edgs[i].w = log2(temp);
        }

        for (i = 1; i <= n; i++)
        {
            subs[i].p = i;
            subs[i].r = 0;
        }

        sort(edgs + 1, edgs + m + 1, cmp);

        cnt = 0;
        i = 1;
        int cost = 0;

        while (cnt < n - 1)
        {
            Edge e = edgs[i++];
            int r1 = find(e.u);
            int r2 = find(e.v);
            if (r1 != r2)
            {
                cnt++;
                cost += e.w;
                _union(r1, r2);
            }
        }

        cout << cost+1 << "\n";
    }
    return 0;
}