#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool cmp(pair<int, int> x, pair<int, int> y) {
    return x.second < y.second;
}

ll solve(vector<pair<int, int>> &arr) {
    sort(arr.begin(), arr.end(), cmp);

    ll count = 0, ultimo = -1;

    for (auto p : arr) {
        if (p.first >= ultimo) {
            count++;
            ultimo = p.second;
        }
    }

    return count;
}

int main() {
    fast();

    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<pair<int, int>> att(n);

        for (ll i = 0; i < n; i++) {
            cin >> att[i].first >> att[i].second;
        }

        ll ans = solve(att);
        cout << ans << "\n";
    }

    return 0;
}
