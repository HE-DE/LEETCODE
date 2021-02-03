#include <iostream>
#include <string>
using namespace std;

string intToRoman(int num)
{
    //进行匹配
    string re;
    while (num > 0)
    {
        if (num >= 1000)
        {
            re += "M";
            num -= 1000;
        }
        else if (num >= 900)
        {
            re += "CM";
            num -= 900;
        }
        else if (num >= 500)
        {
            re += "D";
            num -= 500;
        }
        else if (num >= 400)
        {
            re += "CD";
            num -= 400;
        }
        else if (num >= 100)
        {
            re += "C";
            num -= 100;
        }
        else if (num >= 90)
        {
            re += "XC";
            num -= 90;
        }
        else if (num >= 50)
        {
            re += "L";
            num -= 50;
        }
        else if (num >= 40)
        {
            re += "XL";
            num -= 40;
        }
        else if (num >= 10)
        {
            re += "X";
            num -= 10;
        }
        else if (num >= 9)
        {
            re += "IX";
            num -= 9;
        }
        else if (num >= 5)
        {
            re += "V";
            num -= 5;
        }
        else if (num >= 4)
        {
            re += "IV";
            num -= 4;
        }
        else if (num >= 1)
        {
            re += "I";
            num -= 1;
        }
    }
    return re;
}