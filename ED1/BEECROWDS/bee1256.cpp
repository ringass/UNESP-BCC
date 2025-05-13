#include <bits/stdc++.h>

using namespace std;

int Hashfunc(int val, int m)
{
    return val % m;
}

int main()
{
    int n, m, c, num;
    vector<list<int>> Hashtable;

    cin >> n;

    for (int k = 0; k < n; ++k)
    {
        if (k)
            cout << endl;

        cin >> m >> c;

        Hashtable.assign(m, list<int>());

        for (int i = 0; i < c; ++i)
        {
            cin >> num;

            Hashtable[Hashfunc(num, m)].push_back(num);
        }

        for (int i = 0; i < m; ++i)
        {
            cout << i << " -> ";


            for (const int &num : Hashtable[i])
            {
                cout << num << " -> ";
            }

            cout << "\\" << endl;
        }

        return 0;
    }