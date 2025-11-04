#include <bits/stdc++.h>

using namespace std;

void fast(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int reverse(int n){
    int r = 0;
    while(n > 0){
        r = r * 10 + (n % 10);
        n /= 10;
    }
    return r;
}

int bfs(int A, int B){
    vector<bool> visited(10000, false);
    queue<pair<int,int>> q;


    q.push({A, 0});
    visited[A] = true;

    while(!q.empty()){
        auto [num, steps] = q.front();
        q.pop();

        if(num == B) return steps;

        int inv = reverse(num);
        if(inv < 10000 && !visited[inv]){
            visited[inv] = true;
            q.push({inv, steps + 1});
        }

        int added = num + 1;
        if(added < 10000 && !visited[added]){
            visited[added] = true;
            q.push({added, steps + 1});
        }
    }

    return -1;
}

int main(){
    fast();

    int A, B, T;
    cin >> T;

    while(T--){
        cin >> A >> B;
        cout << bfs(A,B) << "\n";
    }
    
    return 0;
}