#include <bits/stdc++.h>

using namespace std;

void fast()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main()
{

    fast();
    
    int n;

    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(3, INT_MAX));

    dp[0][0] = 0;

    for (int i = 1; i <= n; i++)
    {

        int var = a[i - 1];

        dp[i][0] = min({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + 1;

        
        if (var== 1 || var== 3)
        {
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]); 
        }

        
        if (var== 2 || var== 3)
        {
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]); 
        }
    }

    cout << min({dp[n][0], dp[n][1], dp[n][2]}) << endl;
}