#include "ListNode.hpp"
#include <iostream>
using namespace std;

class Solution
{
public:
    ListNode *swapNodes(ListNode *head, int k)
    {
        ListNode *pre = head;
        for (int i = 1; i < k; ++i)
            pre = pre->next;
        ListNode *fast = head, *slow = head;
        while (k--)
            fast = fast->next;
        while (fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        swap(slow->val, pre->val);
        return head;
    }
};