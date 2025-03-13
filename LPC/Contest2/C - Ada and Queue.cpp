#include <bits/stdc++.h>

using namespace std;

bool vazio(deque<int> &fila)
{
    if (fila.empty())
    {
        cout << "No job for Ada?" << endl;
        return true;
    }
    return false;
}

int main()
{
    deque<int> fila;
    int n, x, rev = 0;
    string str;

    cin >> n;

    while (n--)
    {
        cin >> str;

        switch (str[0])
        {
        case 'r':
            rev = !rev;
            break;

        case 'p':
            cin >> x;
            if (rev)
            {
                fila.push_front(x);
            }
            else
            {
                fila.push_back(x);
            }
            break;

        case 't':

            cin >> x;
            if (rev)
            {
                fila.push_back(x);
            }
            else
            {
                fila.push_front(x);
            }
            break;

        case 'f':
            if (!vazio(fila))
            {
                if (rev)
                {
                    cout << fila.back() << endl;
                    fila.pop_back();
                }
                else
                {
                    cout << fila.front() << endl;
                    fila.pop_front();
                }
            }
            break;

        case 'b':
            if (!vazio(fila))
            {
                if (rev)
                {
                    cout << fila.front() << endl;
                    fila.pop_front();
                }
                else
                {
                    cout << fila.back() << endl;
                    fila.pop_back();
                }
            }
            break;
        }
    }

    return 0;
}
