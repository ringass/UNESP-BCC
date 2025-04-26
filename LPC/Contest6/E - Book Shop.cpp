#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int solve(int k, vector<ull>& h, vector<ull>& s){

    vector<ull> dp(k + 1, 0);

    for(int i = 0; i < h.size(); i++){
        for(int j = k; j >= h[i]; j--){
            dp[j] = max(dp[j], dp[j - h[i]] + s[i]); 
        }
    }

    return dp[k];
}

int main() {

    int n, k;

    cin >> n >> k;

    vector<ull> h(n), s(n);

    for(int i = 0; i < n; i++){
        cin >> h[i];
    }

    for(int i = 0; i < n; i++){
        cin >> s[i];
    }

    cout << solve(k, h, s) << "\n";
    
}