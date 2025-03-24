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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int h = 0;
        for (int i = 1;; ++i)
        {
            int sum = i * (i + 1) / 2;
            if (sum <= n)
            {
                h = i;
            }
            else
            {
                break;
            }
        }
        cout << h << endl;
    }
}