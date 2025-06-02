#include <bits/stdc++.h>

using namespace std;

int getCost(const string &a, const string &b)
{
    int maxDiff = 0;
    for (size_t i = 0; i < a.size(); ++i)
    {
        maxDiff = max(maxDiff, abs(a[i] - b[i]));
    }
    return maxDiff;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<string> rows(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> rows[i];
    }

    vector<int> minDist(n, INT_MAX);
    vector<bool> visited(n, false);
    minDist[0] = 0;

    int result = 0;

    for (int i = 0; i < n; ++i)
    {
        int u = -1;
        for (int j = 0; j < n; ++j)
        {
            if (!visited[j] && (u == -1 || minDist[j] < minDist[u]))
            {
                u = j;
            }
        }
        
        visited[u] = true;
        result = max(result, minDist[u]);

        for (int v = 0; v < n; ++v)
        {
            if (!visited[v])
            {
                int cost = getCost(rows[u], rows[v]);
                if (cost < minDist[v])
                    minDist[v] = cost;
            }
        }
    }

    cout << result << endl;
    return 0;
}
