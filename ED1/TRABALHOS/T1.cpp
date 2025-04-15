#include <bits/stdc++.h>

using namespace std;

void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

constexpr char aaaaa[11] = {'^', '*', '/', '+', '-', '>', '<', '=', '#', '.', '|'};

int prio(char c)
{

    if (c == '^')
    {
        return 6;
    }
    else if (c == '*' || c == '/')
    {
        return 5;
    }
    else if (c == '+' || c == '-')
    {
        return 4;
    }
    else if (c == '>' || c == '<' || c == '=' || c == '#')
    {
        return 3;
    }
    else if (c == '.')
    {
        return 2;
    }
    else if (c == '|')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

void resolve(string str)
{

    stack<char> pilha;
    string ans;
    int count_parentesis = 0;
    char last_c;
    bool flag = false;

    for (int i = 0; i < str.length(); i++)
    {
        char c = str[i];

        if (i >= 1)
        {
            last_c = str[i - 1];

            int prio_last = prio(last_c);
            int prio_now = prio(c);

            if (prio_last > -1 && prio_now > -1)
            {
                flag = true;
            }
            else if ((prio_last == -1 && prio_now == -1) && (isalnum(c) && isalnum(last_c)))
            {
                flag = true;
            }
        }

        if (isalnum(c))//resolver
        {
            ans += c;
        }else if(!isalnum(c)){

            for(auto p : aaaaa){
                if(){

                }
            }
        }
        else if (c == '(')
        {
            pilha.push('(');
            count_parentesis++;
        }
        else if (c == ')')
        {
            count_parentesis--;
            while (pilha.top() != '(')
            {
                ans += pilha.top();
                pilha.pop();
            }
            pilha.pop();
        }
        else
        {
            while (!pilha.empty() && prio(c) <= prio(pilha.top()))
            {
                ans += pilha.top();
                pilha.pop();
            }

            pilha.push(c);
        }

    while (!pilha.empty())
    {
        ans += pilha.top();
        pilha.pop();
    }

    if (count_parentesis != 0)
    {
        cout << "Syntax Error!\n";
        return;
    }
    else if (flag)
    {
        cout << "Lexical Error!\n";
    }
    else
    {
        cout << ans << endl;
    }
}
}

int main()
{

    string str;

    while (cin >> str)
    {
        resolve(str);
    }
}