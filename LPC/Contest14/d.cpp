#include <bits/stdc++.h>

using namespace std;

bool solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    vector<int> b(n + 1);
    b[0] = a[0];
    for (int i = 1; i < n; ++i) {
        b[i] = (a[i-1] * a[i]) / __gcd(a[i-1], a[i]);
    }
    b[n] = a[n-1];
    
    for (int i = 0; i < n; ++i) {
        if (__gcd(b[i], b[i+1]) != a[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        cout << (solve() ? "YES" : "NO") << '\n';
    }
    
    return 0;
}