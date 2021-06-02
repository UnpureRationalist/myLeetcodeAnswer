#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int pre = 0;
        ListNode *p1 = l1, *p2 = l2;
        ListNode *res, *p, *q;
        bool flag = true;
        while(p1 && p2)
        {
            int lop = p1->val, rop = p2->val;
            int sum = lop + rop + pre;
            pre = sum/10;
            sum = sum%10;
            if(flag)
            {
                res = new ListNode(sum);
                p = res;
                flag = false;
            }
            else
            {
                q = new ListNode(sum);
                p->next = q;
                p = q;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        while(p1)
        {
            int sum = p1->val + pre;
            pre = sum/10;
            sum = sum%10;
            q = new ListNode(sum);
            p->next = q;
            p = q;
            p1 = p1->next;
        }
        while(p2)
        {
            int sum = p2->val + pre;
            pre = sum/10;
            sum = sum%10;
            q = new ListNode(sum);
            p->next = q;
            p = q;
            p2 = p2->next;
        }
        if(pre)
        {
            q = new ListNode(pre);
            p->next = q;
            p = q;
        }
        return res;
    }
};
int main()
{

    return 0;
}