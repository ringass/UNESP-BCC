#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(){

    queue<string> norte; //-3
    queue<string> sul;  //-2
    queue<string> leste; //-4
    queue<string> oeste; //-1

    int n;
    string str, temp;


    while(true){

    cin >> str;

    if(str == "-1" || str == "-2" || str == "-3" || str == "-4" ){
        temp == str;
    }

    if(n == 0){
        break;
    }

    if(n == -1){
        oeste.push(str);
    }else if(n == -2){
        sul.push(str);
    }else if(n == -3){
        norte.push(str);
    }else if(n == -4){
        leste.push(str);
    }

    }


    while(!(leste.empty()) && !(oeste.empty()) && !sul.empty() || !norte.empty() ){

        if(!oeste.empty()){
            cout << oeste.front() << " ";
            oeste.pop();
        }


        if(!norte.empty()){
            cout << norte.front() << " ";
            norte.pop();
        }

        if(!sul.empty()){
            cout << sul.front() << " ";
            sul.pop();
        }

        
        if(!leste.empty()){
            cout << leste.front() << " ";
            leste.pop();
        }

    }
    
    cout << endl;
    
}