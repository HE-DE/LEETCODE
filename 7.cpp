#include <iostream>
using namespace std;

int reverse(int x)
{
    int result = 0;
    while (x != 0)
    {                                                                     //当传入参数不为零时进入循环
        int pop = x % 10;                                                 //取出最末尾一位
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && pop > 7)) //判断是否溢出
            return 0;                                                     //最大值末尾7，最小值末尾8
        if (result < INT_MIN / 10 || (result == INT_MIN && pop < -8))
            return 0;
        result = result * 10 + x % 10; //进行迭代
        x = x / 10;
    }
    return result;
}