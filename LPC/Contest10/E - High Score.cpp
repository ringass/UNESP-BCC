#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll INF = 1e18;
ll n, m;
vector<vector<ll>> G, RG;
vector<tuple<ll, ll, ll>> adj;
vector<bool> vis1, vis2;

void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void dfsG(ll u){

    vis1[u] = true;

    for(ll v : G[u]){

        if(!vis1[v]){
            dfsG(v);
        }
    }
}


void dfsRG(ll u){

    vis2[u] = true;

    for(ll v : RG[u]){

        if(!vis2[v]){
            dfsRG(v);
        }
    }
}


int main()
{
    fast();
    cin >> n >> m;

    G.resize(n + 1);
    RG.resize(n + 1);

    vis1.resize(n+1, false);
    vis2.resize(n+1, false);


    vector<ll> dist(n + 1, INF);
    ll u, v, w;

    for (ll i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        adj.push_back({u, v, -w});
        G[u].push_back(v);
        RG[v].push_back(u);
    }

    dist[1] = 0;

    for (int i = 1; i < n; i++) {
        for (auto [u, v, w] : adj) {

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;

            }
        }
    }

    dfsG(1);
    dfsRG(n);

    for (auto [u, v, w] : adj) {

        if (dist[u] + w < dist[v]) {

            if (vis1[v] && vis2[v]) {

                cout << -1 << endl;
                return 0;

            }
        }
    }
    
    cout << -dist[n] << endl;
    return 0;
}
