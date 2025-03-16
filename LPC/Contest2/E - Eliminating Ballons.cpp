#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;

    cin >> n;
    vector<int> baloon(n);
    unordered_map<int, int> arrows;

    for (int i = 0; i < n; i++)
    {
        cin >> baloon[i];
    }

    arrows.reserve(n);
    
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        int height = baloon[i];

        if (arrows[height] > 0)
        {
            arrows[height]--;
            arrows[height - 1]++;
        }
        else
        {
            count++;
            arrows[height - 1]++;
        }
    }

    cout << count << "\n";

    return 0;
}
