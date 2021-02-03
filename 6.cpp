#include <iostream>
#include <string>
#include <vector>
using namespace std;

string convert(string s, int numRows)
{
    if (numRows == 1)
        return s;                                     //如果一行，则直接返回
    vector<string> rows(min(numRows, int(s.size()))); //确保不会超出限制

    int current = 0; //行的游标
    bool op = false; //是否转向
    for (char c : s)
    {                       //c在s中，找到应该出现的位置
        rows[current] += c; //对应位置字符串相加
        if (current == 0 || current == numRows - 1)
        { //转向条件
            op = !op;
        }
        if (op)
        {
            current += 1;
        }
        else
        {
            current += (-1);
        }
    }
    string result; //返回结果
    for (string x : rows)
    {
        result += x;
    }
    return result;
}