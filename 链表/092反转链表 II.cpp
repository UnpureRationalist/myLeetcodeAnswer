#include <iostream>
#include "ListNode.h"
using namespace std;

class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if(left == 1)
        {
            ListNode *cur = head, *pre = nullptr;
            int count = 0;
            while(cur && count < right)
            {
                ListNode *next = cur->next;
                cur->next = pre;
                pre = cur;
                cur = next;
                ++count;
            }
            head->next = cur;
            return pre;
        }
        head->next = reverseBetween(head->next, left - 1, right - 1);
        return head;
    }
};

int main()
{

    return 0;
}