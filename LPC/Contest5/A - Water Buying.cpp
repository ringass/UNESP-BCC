#include <bits/stdc++.h>

using namespace std;

void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    int q, a, b;

    cin >> q;

    while (q--)
    {
        long long n, ans = 0;

        cin >> n >> a >> b;

        if (a * 2 < b)
        {

            ans = n * a;
        }
        else
        {

            long long mod = n % 2;
            ans = (n / 2) * b + (mod * a);
        }
        cout << ans << "\n";
    }
    return 0;
}