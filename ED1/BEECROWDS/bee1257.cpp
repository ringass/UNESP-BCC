#include <iostream>

using namespace std;

int main(){
    string str;
    int n, l, hash;

    cin >> n;

    for(int k = 0; k < n; ++k){
        hash = 0;
        cin >> l;

        for(int i = 0; i < l; ++i){
            cin >> str;

            for(int j = 0; j < str.length(); ++j){
                hash += (str[j] - 'A') + i + j;
            }
        }

        cout << hash << endl;
    }

    return 0;
}