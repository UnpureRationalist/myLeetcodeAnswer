#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class MinStack
{
    stack<int> s;
    int minElem = INT_MAX;
    int minCount = -1;

public:
    /** initialize your data structure here. */
    MinStack()
    {
    }

    void push(int x)
    {
        if (s.empty())
        {
            minElem = x;
            minCount = 1;
        }
        else
        {
            if (x < minElem)
            {
                minElem = x;
                minCount = 1;
            }
            else if (x == minElem)
            {
                ++minCount;
            }
        }
        s.push(x);
    }

    void pop()
    {
        int temp = s.top();
        s.pop();
        if (temp == minElem)
            --minCount;
        if (minCount == 0 && !s.empty())
        {
            // 更新最小值
            minElem = s.top();
            minCount = 0;
            stack<int> backup;
            while (!s.empty())
            {
                backup.push(s.top());
                if (s.top() < minElem)
                    minElem = s.top();
                s.pop();
            }
            while (!backup.empty())
            {
                if (backup.top() == minElem)
                    ++minCount;
                s.push(backup.top());
                backup.pop();
            }
        }
    }

    int top()
    {
        return s.top();
    }

    int min()
    {
        return minElem;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */

int main()
{

    return 0;
}