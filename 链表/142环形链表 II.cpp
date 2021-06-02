#include <iostream>
#include "ListNode.h"
using namespace std;

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *fast = head, *slow = head;
        bool flag = false;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow)
            {
                flag = true;
                break;
            }
        }
        if(!flag)
            return nullptr;
        slow = head;
        while(slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

int main()
{

    return 0;
}