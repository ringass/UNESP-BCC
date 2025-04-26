#include <bits/stdc++.h>

using namespace std;
#define ull unsigned long long


void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

ull solve(vector<ull> &coins, ull sum)
{
    
    int mod = 1e9 + 7;
    vector<ull> dp(sum+1, 0);

    dp[0] = 1;

    for (int j = 0; j <= sum; j++) {
        for (int i = 0; i < coins.size(); i++) {
            if (j >= coins[i]) {
                dp[j] = (dp[j] + dp[j - coins[i]]) % mod;
            }
        }
    }

    return dp[sum];
}

int main()
{
    fast();
    int n;
    ull sum;

    cin >> n >> sum;

    vector<ull> coins(n);

    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    cout << solve(coins, sum) << "\n";

    return 0;
}