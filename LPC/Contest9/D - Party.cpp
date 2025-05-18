#include <bits/stdc++.h>

#define ll long long
#define max_ 2 * 100000 + 5

using namespace std;

ll ans = 0;
ll n, a;

void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

ll solve(vector<ll> &v, ll i)
{

    if (v[i] == -1)
    {
        return 1;
    }

    return 1 + solve(v, v[i] - 1);
}

int main()
{
    fast();

    cin >> n;

    vector<ll> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    for (ll i = 0; i < n; i++)
    {

        ans = max(ans, solve(v, i));
    }

    cout << ans << endl;

    return 0;
}