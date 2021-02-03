#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(int x)
{
    string temp = to_string(x); //将数字转化为字符串
    int nums = temp.size();     //得到字符串的长度
    string result;
    for (int i = nums - 1; i >= 0; i--) //进行翻转
    {
        result += temp[i];
    }
    if (result == temp) //正反相同则为回文数
    {
        return true;
    }
    else
    {
        return false;
    }
}