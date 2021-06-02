#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if(head == nullptr)
            return nullptr;
        map<Node *, Node *> m;
        m[nullptr] = nullptr;
        Node *p = new Node(head->val);
        Node *phead = p;
        Node *cur = head->next;
        m[head] = p;
        while(cur)
        {
            p->next = new Node(cur->val);
            m[cur] = p->next;
            cur = cur->next;
            p = p->next;
        }
        cur = head;
        p = phead;
        while(cur)
        {
            p->random = m[cur->random];
            cur = cur->next;
            p = p->next;
        }
        return phead;
    }
};

int main()
{

    return 0;
}