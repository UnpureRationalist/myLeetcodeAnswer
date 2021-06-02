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
        ListNode *head = nullptr;
        if(l1->val <= l2->val)
        {
            head = new ListNode(l1->val);
            head->next = mergeTwoLists(l1->next, l2);
        }
        else
        {
            head = new ListNode(l2->val);
            head->next = mergeTwoLists(l1, l2->next);
        }
        return head;
    }
};

int main()
{

    return 0;
}