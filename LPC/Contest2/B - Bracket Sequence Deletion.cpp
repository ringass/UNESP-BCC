#include <bits/stdc++.h>


using namespace std;


bool palin(string str){
    int left = 0, right = str.length() - 1;

    while(left < right){

        if(str[left] != str[right]){
            return false;
        }

        right--;
        left--;
    }

    return true;
}


int main(){
    
    int n, len;

    cin >> n;

    while(--n){

        cin >> len;

        string str;

        cin >> str;

        stack<int> pilha;








    }




}
