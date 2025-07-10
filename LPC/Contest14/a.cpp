#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;

long long mod(string num) {
    long long res = 0;
    for(int i = 0; i < num.size(); i++){
        res = (res * 10 + (num[i] - '0')) % MOD;
    }
    return res;
}

long long poww(long long base, string exp_str) {
    long long exponent = 0;
    long long phi = MOD - 1;
    bool reduced = false;
    
    for(int i = 0; i < exp_str.size(); i++){
        exponent = (exponent * 10 + (exp_str[i] - '0')) % phi;
    }
    
    if(base == 0) return 0;
    
    long long result = 1;
    base = base % MOD;
    long long exp = exponent;
    
    while(exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

int main() {
    string xx, op, yy;

    cin >> xx >> op >> yy;
    
    long long x, y;
    x = mod(xx);
    
    if(op == "+"){
        y = mod(yy);
        cout << (x + y) % MOD << "\n";
    }else if(op == "-"){
        y = mod(yy);
        cout << (x - y + MOD) % MOD << "\n";
    }else if(op == "*"){
        y = mod(yy);
        cout << (x * y) % MOD << "\n";
    }else if(op == "^"){
        cout << poww(x, yy) << "\n";
    }
    
    return 0;
}