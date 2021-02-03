#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int s1 = 1; //初始化链表长度
        int s2 = 1;
        ListNode *p = l1;       //l1的游标
        ListNode *q = l2;       //l2的游标
        while (p->next != NULL) //记录链表的长度
        {
            s1 += 1;
            p = p->next;
        }
        while (q->next != NULL)
        {
            s2 += 1;
            q = q->next;
        }
        if (s1 < s2) //短的链表补零
        {
            for (int i = 0; i < s2 - s1; i++)
            {
                p->next = new ListNode(0);
                p = p->next;
            }
        }
        else if (s1 > s2)
        {
            for (int i = 0; i < s1 - s2; i++)
            {
                q->next = new ListNode(0);
                q = q->next;
            }
        }
        bool count = false; //进位标志初始为false(0)
        p = l1;             //游标初始化
        q = l2;
        ListNode *r3 = new ListNode(-1); //盛放结果的链表
        ListNode *t3 = r3;               //结果链表的游标
        int temp = 0;                    //临时存放数字
        while (p != NULL && q != NULL)
        { //对应位置相加（连带进位标志），大于10则进位且原位对10求余
            temp = count + p->val + q->val;
            if (temp >= 10)
            {
                count = true;
            }
            else
            {
                count = false;
            }
            t3->next = new ListNode(temp % 10);
            p = p->next;
            q = q->next;
            t3 = t3->next;
        }
        if (count)
        { //如果最高位相加需进位则进行添一
            t3->next = new ListNode(1);
            t3 = t3->next;
        }
        r3 = r3->next; //返回结果不包括头节点
        return r3;
    }
};