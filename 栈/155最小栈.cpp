#include <iostream>
#include <stack>
#include <set>
using namespace std;

class MinStack
{
    stack<int> stk;
    multiset<int> s;

public:
    /** initialize your data structure here. */
    MinStack()
    {
    }

    void push(int val)
    {
        stk.push(val);
        s.insert(val);
    }

    void pop()
    {
        auto count = s.count(stk.top());
        s.erase(stk.top());
        for (int i = 1; i < count; ++i)
            s.insert(stk.top());
        stk.pop();
    }

    int top()
    {
        return stk.top();
    }

    int getMin()
    {
        return *s.begin();
    }
};

// 辅助栈
class MinStack
{
    stack<int> x_stack;
    stack<int> min_stack;

public:
    MinStack()
    {
        min_stack.push(INT_MAX);
    }

    void push(int x)
    {
        x_stack.push(x);
        min_stack.push(min(min_stack.top(), x));
    }

    void pop()
    {
        x_stack.pop();
        min_stack.pop();
    }

    int top()
    {
        return x_stack.top();
    }

    int getMin()
    {
        return min_stack.top();
    }
};

class MinStack3
{
public:
    /** initialize your data structure here. */
    MinStack3()
    {
    }

    void push(int x)
    {
        if (st.size() == 0)
        {
            st.push({x, x});
        }
        else
        {
            st.push({x, min(x, st.top().second)});
        }
    }

    void pop()
    {
        st.pop();
    }

    int top()
    {
        return st.top().first;
    }

    int getMin()
    {
        return st.top().second;
    }

private:
    stack<pair<int, int>> st;
};

int main()
{

    return 0;
}