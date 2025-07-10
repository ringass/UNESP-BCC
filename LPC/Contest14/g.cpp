#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long t;
    cin >> t;

    while (t--) {
        long long n, a, b;
        cin >> n >> a >> b;

        long long g = __gcd(a, b);

        vector<long long> arr(n + 1);

        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            arr[i] = arr[i] % g;
        }

        sort(arr.begin() + 1, arr.begin() + n + 1);

        long long min_diff = arr[n] - arr[1];

        for (int i = 1; i <= n - 1; i++) {
            long long cost = arr[i] + g - arr[i + 1];
            min_diff = min(min_diff, cost);
        }

        cout << min_diff << "\n";
    }

    return 0;
}
