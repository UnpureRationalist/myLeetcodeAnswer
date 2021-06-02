#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        stringstream ss(s);
        string temp;
        stack<string> stk;
        while (ss >> temp)
        {
            stk.push(temp);
        }
        string res;
        while (!stk.empty())
        {
            temp = stk.top();
            stk.pop();
            res += temp;
            if (!stk.empty())
                res += " ";
        }
        return res;
    }
};

int main()
{

    return 0;
}