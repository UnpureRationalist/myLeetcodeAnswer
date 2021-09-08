#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

class Solution
{
    Node *last = nullptr;
public:
    Node *flatten(Node *head)
    {
        Node *res = head;
        while(head)
        {
            last = head;
            if(head->child)
            {
                Node *next = head->next;
                Node *child = flatten(head->child);
                head->next = child;
                head->child = nullptr;
                child->prev = head;
                last->next = next;
                if(next)
                    next->prev = last;
                head = next;
            }
            else
            {
                head = head->next;
            }
        }
        return res;
    }
};

int main()
{

    return 0;
}