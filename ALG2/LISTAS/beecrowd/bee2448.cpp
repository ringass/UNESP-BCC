#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int main(){

    int n_casas, n_encomendas, temp = 0, pos = 0, novapos = 0;

    cin >> n_casas >> n_encomendas;

    vector<int> casas(n_casas), encomendas(n_encomendas);
    map<int, int> mapa_casas;

    for(int i = 0; i < n_casas; i++){
        cin >> casas[i];
        mapa_casas[casas[i]] = i;
    }

    for(int i = 0; i < n_encomendas; i++){
        cin >> encomendas[i];
    }

    for(int i = 0; i < n_encomendas; i++){
        novapos = mapa_casas[encomendas[i]];
        temp += abs(pos-novapos);
        pos = novapos;
    }

    cout << temp << endl;
}