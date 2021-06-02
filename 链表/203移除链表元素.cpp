#include <iostream>
#include "ListNode.h"
using namespace std;

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *newHead = new ListNode(), *save = newHead;
        newHead->next = head;
        while (head)
        {
            if (head->val == val)
            {
                ListNode *temp = head;
                newHead->next = head->next;
                head = head->next;
                delete temp;
            }
            else
            {
                head = head->next;
                newHead = newHead->next;
            }
        }
        newHead = save;
        ListNode *res = save->next;
        delete newHead;
        return res;
    }
};

int main()
{

    return 0;
}