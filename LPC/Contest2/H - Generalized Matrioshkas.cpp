#include <bits/stdc++.h>
using namespace std;

bool val(vector<int> &v) {

   stack<pair<int, int>> pilha;

    for (int num : v) {
        if (num < 0) {
            
            if (!pilha.empty() && abs(num) >= pilha.top().first) {
                return false; 
            }
            
            pilha.push({abs(num), 0});
        } else {
            if (pilha.empty() || pilha.top().first != num) {
                return false; 
            }
            
            if (pilha.top().second >= pilha.top().first) {
                return false; 
            }
            pilha.pop(); 
            
            if (!pilha.empty()) {
                pilha.top().second += num;
            }
        }
    }
    return pilha.empty(); 
}

int main() {
    string line;
    while (getline(cin, line)) {

        vector<int> v;
        int num;

        istringstream in(line);

        while (in >> num) {
            v.push_back(num);
        }

        if (val(v)) {
            cout << ":-) Matrioshka!" << endl;
        } else {
            cout << ":-( Try again." << endl;
        }
    }
    return 0;
}