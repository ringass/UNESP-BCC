#include <bits/stdc++.h>
using namespace std;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main() {
    fast();

    int n, q;
    cin >> n >> q;

    vector<int> vet(n);
    for (int i = 0; i < n; i++) {
        cin >> vet[i];
    }

    int x;
    while (q--) {
        cin >> x;
        auto j = lower_bound(vet.begin(), vet.end(), x);
        if (j != vet.end() && *j == x) {
            cout << (j - vet.begin()) << '\n';
        } else {
            cout << "-1\n";
        }
    }

    return 0;
}