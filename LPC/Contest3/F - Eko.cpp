#include <bits/stdc++.h>
#define ll long long

using namespace std;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}


bool verifica(const vector<int>& arv, ll m, ll altura, ll n)
{

    ll soma = 0;

    for(int i = 0; i < n; i++){
        if(arv[i] > altura){
            soma += arv[i] - altura;
        }
    }

    return (soma >= m);

}

int main()
{


    fast();

    ll n, m;

    cin >> n >> m;

    vector<int> arv(n);

    for (ll i = 0; i < n; i++)
    {

        cin >> arv[i];
    }

    sort(arv.begin(), arv.end());

    ll ans = 0;
    ll dir = arv.back();
    ll esq = 0;


    while(esq <= dir){
        ll meio = (esq+dir)/2;
        

        if(verifica(arv, m, meio, n)){
            ans = meio;
            esq = meio + 1;
        }else{
            dir = meio - 1;
        }

    }

    cout << ans << '\n';
    
}