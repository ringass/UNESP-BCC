#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, ans = 1;

    cin >> n >> k;

    int p;

    for (int i = 0; i < n; i++)
    {
        cin >> p;

        if (k % p == 0 && p > ans)
        {
            ans = p;
        }
    }

    cout << k / ans << endl;
    return 0;
}