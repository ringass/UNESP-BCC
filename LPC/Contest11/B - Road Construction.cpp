#include <bits/stdc++.h>

using namespace std;


void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int get(int x, vector<int> &v)  
{
    return (v[x] < 0 ? x : v[x] = get(v[x], v));
}

bool unite(int x, int y, vector<int> &v)  
{
    x = get(x, v);
    y = get(y, v);

    if (x == y)
    {
        return 0;
    }
    if (v[x] > v[y])
    {
        swap(x, y);
    }

    v[x] += v[y];
    v[y] = x;

    return 1;
}

int size(int x, vector<int> &v)  
{
    return -v[get(x, v)];
}

int main()
{   

    fast();

    int n, m;

    cin >> n >> m;

    vector<int> v;

    v = vector<int>(n, -1);

    int cc = n, large = 1;

    while (m--)
    {
        int x, y;
        cin >> x >> y;
        
        x--;
        y--;

        if (unite(x, y, v))
        {
            large = max(large, size(x, v));
            cc--;
        }
        cout << cc << ' ' << large << '\n';
    }
}