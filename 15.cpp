#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{ //排序+双指针
    int len = nums.size();
    int L = 0;                      //左指针
    int R = 0;                      //右指针
    vector<vector<int>> ans;        //最终答案
    sort(nums.begin(), nums.end()); //排序，默认升序
    if (len < 3)
    { //长度小于三直接返回空
        return ans;
    }
    for (int i = 0; i < len; i++)
    { //去重及计算
        if (nums[i] > 0)
        { //从此时起，由于已经排好序，不会出现为零的和
            return ans;
        }
        if (i > 0 && nums[i] == nums[i - 1])
        { //去重
            continue;
        }
        L = i + 1;   //定位左指针
        R = len - 1; //定位右指针
        while (L < R)
        { //指针进行移动
            if (nums[i] + nums[L] + nums[R] == 0)
            { //得到答案
                vector<int> temp;
                temp.push_back(nums[i]);
                temp.push_back(nums[L]);
                temp.push_back(nums[R]);
                ans.push_back(temp);
                temp.clear();
                while (L < R && nums[L] == nums[L + 1])
                { //去重
                    L += 1;
                }
                while (L < R && nums[R] == nums[R - 1])
                { //去重
                    R -= 1;
                }
                L += 1; //移动游标
                R -= 1;
            }
            else if (nums[i] + nums[L] + nums[R] > 0)
            {
                R -= 1;
            }
            else
            {
                L += 1;
            }
        }
    }
    return ans;
}