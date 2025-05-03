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
    
    long long n;

    cin >> n;

    vector<long long> a(n);

    for (long long i = 0; i < n; i++)
    {

        cin >> a[i];
    }

    vector<vector<long long>> dp(n, vector<long long>(n, 0));

    for (long long i = 1; i <= n; i++)
    {

        for (long long left = 0; left + i - 1 < n; left++)
        {

            long long right = left + i - 1;

            if (right == left)
            {
                dp[left][right] = a[left];
            }
            else
            {
                dp[left][right] = max(a[left] - dp[left + 1][right], a[right] - dp[left][right - 1]);
            }
        }
    }

    cout << dp[0][n - 1] << '\n';
}