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
        int N;
        cin >> N;

        vector<int> arr(N);
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }

        int min_ = N;
        int max_ = 0;

        for (int i = 0; i < N; i++)
        {
            vector<bool> caixa(N, false);
            caixa[i] = true;

            bool aa;
            do
            {
                aa = false;
                for (int j = 0; j < N; j++)
                {
                    if (caixa[j])
                    {
                        for (int k = 0; k < N; k++)
                        {
                            if (!caixa[k] && abs(arr[j] - arr[k]) <= 2)
                            {
                                caixa[k] = true;
                                aa = true;
                            }
                        }
                    }
                }
            } while (aa);

            int total = count(caixa.begin(), caixa.end(), true);
            min_ = min(min_, total);
            max_ = max(max_, total);
        }

        cout << min_ << " " << max_ << "\n";
    }

    return 0;
}