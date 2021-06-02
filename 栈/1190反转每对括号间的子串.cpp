#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution
{
public:
    string reverseParentheses(string s)
    {
        auto n = s.length();
        stack<decltype(n)> stk;
        for (decltype(n) i = 0; i < n; ++i)
        {
            if (s[i] == '(')
            {
                stk.push(i);
            }
            else if (s[i] == ')')
            {
                auto start = stk.top();
                stk.pop();
                reverse(s.begin() + start, s.begin() + i + 1);
            }
        }
        
        string res;
        for (auto c : s)
            if (c != '(' && c != ')')
                res.push_back(c);
        return res;
    }
};

int main()
{

    return 0;
}