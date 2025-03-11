#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, x, i = 0, ans = 0, a = 0, b = 0, temp = 0;

    cin >> n >> x;

    vector<int> arr(n);

    for(i = 0; i < n; i++){
        cin >> arr[i];
    }

    for(a; a < n; a++){

        temp += arr[a];

        while(temp > x){
            temp -= arr[b];
            b++;
        }

        if(temp == x){
            ans++;
        }
    }

    cout << ans << endl;
}