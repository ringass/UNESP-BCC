#include <bits/stdc++.h>

#define ll long long
#define max_ 100001

using namespace std;

vector<ll> v[max_];
bool vis[max_];
double ans = 0.0;

void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void dfs(ll t, ll parent, double prob, ll dep)
{
    ll children = 0;

    for (auto it : v[t])
        if (it != parent)
        {
            children++;
        }

    for (auto it : v[t])
        if (it != parent)
        {

            dfs(it, t, prob/children, dep+1);
        }

    if (children == 0) {
        ans += prob*dep;
    }
}

int main()
{
    fast();

    ll n, a, b;

    cin >> n;

    for (int i = 0; i < n-1; i++)
    {
        cin >> a >> b;
        v[a].push_back(b), v[b].push_back(a);
    }

    dfs(1, 1, 1.0, 0);

    cout << fixed << setprecision(6) << ans <<endl;

    return 0;
}