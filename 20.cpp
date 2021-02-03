#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isValid(string s)
{
    stack<char> temp;
    int len = s.size();
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '{')
        {
            temp.push(s[i]);
        }
        else if (s[i] == '[')
        {
            temp.push(s[i]);
        }
        else if (s[i] == '(')
        {
            temp.push(s[i]);
        }
        else if (s[i] == '}')
        {
            if (temp.empty())
                return false;
            if (temp.top() != '{')
                return false;
            temp.pop();
        }
        else if (s[i] == ']')
        {
            if (temp.empty())
                return false;
            if (temp.top() != '[')
                return false;
            temp.pop();
        }
        else if (s[i] == ')')
        {
            if (temp.empty())
                return false;
            if (temp.top() != '(')
                return false;
            temp.pop();
        }
    }
    if (temp.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string s;
    cin >> s;
    cout << isValid(s) << endl;
    system("pause");
    return 0;
}