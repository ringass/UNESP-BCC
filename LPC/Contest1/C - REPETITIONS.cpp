#include <iostream>

using namespace std;

int main(){

    string str;

    cin >> str;

    int i = 1, count = 1, max_ = 1;

    while(i < str.length()){

        if(str[i] == str[i-1]){
            count++;
        }else{
            max_ = max(max_, count);
            count = 1;
        }
        i++;
    }

    max_ = max(max_, count);

    printf("%d\n", max_);

}