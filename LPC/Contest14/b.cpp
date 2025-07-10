#include <bits/stdc++.h>

using namespace std;

const int MAX_A = 200000;

vector<int> spf;

void sieve() {
    spf.resize(MAX_A + 1);
    for (int i = 1; i <= MAX_A; ++i) {
        spf[i] = i;
    }
    for (int i = 2; i * i <= MAX_A; ++i) {
        if (spf[i] == i) {
            for (int j = i * i; j <= MAX_A; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

vector<int> get_prime_factors(int x) {
    vector<int> factors;
    while (x > 1) {
        int p = spf[x];
        while (x % p == 0) {
            x /= p;
        }
        factors.push_back(p);
    }
    return factors;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve();

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    map<int, vector<int>> prime_exponents;
    for (int num : a) {
        map<int, int> factors;
        int x = num;
        while (x > 1) {
            int p = spf[x];
            int cnt = 0;
            while (x % p == 0) {
                x /= p;
                cnt++;
            }
            factors[p] = cnt;
        }
        for (auto &[p, cnt] : factors) {
            prime_exponents[p].push_back(cnt);
        }
    }

    long long result = 1;
    for (auto &[p, exponents] : prime_exponents) {
        if (exponents.size() >= n - 1) {
            sort(exponents.begin(), exponents.end());
            int power = exponents.size() >= n ? exponents[1] : exponents[0];
            for (int i = 0; i < power; ++i) {
                result *= p;
            }
        }
    }

    cout << result << '\n';

    return 0;
}