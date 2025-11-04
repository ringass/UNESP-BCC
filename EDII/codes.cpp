#include <bits/stdc++.h>

using namespace std;

void bfs(vector<vector<int>>& adj, int src){

    int V = adj.size();

    vector<bool> visited(V, false);
    queue<int> q;
    vector<int> caminho(V);

    visited[src] = true;
    q.push(src);

    while(!q.empty()){
        auto x = q.front();
        q.pop();

        for(auto v : adj[x]){
            if(!visited[v]){
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int prim(vector<vector<pair<int, int>>>& adj){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int V = adj.size();
    vector<bool> visited(V, false);
    int res = 0;

    pq.push({0, 0});

    while(!pq.empty()){
        auto [peso, x] = pq.top();
        pq.pop();

        if(visited[x]) continue;

        res+=peso;
        visited[x] = true;

        for(auto[v, w] : adj[x]){
            if(!visited[v]){
                pq.push({w,v});
            }
        }

    }

    return res;

}

vector<int> dijkstra(vector<vector<pair<int,int>>> adj, int src){
    int V = adj.size();
    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, 1e8);
    pq.push({0, src});
    dist[src] = 0;

    while(!pq.empty()){
        auto u = pq.top().second;
        pq.pop();

        for(auto x : adj[u]){
            auto [v, wt] = x;

            if(dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt;
                pq.push({dist[v], v});
            }
        }
    }

return dist;
}


int main(){

}