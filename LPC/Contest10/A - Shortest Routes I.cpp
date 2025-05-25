#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll INF = LLONG_MAX;

vector<vector<pair<ll, ll>>> adj(100005);
vector<bool> vis(100005, false);
vector<ll> dis(100005, INF);

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve() {
    ll n, m;
    cin >> n >> m;

    for(ll i = 0; i < m; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    dis[1] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    q.push({0, 1});

    while (!q.empty()) {
        ll u = q.top().second;
        q.pop();
        if (vis[u]) continue;
        vis[u] = true;

        for (auto &[v, w] : adj[u]) {
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push({dis[v], v});
            }
        }
    }

    for (ll i = 1; i <= n; ++i) {
        cout << dis[i] << " ";
    }
    cout << '\n';
}

int main() {
    fast();
    solve();
    return 0;
}
