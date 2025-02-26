#include <iostream>

using namespace std;

int main()
{

    int n;

    cin >> n;

    if (n <= 3 && n > 1)
    {
        cout << "NO SOLUTION\n";
        return 0;
    }

    int i = 2;

    while (i <= n)
    {
        cout << i << " ";
        i += 2;
    }

    i = 1;

    while (i <= n)
    {
        cout << i << " ";
        i += 2;
    }

    cout << endl;
}


// #include <iostream>

// using namespace std;

// int main(void)
// {
//     int n;
//     string odd;
//     cin >> n;

//     if (n <= 3 && n > 1)
//     {
//         cout << "NO SOLUTION" << endl;
//         return 0;
//     }

//     for(int i = 1; i <= n; i++){
//         if(i % 2 == 0){

//             cout << i << " ";

//         }else{

//             odd += to_string(i) + " ";

//         }
//     }

//     cout << odd << "\n";

//     return 0;
// }
