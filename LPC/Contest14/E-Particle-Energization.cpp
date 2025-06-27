#include <bits/stdc++.h>

using namespace std;

void fast()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{

    fast();

    int y, k;
    long long int ans = 1;

    cin >> y >> k;

    vector<int> v;

    for (int i = 2; i * i <= y; i++)
    {
        while (y % i == 0)
        {
            v.push_back(i);
            y /= i;
        }
    }

    if (y > 1)
    {
        v.push_back(y);
    }

    for (auto i : v)
    {
        if (k <= i - 1)
        {
            ans *= k + 1;
            k = 0;
            break;
        }
        else
        {
            ans *= i;
            k -= i - 1;
        }
    }

    ans *= k + 1;

    cout << ans << '\n';
}