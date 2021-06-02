#include <iostream>
#include "ListNode.h"
using namespace std;

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *node1 = headA;
        ListNode *node2 = headB;
        while (node1 != node2)
        {
            node1 = node1 != nullptr ? node1->next : headB;
            node2 = node2 != nullptr ? node2->next : headA;
        }
        return node1;
    }
};

int main()
{

    return 0;
}