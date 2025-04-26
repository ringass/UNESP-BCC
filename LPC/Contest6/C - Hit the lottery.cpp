#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

vector<ll> bills = {100, 20, 10, 5, 1};

int main()
{

    fast();

    ll n;
    cin >> n;

    ll ans = 0;

    for (auto bill : bills)
    {
        ans += n / bill;
        n %= bill;
    }

    cout << ans << "\n";
}