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

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    int len = 0;
    ListNode *p = head;
    while (p != NULL)
    {
        len++;
        p = p->next;
    }
    ListNode *first = new ListNode(0, head);
    p = first;
    for (int i = 1; i < len - n + 1; i++)
    {
        p = p->next;
    }
    p->next = p->next->next;
    ListNode *ans = first->next;
    delete first;
    return ans;
}