#include <iostream>
#include "ListNode.h"
using namespace std;

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *p = head, *pre = nullptr;
        while(p)
        {
            ListNode *next = p->next;
            p->next = pre;
            pre = p;
            p = next;
        }
        return pre;
    }
};

int main()
{

    return 0;
}