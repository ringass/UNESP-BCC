#include <iostream>

using namespace std;

int main(void)
{
    int n;

    cin >> n;

    if (n == 1)
    {
        cout << n << endl;
        exit(0);
    }

    if (n <= 3)
    {
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    int j;

    if(n % 2 != 0){
        j = n - 1;
    }else{
        j = n;
    }
    
    
    for (int i = j; i >= 2; i -= 2)
    {
        cout << i << " ";
    }

    if (n % 2 != 0)
    {
        cout << n << " ";
    }

    for (int i = j - 1; i > 0; i -= 2)
    {
        cout << i << " ";
    }

    cout << endl;


    return 0;
}
