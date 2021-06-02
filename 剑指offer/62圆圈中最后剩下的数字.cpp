#include <iostream>
#include <list>
using namespace std;

class Solution
{
    struct Node
    {
        int data = 0;
        Node *next = nullptr, *pre = nullptr;

        Node(int n) : data(n) {}

        Node() {}
    };

    class CircleList
    {
        Node *head;
        int count = 0;

    public:
        CircleList(int n)
        {
            count = n;
            head = new Node();
            Node *pre = head, *cur = nullptr;
            for (int i = 1; i < n; ++i)
            {
                cur = new Node(i);
                pre->next = cur;
                cur->pre = pre;
                pre = cur;
            }
            cur->next = head;
            head->pre = cur;
        }

        int getNode(int m)
        {
            Node *p = head;
            while (count > 1)
            {
                int k = m % count;
                if (k > 0)
                {
                    while (--k)
                        p = p->next;
                }
                else
                    p = p->pre;
                Node *temp = p;
                p->pre->next = p->next;
                p->next->pre = p->pre;
                p = p->next;
                delete temp;
                --count;
            }
            return p->data;
        }
    };

public:
    int lastRemaining(int n, int m)
    {
        CircleList clist(n);
        return clist.getNode(m);
    }
};

class Solution2
{
    int f(int n, int m)
    {
        if (n == 1)
        {
            return 0;
        }
        int x = f(n - 1, m);
        return (m + x) % n;
    }

public:
    int lastRemaining(int n, int m)
    {
        return f(n, m);
    }
};

class Solution3
{
public:
    int lastRemaining(int n, int m)
    {
        int f = 0;
        for (int i = 2; i != n + 1; ++i)
        {
            f = (m + f) % i;
        }
        return f;
    }
};

int main()
{
    Solution s;
    cout << s.lastRemaining(70866, 116922) << endl;
    return 0;
}