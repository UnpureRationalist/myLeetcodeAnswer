#include <iostream>
#include "ListNode.h"
using namespace std;

class Solution
{
public:
    ListNode *insertionSortList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode Node(0, head), *virtualNode = &Node;
        ListNode *cur = head->next, *lastSorted = head;
        while (cur)
        {
            if (lastSorted->val <= cur->val)
            {
                lastSorted = cur;
            }
            else
            {
                ListNode *pre = virtualNode;
                while (pre->next->val < cur->val)
                {
                    pre = pre->next;
                }
                lastSorted->next = cur->next;
                cur->next = pre->next;
                pre->next = cur;
            }
            cur = lastSorted->next;
        }
        return virtualNode->next;
    }
};

int main()
{
    Solution s;
    ListNode n1(10), n2(1), n3(12);
    n1.next = &n2;
    n2.next = &n3;
    ListNode *res = s.insertionSortList(&n1);
    while (res)
    {
        cout << "res->val = " << res->val << endl;
        res = res->next;
    }
    return 0;
}