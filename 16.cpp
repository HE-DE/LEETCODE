#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int threeSumClosest(vector<int> &nums, int target)
{
    int len = nums.size();
    int result = nums[0] + nums[1] + nums[2];
    int L = 0;
    int R = 0;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < len; i++)
    {
        L = i + 1;
        R = len - 1;
        while (L < R)
        {
            int sum = nums[L] + nums[R] + nums[i];
            if (abs(sum - target) < abs(result - target))
            {
                result = sum;
            }
            if (target < sum)
            {
                R--;
            }
            if (target > sum)
            {
                L++;
            }
            if (target == sum)
            {
                return result;
            }
        }
    }
    return result;
}