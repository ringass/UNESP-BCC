#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n, height, max = 0;

    cin >> n;

    map<int, int> towers;

    for(int i = 0; i < n; i++){
        cin >> height;

        towers[height]++;
    }

    for(auto &[height, i] : towers){

        if(i > max){
            max = i;
        }
    }

    cout << max << " " << towers.size() << endl;

    return 0;

}