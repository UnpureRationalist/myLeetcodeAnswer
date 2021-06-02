#include <iostream>
#include "ListNode.h"
using namespace std;

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast != nullptr)
            slow = slow->next;
        ListNode *left = head;
        ListNode *right = reverse(slow);
        while (right)
        {
            if(left->val != right->val)
                return false;
            left = left->next;
            right = right->next;
        }
        return true;
    }

    ListNode *reverse(ListNode *head)
    {
        ListNode *p = head, *pre = nullptr, *next = nullptr;
        while(p)
        {
            next = p->next;
            p->next = pre;
            pre = p;
            p = next;
        }
        return pre;
    }
};


class Solution2
{
    ListNode *left;
public:
    bool isPalindrome(ListNode *head)
    {
        left = head;
        return traverse(head);
    }

    bool traverse(ListNode *right)
    {
        if(right == nullptr)
            return true;
        bool res = traverse(right->next);
        res = res && (right->val == left->val);
        left = left->next;
        return res;
    }
};

int main()
{

    return 0;
}