#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define median_q -1

void fast()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}


int URSS(vector<int> &arr, int n){

    vector<int> ordenado; 
    int p = 0, count = 0;
    ordenado.push_back(arr[p]);

    for(int i = 1; i < n; i++){

        if(arr[i] >= ordenado[p]){
            
            ordenado.push_back(arr[i]);
            p++;
            count++;
        }
    }

    return count;
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

        vector<int> arr(n);

        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        cout << URSS(arr, n) << "\n";

    }
}
