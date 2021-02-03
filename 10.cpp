#include <iostream>
#include <string>
using namespace std;
bool isMatch(string s, string p)
{ //利用递归解决
    if (p.empty())
    { //如果p为空，则判断s是否为空
        return s.empty();
    }
    if ('*' == p[1])
    {//如果第二个字符为*，则进行递归
        return isMatch(s, p.substr(2)) || (!s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p));
    }
    else
    {
        return !s.empty() && (s[0] == p[0] || '.' == p[0]) && (isMatch(s.substr(1), p.substr(1)));
    }
}
