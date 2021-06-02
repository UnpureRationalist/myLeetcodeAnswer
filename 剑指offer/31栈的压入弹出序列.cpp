#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        if (pushed.size() != popped.size())
            return false;
        int n = pushed.size();
        if (n == 0)
            return true;
        stack<int> s;
        int i = 0, j = 0;
        while (i < n && j < n)
        {
            while (i < n && (s.empty() || s.top() != popped[j]))
            {
                s.push(pushed[i]);
                ++i;
            }
            while (j < n && !s.empty() && s.top() == popped[j])
            {
                s.pop();
                ++j;
            }
        }
        return s.empty();
    }
};

class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        stack<int> s;
        int i = 0;
        for (int num : pushed)
        {
            s.push(num); // num 入栈
            while (!s.empty() && i < popped.size() && s.top() == popped[i])
            { // 循环判断与出栈
                s.pop();
                i++;
            }
        }
        return s.empty();
    }
};

int main()
{

    return 0;
}