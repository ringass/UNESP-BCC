#include <bits/stdc++.h>
using namespace std;

void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

const char operators[11] = {'^', '*', '/', '+', '-', '>', '<', '=', '#', '.', '|'};

bool ver_operator(char c)
{
    for (char op : operators)
    {
        if (c == op)
            return true;
    }
    return false;
}

int prio(char c)
{
    if (c == '^')
        return 6;
    else if (c == '*' || c == '/')
        return 5;
    else if (c == '+' || c == '-')
        return 4;
    else if (c == '>' || c == '<' || c == '=' || c == '#')
        return 3;
    else if (c == '.')
        return 2;
    else if (c == '|')
        return 1;
    else
        return -1;
}

void resolve(string str)
{
    stack<char> pilha;
    string ans;
    int count_parentesis = 0;
    char last = '\0';
    bool lexical_flag = false;
    bool syntax_flag = false;

    for (int i = 0; i < str.length(); i++)
    {
        char c = str[i];

        if (!isalnum(c) && !ver_operator(c) && c != '(' && c != ')')
        {
            lexical_flag = true;
            break;
        }

        if (i >= 1)
        {
            if ((isalnum(last) && isalnum(c)) || (ver_operator(last) && ver_operator(c)))
            {
                syntax_flag = true;
            }
        }

        if (isalnum(c))
        {
            ans += c;
        }
        else if (c == '(')
        {
            pilha.push(c);
            count_parentesis++;
        }
        else if (c == ')')
        {
            count_parentesis--;
            if (count_parentesis < 0)
            {
                syntax_flag = true;
                break;
            }
            while (!pilha.empty() && pilha.top() != '(')
            {
                ans += pilha.top();
                pilha.pop();
            }
            if (pilha.empty())
            {
                syntax_flag = true;
                break;
            }
            pilha.pop();
        }
        else if (ver_operator(c))
        {
            while (!pilha.empty() && prio(c) <= prio(pilha.top()))
            {
                ans += pilha.top();
                pilha.pop();
            }
            pilha.push(c);
        }

        last = c;
    }

    while (!pilha.empty())
    {
        if (pilha.top() == '(' || pilha.top() == ')')
        {
            syntax_flag = true;
            break;
        }
        ans += pilha.top();
        pilha.pop();
    }

    if (lexical_flag)
    {
        cout << "Lexical Error!" << endl;
    }
    else if (syntax_flag || count_parentesis != 0)
    {
        cout << "Syntax Error!" << endl;
    }
    else
    {
        cout << ans << endl;
    }
}

int main()
{
    string str;
    while (cin >> str)
    {
        resolve(str);
    }
    return 0;
}
