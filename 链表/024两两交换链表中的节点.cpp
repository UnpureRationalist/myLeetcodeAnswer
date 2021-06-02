#include <iostream>
#include "ListNode.h"
using namespace std;

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode *newHead = head->next;
        ListNode *next = head->next->next;
        newHead->next = head;
        head->next = swapPairs(next);
        return newHead;
    }
};

int main()
{

    return 0;
}