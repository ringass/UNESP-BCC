#include <bits/stdc++.h>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x, i, ab;

    cin >> n >> x;

    vector<int> arr(n);
    unordered_map<int, int> hash_map;
    hash_map.reserve(n);

    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (i = 0; i < arr.size(); i++)
    {

        ab = x - arr[i];

        if (hash_map.count(ab))
        {
            cout << hash_map[ab] << " " << i + 1 << endl;
            return 0;
        }

        hash_map[arr[i]] = i + 1;
    }

    cout << "IMPOSSIBLE" << endl;
}