#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        int len;
        cin >> len;

        string str;
        cin >> str;

        string temp;
        int conjuntos = 0, usados = 0;

        for (int i = 0; i < len; i++)
        {
            temp += str[i];

            if (temp == "))" || temp == "((" || temp == "()")
            {
                conjuntos++;
                usados += temp.length();
                temp.clear();
            }
            else if (temp.length() > 1)
            {
                if (temp[i] == ')')
                {
                    conjuntos++;
                    usados += temp.length();
                    temp.clear();
                }
            }
        }

        cout << conjuntos << " " << len - usados<< endl;
    }

    return 0;
}