#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, index;

    cin >> n >> index;

    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    long long somaIndex = 0;

    for(int i = 0; i < index; i++){
        somaIndex += arr[i];
    }

    int minE = *min_element(arr.begin(), arr.begin() + index);
    int min_Index = n;


    for(int i = index; i < n; i++){
        if(arr[i] > minE){
            min_Index = i;
            break;
        }
    }


    if(min_Index != n){

        cout << min_Index - (index - 1) << endl;

    }else{
        cout << -1 << endl;
    }

}