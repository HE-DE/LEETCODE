#include <iostream>
#include <string>
using namespace std;

int romanToInt(string s)
{
    int len = s.size();
    int result = 0;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == 'I')
        {
            result += 1;
        }
        else if (s[i] == 'V')
        {
            result += 5;
        }
        else if (s[i] == 'X')
        {
            result += 10;
        }
        else if (s[i] == 'L')
        {
            result += 50;
        }
        else if (s[i] == 'C')
        {
            result += 100;
        }
        else if (s[i] == 'D')
        {
            result += 500;
        }
        else if (s[i] == 'M')
        {
            result += 1000;
        }
    }
    for (int j = 0; j < len - 1; j++)
    {
        if ((s[j] == 'I' && s[j + 1] == 'V') || (s[j] == 'I' && s[j + 1] == 'X'))
        {
            result -= 2;
        }
        else if ((s[j] == 'X' && s[j + 1] == 'L') || (s[j] == 'X' && s[j + 1] == 'C'))
        {
            result -= 20;
        }
        else if ((s[j] == 'C' && s[j + 1] == 'D') || (s[j] == 'C' && s[j + 1] == 'M'))
        {
            result -= 200;
        }
    }
    return result;
}