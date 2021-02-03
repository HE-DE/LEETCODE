#include <iostream>
#include <vector>
using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{ //归并求中位数
    int l1 = nums1.size();
    int l2 = nums2.size();
    vector<int> result(l1 + l2);
    int i = 0; //第一个数组的游标
    int j = 0; //第二个数组的游标
    int k = 0; //结果数组的游标
    while (i < l1 && j < l2)
    { //进行归并
        if (nums1[i] < nums2[j])
        {
            result[k] = nums1[i];
            k++;
            i++;
        }
        else
        {
            result[k] = nums2[j];
            k++;
            j++;
        }
    }
    while (i < l1)
    { //第一个数组有剩余
        result[k] = nums1[i];
        k++;
        i++;
    }
    while (j < l2)
    { //第二个数组有剩余
        result[k] = nums2[j];
        k++;
        j++;
    }
    int l3 = result.size();
    if (l3 % 2 == 0)
    { //返回中位数
        return (double(result[l3 / 2 - 1]) + double(result[l3 / 2])) / 2;
    }
    else
    {
        return double(result[l3 / 2]);
    }
}