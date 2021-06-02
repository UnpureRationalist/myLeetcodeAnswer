#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> res;
        int n = tokens.size();
        for (int i = 0; i < n; ++i)
        {
            string s = tokens[i];
            if (s.length() == 1)
            {
                switch (s[0])
                {
                    int op1, op2;
                case '+':
                    op1 = res.top();
                    res.pop();
                    op2 = res.top();
                    res.pop();
                    res.push(op1 + op2);
                    break;
                case '-':
                    op1 = res.top();
                    res.pop();
                    op2 = res.top();
                    res.pop();
                    res.push(op2 - op1);
                    break;
                case '*':
                    op1 = res.top();
                    res.pop();
                    op2 = res.top();
                    res.pop();
                    res.push(op1 * op2);
                    break;
                case '/':
                    op1 = res.top();
                    res.pop();
                    op2 = res.top();
                    res.pop();
                    res.push(op2 / op1);
                    break;
                default:
                    res.push(atoi(s.c_str()));
                    break;
                }
            }
            else
            {
                res.push(atoi(s.c_str()));
            }
        }
        return res.top();
    }
};

int main()
{

    return 0;
}