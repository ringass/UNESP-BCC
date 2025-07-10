#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    
    int n;
    int k;
    cin >> n >> k;
    
    unordered_set<int> vet;

    int count = 0;

    for (int i = 0; i < n; i++) {
        int bo;
        cin >> bo;
        vet.insert(bo);
    }

    for (int i : vet) {
        if (vet.count(i + k)) {
            count++;
        }
    }

    cout << count << "\n";
    return 0;
}
