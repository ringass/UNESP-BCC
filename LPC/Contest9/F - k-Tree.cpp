#include <bits/stdc++.h>

#define max_ 110
const int mod = 1e9 + 7;

using namespace std;

int dp1[max_], dp2[max_], ps1[max_], ps2[max_];
int ans;

void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main()
{
    fast();

    int n, k, d;

    cin >> n >> k >> d;

    dp2[0] = dp1[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        ps1[i] = (ps1[i - 1] + dp1[i - 1]) % mod;

        int l = max(0, i - k), r = i;

        dp1[i] = (ps1[r] - ps1[l] + mod) % mod;
    }

    for (int i = 1; i <= n; i++)
    {
        ps2[i] = (ps2[i - 1] + dp2[i - 1]) % mod;

        int l = max(0, i - (d - 1)), r = i;

        dp2[i] = (ps2[r] - ps2[l] + mod) % mod;
    }

    ans = (dp1[n] - dp2[n] + mod) % mod;

    cout << ans << endl;

    return 0;
}