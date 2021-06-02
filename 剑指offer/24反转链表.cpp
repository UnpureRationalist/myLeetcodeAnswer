#include <iostream>
#include "ListNode.h"
using namespace std;

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *cur = head, *next = nullptr, *pre = nullptr;
        while(cur)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};

int mian()
{

    return 0;
}