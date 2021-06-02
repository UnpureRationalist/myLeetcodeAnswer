#include <iostream>
#include "ListNode.h"
using namespace std;

class Solution
{
public:
    ListNode *deleteNode(ListNode *head, int val)
    {
        if(!head)
            return head;
        if(head->val == val)
            return head->next;
        ListNode *p = head, *pre = head;
        while(p)
        {
            if(p->val == val)
                break;
            
            pre = p;
            p = p->next;
        }
        if(p)
        {
            pre->next = p->next;
        }
        return head;
    }
};

int main()
{

    return 0;
}