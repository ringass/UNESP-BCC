#include <bits/stdc++.h>
using namespace std;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main() {

    int n, q;

    cin >> n >> q;

    vector<int> arr(n);
    unordered_map<int, vector<int>> map;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        map[arr[i]].push_back(i+1);
    }

    while(q--){
        int x, k;
        cin >> x >> k;

        if(map.find(x) == map.end() || map[x].size() < k){
            cout << "-1\n";
        }else{
            cout << map[x][k - 1] << '\n';
        }
    }

}