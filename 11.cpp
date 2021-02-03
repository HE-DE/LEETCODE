#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int> &height)
{ //枚举所有可能情况，找出最大值
    int max_area = 0;
    for (int i = 0; i < height.size(); i++)
    {
        for (int j = i + 1; j < height.size(); j++)
        {
            int temp_area = min(height[i], height[j]) * (j - i);
            max_area = max(max_area, temp_area);
        }
    }
    return max_area;
}
