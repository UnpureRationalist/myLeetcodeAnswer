#include <iostream>
#include "ListNode.h"
using namespace std;

class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode virtHead(-1, head);
        ListNode *pre = &virtHead, *cur = head;
        ListNode virBigHead(-1, nullptr);
        ListNode *bigPre = &virBigHead;
        while (cur)
        {
            if (cur->val >= x)
            {
                bigPre->next = cur;
                bigPre = cur;
            }
            else
            {

                pre->next = cur;
                pre = cur;
            }
            cur = cur->next;
        }
        pre->next = virBigHead.next;
        bigPre->next = nullptr;
        return virtHead.next;
    }
};

int main()
{
    ListNode nodes[] = {1, 4, 3, 2, 5, 2};
    int n = sizeof(nodes) / sizeof(ListNode);
    for (int i = 0; i < n - 1; ++i)
    {
        nodes[i].next = &nodes[i + 1];
    }
    Solution s;
    auto head = s.partition(&nodes[0], 3);
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}