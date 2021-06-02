#include <iostream>
#include "ListNode.h"
using namespace std;

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *p1 = headA, *p2 = headB;
        while (p1 != p2)
        {
            p1 = p1 != nullptr ? p1->next : headB;
            p2 = p2 != nullptr ? p2->next : headA;
        }
        return p1;
    }
};

int main()
{

    return 0;
}