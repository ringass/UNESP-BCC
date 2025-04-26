#include <bits/stdc++.h>

using namespace std;

void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{

    int n, it = 0;

    cin >> n;

    while (n != 0)
    {

        int sub = 0, t = n;

        while (t > 0)
        {
            sub = max(sub, t % 10);
            t /= 10;
        }

        n -= t;
        it++;
    }

    cout << it << "\n";
}