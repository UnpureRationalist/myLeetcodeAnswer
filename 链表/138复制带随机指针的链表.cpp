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
        map<Node *, Node *> m; // map
        m[nullptr] = nullptr;  // 需要先插入该元素
        Node *curr = head;
        Node *p = new Node(0); // 头节点 方便统一处理
        while (curr)
        {
            p->next = new Node(curr->val);
            m[curr] = p->next; // map 映射关系为 原链表同一位置（序号）节点指针 --->  新链表同一位置（序号）节点指针
            p = p->next;
            curr = curr->next;
        }

        curr = head;
        p = m[curr]; // p 指向新链表的第一个节点
        while (curr)
        {
            p->random = m[curr->random]; // 有存储的映射关系 获取新链表节点 random 指针应指向位置
            p = p->next;
            curr = curr->next;
        }
        return m[head];
    }
};

int main()
{

    return 0;
}