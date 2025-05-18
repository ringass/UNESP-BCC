#include <bits/stdc++.h>

#define ll long long
#define max_ 10005

using namespace std;

vector<ll> v[max_];
bool vis[max_];

void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void dfs(ll t)
{
    vis[t] = true;

    for (auto it : v[t])
        if (!vis[it])
        {

            dfs(it);
        }
}

int main()
{
    fast();

    ll n, m, a, b;

    cin >> n >> m;

    if (m != n - 1) {
        cout << "NO" << endl;
        return 0;
    }

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        v[a].push_back(b), v[b].push_back(a);
    }

    dfs(1);

    for (int i = 1; i <= n; ++i)
    {
        if (!vis[i])
        {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    return 0;
}