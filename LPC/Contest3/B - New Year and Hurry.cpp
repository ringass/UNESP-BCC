#include <bits/stdc++.h>


using namespace std;

int main(){

    int n, k;

    cin >> n >> k;

    int time = 240 - k, tE = 0, soma = 0;

    for(int i = 1; i <= n; i++){

        soma += 5 * i;

        if(time < soma){
            break;
        }

        tE += 1;
        
    }

    cout << tE << endl;

}