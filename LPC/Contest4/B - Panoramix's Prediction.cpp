#include <bits/stdc++.h>
using namespace std;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool primo(int x) {
    if (x <= 1) return false;

    if (x == 2) return true;

    if (x % 2 == 0) return false;
    
    for (int i = 2; i*i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    fast();

    int n, m;
    cin >> n >> m;

    int ans; 

    for (int i = n+1; ; i++) {
        if (primo(i)) {
            ans = i;
            break;
        }
    }

    cout << (ans == m ? "YES" : "NO") << "\n";
    return 0;
}