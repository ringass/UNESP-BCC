#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    int direcao_atual = -1; 
    int time_count = 0;     

    for (int i = 0; i < n; i++) {
        int tC = arr[i].first;
        int new_direcao = arr[i].second;

        if (direcao_atual == -1) {
            
            direcao_atual = new_direcao;
            time_count = tC + 10;
        } else if (new_direcao == direcao_atual) {
            
            if (tC <= time_count) {
                
                time_count = tC + 10;
            } else {
                
                direcao_atual = new_direcao;
                time_count = tC + 10;
            }
        } else {
            
            if (tC >= time_count) {
                
                direcao_atual = new_direcao;
                time_count = tC + 10;
            } else {
                
                time_count = time_count + 10;
                direcao_atual = new_direcao;
            }
        }
    }

    cout << time_count << "\n";

    return 0;
}