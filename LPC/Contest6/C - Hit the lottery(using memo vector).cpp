#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

vector<ll> bills = {1, 5, 10, 20, 100};

ll min_bills(ll n, vector<ll> &memo)
{
    if (memo[n] != -1)
    {
        return memo[n];
    }

    if (n == 0)
    {
        return memo[0] = 0;
    }

    ll val = 1e17;

    for (auto aaa : bills)
    {

        if (n - aaa < 0)
        {
            continue;
        }

        val = min(min_bills(n - aaa, memo) + 1, val);
    }

    memo[n] = val;

    return memo[n];
}

int main()
{

    int n;
    cin >> n;

    vector<ll> memo(n + 1, -1);


    cout << min_bills(n, memo) << "\n";
}