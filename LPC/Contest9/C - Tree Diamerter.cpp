#include <bits/stdc++.h>

#define ll long long
#define max_ 2 * 100000 + 5

using namespace std;

vector<ll> v[max_];
bool vis[max_];
ll count_ = 1;
ll max_dist = 0;

void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

ll dfs(ll t, ll dist)
{
    vis[t] = true;

    if (dist > max_dist)
    {
        max_dist = dist;
        count_ = t;
    }

    for (auto it : v[t])
        if (!vis[it])
        {

            dfs(it, dist + 1);
        }

    return count_;
}

int main()
{
    fast();

    ll n, a, b;

    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        v[a].push_back(b), v[b].push_back(a);
    }

    dfs(1, 0);

    fill(begin(vis), end(vis), false);
    max_dist = 0;

    dfs(count_, 0);

    cout << max_dist << endl;

    return 0;
}