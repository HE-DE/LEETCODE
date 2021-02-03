#include <iostream>
#include <string>
using namespace std;

string intToRoman(int num)
{
    //人造哈希表
    int number[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string roman[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    string re;
    for (int i = 0; i < 13 && num > 0; i++)
    { //从最大开始逐步进行减法
        int x = number[i];
        string c = roman[i];
        while (num > x)
        {
            re += c;
            num -= x;
        }
    }
    return re;
}