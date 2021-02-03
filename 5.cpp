#include <iostream>
#include <string>
using namespace std;

int excenter(string &s, int left, int right)
{
    int L = left;
    int R = right;
    while (L >= 0 && R < s.length() && s[L] == s[R])
    {
        L--;
        R++;
    }
    return R - L - 1;
}

string longestPalindrome(string s)
{
    int n = s.length();
    int start = 0;
    int end = 0;
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        int len1 = excenter(s, i, i);
        int len2 = excenter(s, i, i + 1);
        len = max(max(len1, len2), len);
        if (len > end - start + 1)
        {
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }
    return s.substr(start, len);
}