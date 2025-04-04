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

    int T;
    cin >> T;

    while (T--)
    {
        vector<int> a = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> n(10);
        int K;
        bool ans = false;

        for (int i = 0; i < 10; i++)
        {
            cin >> n[i];
        }

        cin >> K;

        do
        {
            int aa = 0;

            for (int i = 0; i < 10; i++)
            {
                aa += a[i]*n[i];
            }

            if (aa <= K)
            {
                ans = true;
                for (int i = 0; i < 10; i++)
                {
                    cout << a[i] << " ";
                }
                break;
            }
        } while (next_permutation(a.begin(), a.end()));

        if (!ans)
        {
            cout << -1;
        }

        cout << "\n";
    }
    return 0;
}