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
    
    string s, t;

    cin >> s >> t;

    int n = s.size();
    int m = t.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    for(int i = 0; i <= n; ++i){ 
        dp[i][0] = i;
    
    }

    for (int j = 0; j <= m; ++j){ 
        dp[0][j] = j;
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1]; 
            }
            else
            {
                dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1});
            }
        }
    }

    cout << dp[n][m] << "\n";
}