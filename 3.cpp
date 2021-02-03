#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
//滑动窗口
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int start = 0;  //窗口开始
        int end = 0;    //窗口结束
        int length = 0; //临时长度
        int result = 0; //最终结果
        while (end < s.size())
        {                       //未进行到最后
            char temp = s[end]; //临时存储字符
            for (int i = start; i < end; i++)
            { //判断是否在之前出现
                if (temp == s[i])
                {
                    start = i + 1;
                    length = end - start;
                    break;
                }
            }
            end++;
            length++;
            result = max(result, length);
        }
        return result;
    }
};