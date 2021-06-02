#ifndef LIST_NODE
#define LIST_NODE

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *nex) : val(x), next(nex) {}
};

#endif