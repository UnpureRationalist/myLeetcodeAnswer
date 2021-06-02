#include <iostream>
#include "ListNode.h"
#include <map>
using namespace std;

class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode newHead(-1, head), *virtualHead = &newHead;
        ListNode *lastSorted = head, *cur = head->next;
        while (cur)
        {
            if (cur->val >= lastSorted->val)
            {
                lastSorted = cur;
            }
            else
            {
                ListNode *p = virtualHead;
                while (p->next->val < cur->val)
                {
                    p = p->next;
                }
                lastSorted->next = cur->next;
                cur->next = p->next;
                p->next = cur;
            }
            cur = lastSorted->next;
        }
        return virtualHead->next;
    }
};

class Solution2
{
public:
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        map<int, int> mp;
        ListNode *p = head;
        while (p)
        {
            ++mp[p->val];
            p = p->next;
        }
        p = head;
        for (auto &twin : mp)
        {
            int val = twin.first;
            int count = twin.second;
            while (count--)
            {
                p->val = val;
                p = p->next;
            }
        }
        return head;
    }
};

// 自顶向下归并排序
class Solution3
{
public:
    ListNode *sortList(ListNode *head)
    {
        return sortList(head, nullptr);
    }

    ListNode *sortList(ListNode *head, ListNode *tail)
    {
        if (head == nullptr)
        {
            return head;
        }
        if (head->next == tail)
        {
            head->next = nullptr;
            return head;
        }
        ListNode *slow = head, *fast = head;
        while (fast != tail)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast != tail)
            {
                fast = fast->next;
            }
        }
        ListNode *mid = slow;
        return merge(sortList(head, mid), sortList(mid, tail));
    }

    ListNode *merge(ListNode *head1, ListNode *head2)
    {
        ListNode *dummyHead = new ListNode(0);
        ListNode *temp = dummyHead, *temp1 = head1, *temp2 = head2;
        while (temp1 != nullptr && temp2 != nullptr)
        {
            if (temp1->val <= temp2->val)
            {
                temp->next = temp1;
                temp1 = temp1->next;
            }
            else
            {
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        if (temp1 != nullptr)
        {
            temp->next = temp1;
        }
        else if (temp2 != nullptr)
        {
            temp->next = temp2;
        }
        return dummyHead->next;
    }
};

class Solution4
{
public:
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr)
        {
            return head;
        }
        int length = 0;
        ListNode *node = head;
        while (node != nullptr)
        {
            length++;
            node = node->next;
        }
        ListNode *dummyHead = new ListNode(0, head);
        for (int subLength = 1; subLength < length; subLength <<= 1)
        {
            ListNode *prev = dummyHead, *curr = dummyHead->next;
            while (curr != nullptr)
            {
                ListNode *head1 = curr;
                for (int i = 1; i < subLength && curr->next != nullptr; i++)
                {
                    curr = curr->next;
                }
                ListNode *head2 = curr->next;
                curr->next = nullptr;
                curr = head2;
                for (int i = 1; i < subLength && curr != nullptr && curr->next != nullptr; i++)
                {
                    curr = curr->next;
                }
                ListNode *next = nullptr;
                if (curr != nullptr)
                {
                    next = curr->next;
                    curr->next = nullptr;
                }
                ListNode *merged = merge(head1, head2);
                prev->next = merged;
                while (prev->next != nullptr)
                {
                    prev = prev->next;
                }
                curr = next;
            }
        }
        return dummyHead->next;
    }

    ListNode *merge(ListNode *head1, ListNode *head2)
    {
        ListNode *dummyHead = new ListNode(0);
        ListNode *temp = dummyHead, *temp1 = head1, *temp2 = head2;
        while (temp1 != nullptr && temp2 != nullptr)
        {
            if (temp1->val <= temp2->val)
            {
                temp->next = temp1;
                temp1 = temp1->next;
            }
            else
            {
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        if (temp1 != nullptr)
        {
            temp->next = temp1;
        }
        else if (temp2 != nullptr)
        {
            temp->next = temp2;
        }
        return dummyHead->next;
    }
};

int main()
{

    return 0;
}