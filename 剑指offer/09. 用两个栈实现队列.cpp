#include <iostream>
#include <stack>
using namespace std;

class CQueue
{
    stack<int> s1, s2;

public:
    CQueue()
    {
    }

    void appendTail(int value)
    {
        s1.push(value);
    }

    int deleteHead()
    {
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (s2.empty())
            return -1;
        int temp = s2.top();
        s2.pop();
        return temp;
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        s1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (s2.empty())
            return -1;
        int temp = s2.top();
        s2.pop();
        return temp;
    }

    /** Get the front element. */
    int peek()
    {
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (s2.empty())
            return -1;
        return s2.top();
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return s1.empty() && s2.empty();
    }
};

int main()
{

    return 0;
}