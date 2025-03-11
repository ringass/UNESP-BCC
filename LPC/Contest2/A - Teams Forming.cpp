#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    
    cin >> n;
    int arr[5+n];
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    sort(arr, arr+n);
    
    int ans = 0, diff = 0;
    
    for(int i = 0; i < n; i+=2){
        if(arr[i] != arr[i+1]){
            ans += abs(arr[i] - arr[i+1]);             
        }
    }
    
    cout << ans << endl;
    
}
