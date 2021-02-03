#include <iostream>
#include <string>
using namespace std;

int myAtoi(string s)
{
    int i = 0;      //字符串的游标
    int sign = 1;   //正负标志
    int result = 0; //结果
    while (s[i] == ' ' && i < s.size())
    { //处理' '游标向后移动
        i++;
    }
    if (i == s.size())
    { //全为' '返回零
        return 0;
    }
    //处理第一个非' '字符
    if (s[i] == '-')
    { //负号读入，游标向后移动，正负标识改变
        sign = -1;
        i++;
    }
    else if (s[i] == '+')
    { //正号读入，游标向后移动
        i++;
    }

    else if (!isdigit(s[i]))
    { //读入非数字型字符，返回零
        return 0;
    }
    while (isdigit(s[i]) && i < s.size())
    { //读入字符为数字且在范围内
        if ((INT_MAX - (s[i] - '0')) / 10 < result)
        { //如果溢出
            if (sign == -1)
            { //负数返回最小值
                return INT_MIN;
            }
            else
            { //正数返回最大值
                return INT_MAX;
            }
        }
        result = result * 10 + (s[i] - '0'); //进行迭代
        i++;
    }
    return sign * result; //返回结果
}
