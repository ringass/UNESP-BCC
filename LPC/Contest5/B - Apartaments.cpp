#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    fast();

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> applicant(n);
    vector<int> apartments(m);

    for (int i = 0; i < n; i++)
    {
        cin >> applicant[i];
    }

    for (int i = 0; i < m; i++) 
    {
        cin >> apartments[i];
    }

    sort(applicant.begin(), applicant.end());
    sort(apartments.begin(), apartments.end());

    int count = 0;
    int i = 0, j = 0;

    while (i < n && j < m)
    {
        while (j < m && apartments[j] < applicant[i] - k)
        {
            j++;
        }

        if (j < m && abs(apartments[j] - applicant[i]) <= k)
        {
            count++;
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }

    cout << count << "\n";
}
