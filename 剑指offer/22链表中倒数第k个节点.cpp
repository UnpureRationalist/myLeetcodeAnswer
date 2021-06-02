#include <iostream>
#include "ListNode.h"
using namespace std;

class Solution
{
public:
    ListNode *getKthFromEnd(ListNode *head, int k)
    {
        ListNode *fast = head, *slow = head;
        while(k--)
            fast = fast->next;
        while(fast)
        {
            slow =slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

int main()
{

    return 0;
}