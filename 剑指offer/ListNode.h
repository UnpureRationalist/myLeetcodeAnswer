#ifndef LIST_NODE
#define LIST_NODE

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

#endif