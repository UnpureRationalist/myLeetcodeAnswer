#include <iostream>
#include "ListNode.h"
using namespace std;

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode *cur = head->next;
        ListNode *pre = head;
        while(cur)
        {
            if(cur->val == pre->val)
            {
                pre->next = cur->next;
                ListNode *temp = cur;
                cur = cur->next;
                delete temp;
            }
            else
            {
                pre = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};

int main()
{

    return 0;
}