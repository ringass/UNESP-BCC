#include <bits/stdc++.h>
using namespace std;

#define ll long long


ll exp(ll x, ll n, ll m) {
    assert(n >= 0);
    x %= m;
    ll res = 1;
    while (n > 0) {
        if (n % 2 == 1) res = res * x % m;
        x = x * x % m;
        n /= 2;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        ll a, b, c;
        cin >> a >> b >> c;

        ll pp = exp(b, c, 1e9 + 7 - 1);  
        ll ans = exp(a, pp, 1e9 + 7); 

        cout << ans << "\n";
    }

    return 0;
}
