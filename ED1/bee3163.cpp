#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int main()
{
    queue<string> norte; //-3
    queue<string> sul;   //-2
    queue<string> leste; //-4
    queue<string> oeste; //-1

    int n;
    char str[10], temp[10] = "";
    int count = 0;
    while (true)
    {
        cin >> str;

        // Corrige a comparação usando strcmp()
        if (strcmp(str, "-1") == 0 || strcmp(str, "-2") == 0 || strcmp(str, "-3") == 0 || strcmp(str, "-4") == 0)
        {
            strcpy(temp, str);
        }

        if (strcmp(str, "0") == 0)
        {
            break;
        }

        if (strcmp(str, "-1") != 0 && strcmp(str, "-2") != 0 && strcmp(str, "-3") != 0 && strcmp(str, "-4") != 0)
        {
            if (strcmp(temp, "-1") == 0)
            {
                oeste.push(string(str));
                count++;
            }
            else if (strcmp(temp, "-2") == 0)
            {
                sul.push(string(str));
                count++;
            }
            else if (strcmp(temp, "-3") == 0)
            {
                norte.push(string(str));
                count++;
            }
            else if (strcmp(temp, "-4") == 0)
            {
                leste.push(string(str));
                count++;
            }
        }
    }

    while (!(leste.empty()) || !(oeste.empty()) || !sul.empty() || !norte.empty())
    {
        if (!oeste.empty())
        {
            if (count != 1)
            {
                cout << oeste.front() << " ";
            }
            else
            {
                cout << oeste.front();
            }
            oeste.pop();
            count--;
        }

        if (!norte.empty())
        {
            if (count != 1)
            {
                cout << norte.front() << " ";
            }
            else
            {
                cout << norte.front();
            }
            norte.pop();
            count--;
        }

        if (!sul.empty())
        {
            if (count != 1)
            {
                cout << sul.front() << " ";
            }
            else
            {
                cout << sul.front();
            }
            sul.pop();
            count--;
        }

        if (!leste.empty())
        {
            if (count != 1)
            {
                cout << leste.front() << " ";
            }
            else
            {
                cout << leste.front();
            }
            leste.pop();
            count--;
        }
    }

    cout << "\n";
}
