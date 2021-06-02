#include <iostream>
#include "ListNode.h"
using namespace std;

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *slow = head, *fast = head;
        int k = n;
        while(n--)
        {
            fast = fast->next;
        }
        if(fast == nullptr)
        {
            return head->next;
        }
        ListNode *pre = head;
        while(fast)
        {
            pre = slow;
            slow = slow->next;
            fast = fast->next;
        }
        pre->next = slow->next;
        delete slow;
        return slow == head ? nullptr : head;
    }

    
};

int main()
{

    return 0;
}