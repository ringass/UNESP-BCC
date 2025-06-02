#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w, id;
    bool operator<(const Edge &o) const { return w < o.w; }
};

int N, R, Q;
vector<Edge> edges;
vector<vector<pair<int,int>>> adj; 

int parent[100005], depth[100005], maxEdge[100005][20], up[100005][20];


int uf_parent[100005];
int uf_find(int a) {
    if (uf_parent[a] == a) return a;
    return uf_parent[a] = uf_find(uf_parent[a]);
}
bool uf_union(int a, int b) {
    a = uf_find(a); b = uf_find(b);
    if (a == b) return false;
    uf_parent[b] = a;
    return true;
}

void dfs(int u, int p, int d, int w) {
    parent[u] = p;
    depth[u] = d;
    up[u][0] = p;
    maxEdge[u][0] = w;
    for (int i=1; i<20; i++) {
        up[u][i] = up[up[u][i-1]][i-1];
        maxEdge[u][i] = max(maxEdge[u][i-1], maxEdge[up[u][i-1]][i-1]);
    }
    for (auto &e : adj[u]) {
        if (e.first != p) dfs(e.first, u, d+1, e.second);
    }
}

int getMaxEdge(int u, int v) {
    if (depth[u] < depth[v]) swap(u,v);
    int res = 0;
    int diff = depth[u] - depth[v];
    for (int i=0; i<20; i++) {
        if (diff & (1 << i)) {
            res = max(res, maxEdge[u][i]);
            u = up[u][i];
        }
    }
    if (u == v) return res;
    for (int i=19; i>=0; i--) {
        if (up[u][i] != up[v][i]) {
            res = max(res, maxEdge[u][i]);
            res = max(res, maxEdge[v][i]);
            u = up[u][i];
            v = up[v][i];
        }
    }
    res = max(res, maxEdge[u][0]);
    res = max(res, maxEdge[v][0]);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> R;
    edges.resize(R);
    for (int i=0; i<R; i++) {
        int A,B,C;
        cin >> A >> B >> C;
        edges[i] = {A, B, C, i};
    }

    
    for (int i=1; i<=N; i++) uf_parent[i] = i;

    sort(edges.begin(), edges.end());

    vector<bool> inMST(R, false);
    adj.resize(N+1);

    long long mstCost = 0;

    
    for (auto &e : edges) {
        if (uf_union(e.u, e.v)) {
            mstCost += e.w;
            inMST[e.id] = true;
            adj[e.u].push_back({e.v, e.w});
            adj[e.v].push_back({e.u, e.w});
        }
    }

    
    parent[1] = 1;
    depth[1] = 0;
    dfs(1,1,0,0);

    cin >> Q;
    while (Q--) {
        int U, V;
        cin >> U >> V;
        
        int edgeIndex = -1;
        
        for (int i=0; i<R; i++) {
            if ((edges[i].u == U && edges[i].v == V) || (edges[i].u == V && edges[i].v == U)) {
                edgeIndex = i;
                break;
            }
        }
        if (edgeIndex == -1) {
            cout << mstCost << "\n"; 
            continue;
        }
        if (inMST[edgeIndex]) {
            cout << mstCost << "\n"; 
        } else {
            int u = edges[edgeIndex].u;
            int v = edges[edgeIndex].v;
            int w = edges[edgeIndex].w;
            int maxE = getMaxEdge(u, v);
            cout << mstCost - maxE + w << "\n";
        }
    }

    return 0;
}
