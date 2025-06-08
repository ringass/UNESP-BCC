#include <bits/stdc++.h>

using namespace std;

vector<int> p, size_c;
int s;

void fast()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void dfs(int i, int j)
{

    s++;

    if (p[i] == j)
    {
        size_c[i] = s;
        return;
    }
    else
    {
        dfs(p[i], j);
        size_c[i] = s;
    }
}

int main()
{

    fast();

    int T;

    cin >> T;

    while (T--)
    {

        int n;

        cin >> n;

        p.assign(n + 1, 0);
        size_c.assign(n + 1, 0);

        s = 0;

        for (int i = 1; i <= n; i++)
        {
            cin >> p[i];

            size_c[i] = 0;
        }

        for (int i = 1; i <= n; i++)
        {
            if (size_c[i] == 0)
            {
                s = 0;

                dfs(i, i);
            }
        }

        for (int i = 1; i < n; i++)
        {
            cout << size_c[i] << " ";
        }

        cout << size_c[n] << "\n";
    }
}