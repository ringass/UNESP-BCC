#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;

    cin >> n;

    vector<int> pedras(n);

    int all = 0;

    for (int i = 0; i < n; i++)
    {

        cin >> pedras[i];
        all += pedras[i];
    }

    int diff = 100000;

    for (int i = 0; i < (1 << n); i++)
    {

        int soma = 0;

        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                soma += pedras[j];
            }
        }

        int pp = abs(all - 2 * soma);

        if (pp < diff)
        {
            diff = pp;
        }
    }

    cout << diff << endl;
    return 0;
}
