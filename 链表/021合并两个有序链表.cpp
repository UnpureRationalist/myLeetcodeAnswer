#include <iostream>
#include "ListNode.h"
using namespace std;

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if(l1 == nullptr)
            return l2;
        if(l2 == nullptr)
            return l1;
        ListNode *head = l1->val > l2->val ? l2 : l1;
        if(l1->val > l2->val)
            l2 = l2->next;
        else
            l1 = l1->next;
        ListNode *p = head;
        while(l1 && l2)
        {
            if(l1->val > l2->val)
            {
                p->next = l2;
                l2 = l2->next;
            }
            else
            {
                p->next = l1;
                l1 = l1->next;
            }
            p = p->next;
        }
        while(l1)
        {
            p->next = l1;
            l1 = l1->next;
            p = p->next;
        }
        while(l2)
        {
            p->next = l2;
            l2 = l2->next;
            p = p->next;
        }
        return head;
    }
};

int main()
{

    return 0;
}