#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int> &height)
{ //贪心算法，双游标移动
    int len = height.size();
    int i = 0;
    int j = len - 1;
    int max_area = 0;
    while (i < j)
    {
        int temp_area = min(height[i], height[j]) * (j - i);
        max_area = max(max_area, temp_area);
        if (height[i] < height[j])
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return max_area;
}