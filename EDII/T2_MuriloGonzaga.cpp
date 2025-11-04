#include <bits/stdc++.h>

using namespace std;

void fast(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int bfs_kahns(int N, vector<vector<int>>& adj, vector<int>& inDegree){ //baseando-se no kahns algorithm de sort topológico com depedencias
    int fullTime = 0;
    queue<int> q;
    vector<int> time(N+1, 0);

    for(int i = 1; i <= N; i++){
        if(inDegree[i] == 0){
            q.push(i);
            time[i] = 1;
        }
    }

    int compiledArq = 0;
    
    while(!q.empty()){
        int u = q.front();
        q.pop();

        compiledArq++;
        fullTime = max(fullTime, time[u]);

        for(int v : adj[u]){
            time[v] = max(time[v], time[u] + 1);
            inDegree[v]--; //tirando a dependencia
            if (inDegree[v] == 0)
                q.push(v);
        }  
    }

    cout << "\n";
    
    for(auto a : time){
        cout << a << " ";
    }

    if(compiledArq == N){
        return fullTime;
    }else{
        return -1;
    }
}

int main(){
    fast();

    int N;

    while (cin >> N){
        vector<vector<int>> adj(N + 1);

        vector<int> inDegree(N+1, 0); //contagem de dependencias por arquivo

        for(int i = 1; i <= N; i++){
            int Mi; //qtd de dependencias
            cin >> Mi;
            for(int j = 0; j < Mi; j++){
                int arq_dep;
                cin >> arq_dep;
                inDegree[i]++; //atribuindo a dependencia do arq_dep ao arquivo i
                adj[arq_dep].push_back(i);
            }
        }

        cout << bfs_kahns(N, adj, inDegree) << "\n";    
    }
    return 0;
}