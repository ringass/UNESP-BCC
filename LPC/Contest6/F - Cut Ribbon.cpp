#include <bits/stdc++.h>
#define ll long long

using namespace std;

void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// problema do tung tung tung tung sahur fuck this shit off

int solve(vector<ll> &fita, int target)
{
    vector<ll> dp(target + 1, -10000000);
    dp[0] = 0;

    for (int j = 1; j <= target; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            if (j >= fita[i])
            {
                dp[j] = max(dp[j], 1 + dp[j - fita[i]]);
            }
        }
    }
    return dp[target];
}

int main()
{
    fast();

    int n;

    cin >> n;

    vector<ll> fita(3);

    for (int i = 0; i < 3; i++)
    {

        cin >> fita[i];
    }

    cout << solve(fita, n) << "\n";
}
