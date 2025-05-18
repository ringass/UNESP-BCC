#include <bits/stdc++.h>

#define ll long long
#define max_ 100006

using namespace std;

vector<ll> v[max_];
bool vis[max_];
ll count_ = 1;

void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

ll dfs(ll t)
{
    vis[t] = 1;
    for (auto it : v[t])
        if (!vis[it])
        {
            count_++;

            dfs(it);
        }
    return count_;
}

int main()
{
    fast();

    ll m, n, x, y;

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        v[x].push_back(y), v[y].push_back(x);
    }

    dfs(1);

    if (n == m && n == count_)
    {

        cout << "FHTAGN!" << endl;
    }

    else
    {
        cout << "NO" << endl;
    }

    return 0;
}