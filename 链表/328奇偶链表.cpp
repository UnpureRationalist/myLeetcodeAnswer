#include <iostream>
#include "ListNode.h"
using namespace std;

class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *even = head, *ehead = even, *odd = head->next, *ohead = odd;
        int count = 1;
        head = head->next->next;
        while (head)
        {
            if (count % 2)
            {
                even->next = head;
                even = even->next;
            }
            else
            {
                odd->next = head;
                odd = odd->next;
            }
            ++count;
            head = head->next;
        }
        even->next = ohead;
        odd->next = nullptr;
        return ehead;
    }
};

int main()
{

    return 0;
}