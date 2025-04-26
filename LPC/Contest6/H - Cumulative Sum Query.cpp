#include <bits/stdc++.h>

using namespace std;

void fast(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

vector<int> prefixSum(vector<int>& vet){

    for(unsigned int i = 1; i < vet.size(); i++){
        
        vet[i] = vet[i - 1] + vet[i];
    }

    return vet;
}


int main(){

    fast();

    int n, qt;

    cin >> n;

    vector<int> vet(n);

    for(int i = 0; i < n; i++){
        cin >> vet[i];
    }

    vet = prefixSum(vet);

    cin >> qt;

    int ans = 0;

    while(qt--){

        int i, j;

        cin >> i >> j;

        if(i > 0){
            ans = vet[j] - vet[i-1];
        }else{
            ans = vet[j];
        }
        
        cout << ans << "\n";
    }

}