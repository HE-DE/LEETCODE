#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> result;
    if (nums.size() < 4)
    {
        return result;
    }
    sort(nums.begin(), nums.end());
    int L = 0;
    int R = 0;
    for (int i = 0; i < nums.size() - 3; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }
        for (int j = i + 1; j < nums.size() - 2; j++)
        {
            if (j > i+1 && nums[j] == nums[j - 1])
            {
                continue;
            }
            L = j + 1;
            R = nums.size() - 1;
            while (L < R)
            {
                if (nums[i] + nums[j] + nums[L] + nums[R] > target)
                {
                    R--;
                }
                else if (nums[i] + nums[j] + nums[L] + nums[R] < target)
                {
                    L++;
                }
                else
                {
                    result.push_back({nums[L], nums[i], nums[j], nums[R]});
                    while (L < R && nums[L] == nums[L + 1])
                    {
                        L += 1;
                    }
                    while (L < R && nums[R] == nums[R - 1])
                    {
                        R -= 1;
                    }
                    L += 1;
                    R -= 1;
                }
            }
        }
    }
    return result;
}