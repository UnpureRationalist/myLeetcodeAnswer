#include <iostream>
#include <vector>
#include "ListNode.h"
using namespace std;

class Solution
{
    int getLength(ListNode *head)
    {
        int count = 0;
        while (head)
        {
            head = head->next;
            ++count;
        }
        return count;
    }

public:
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        int length = getLength(head);
        vector<ListNode *> res;
        int average = length / k;
        int mod = length % k;
        ListNode *pre = head;
        ListNode *tail = head;
        for (int i = 0; i < k; ++i)
        {
            res.push_back(pre);
            int end = i < mod ? average + 1 : average;
            for (int j = 0; j < end; ++j)
            {
                tail = pre;
                pre = pre == nullptr ? pre : pre->next;
            }
            if (tail != nullptr)
            {
                tail->next = nullptr;
            }
        }
        return res;
    }
};