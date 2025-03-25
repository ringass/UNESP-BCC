#include <bits/stdc++.h>

using namespace std;

int prio(char c){

    if(c == '^'){
        return 3;
    }
    else if(c == '*' || c == '/'){
        return 2;
    }else if(c == '+' || c == '-'){
        return 1;
    }else{
        return -1;
    }  
}


void resolve(string str){

    stack<char> pilha;
    string ans;

    for(int i = 0; i < str.length(); i++){
        char c = str[i];

        if(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || (c >= '0' && c <= '9')){
            ans += c;
        }else if(c == '('){
            pilha.push('(');
        }else if(c == ')'){
            while(pilha.top() != '('){
                ans += pilha.top();
                pilha.pop();
             }
             pilha.pop();
        }else{

            while(!pilha.empty() && prio(c) <= prio(pilha.top())){
                ans += pilha.top();
                pilha.pop();
            }

            pilha.push(c);
        }
}
        while(!pilha.empty()){
            ans += pilha.top();
            pilha.pop();
}
        
    cout << ans << endl;
}

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{

    fast();

    int n;

    cin >> n;

    while (n--)
    {
        string str;

        cin >> str;

        resolve(str);    
    }

    return 0;
}
