#include <iostream>
#include "ListNode.h"
using namespace std;
/*
    需要一个虚拟头结点，然后用变量pre指向该虚拟头结点。
    这样在删除重复结点之后，剩余的结点就可以挂在pre之后继续考察了。
*/
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode *virtualHead = new ListNode(head->val - 1);
        virtualHead->next = head;

        ListNode *pre = virtualHead;
        ListNode *cur = head;
        while(cur)
        {
            int repeat = 0;
            ListNode *diffNode = cur;
            while(diffNode && cur->val == diffNode->val)
            {
                repeat++;
                diffNode = diffNode->next;
            }
            if(repeat > 1)
            {
                pre->next = diffNode;
            }
            else
            {
                pre = cur;
            }
            cur = diffNode;
        }
        return virtualHead->next;
    }
};

// 递归
class Solution2
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode *p = head->next;
        while(p && p->val == head->val)
            p = p->next;
        if(p == head->next)
        {
            head->next = deleteDuplicates(p);
            return  head;
        }
        else
        {
            return deleteDuplicates(p);
        }
    }
};

int main()
{

    return 0;
}