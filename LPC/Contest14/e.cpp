#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void solve() {
    int T;
    cin >> T;
    while (T--) {
        long long r, b, k;
        cin >> r >> b >> k;
        if (r == b) {
            cout << "OBEY" << endl;
            continue;
        }
        if (r > b) {
            swap(r, b);
        }
        long long g = gcd(r, b);
        long long L = r * b / g;
        long long max_r = (L / b) - 1;
        long long max_b = (L / r) - 1;
        if ((b - g + r - 1) / r >= k) {
            cout << "REBEL" << endl;
        } else {
            cout << "OBEY" << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}