#include <iostream>

using namespace std;

int main()
{

    char a, b;
    char pos[4];

    int n;

    cin >> a >> b >> n;

    if (a == b)
    {
        cout << "undefined" << endl;
        return 0;
    }

    int x = n % 4;

    if (a == '^')
    {
        pos[0] = '^';
        pos[1] = '>';
        pos[2] = 'v';
        pos[3] = '<';
    }
    else if (a == 'v')
    {
        pos[2] = '^';
        pos[3] = '>';
        pos[0] = 'v';
        pos[1] = '<';
    }
    else if (a == '<')
    {
        pos[1] = '^';
        pos[2] = '>';
        pos[3] = 'v';
        pos[0] = '<';
    }
    else if (a == '>')
    {
        pos[3] = '^';
        pos[0] = '>';
        pos[1] = 'v';
        pos[2] = '<';
    }

    if (pos[x] == b && pos[4 - x] != b)
    {
        cout << "cw" << endl;
    }else if(pos[2] == b){
        cout << "undefined" << endl;
    }else{
        cout << "ccw" << endl;
    }
}