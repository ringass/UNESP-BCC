#include <bits/stdc++.h>

using namespace std;

int main(){

    int x, n, i = 0;

    cin >> n >> x;

    vector<vector<int>> arr(n, vector<int>(n));

    for(i; i < n; i++){
        cin >> arr[i][0];
        arr[i][1] = i + 1;
    }

    sort(arr.begin(), arr.end());
    
    // i é o ponteiro que fica no inicio e roda no primeiro loop, b é o ponteiro que roda caso a soma de menor que o target, c é o ponteiro que faz o processo inverso do b;

    int b = 0, c = 0; 

    for(i = 0; i < n - 2; i++){

        b = i + 1;
        c = n - 1;

        while(b < c){

            int sum = arr[i][0] + arr[b][0] + arr[c][0];

            if(sum == x){
                cout << arr[i][1] << " " << arr[b][1] << " " << arr[c][1] << endl;
                return 0;
            }
            
            if(sum < x){
                b++;
            }

            if(sum > x){
                c--;
            }

        }

    }

    cout <<"IMPOSSIBLE" << endl;
}
