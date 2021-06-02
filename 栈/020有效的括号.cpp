#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> sk;
        const char *p = s.c_str();
        while(*p)
        {
            char c = *p;
            char t;
            switch(c)
            {
                case '(':
                    sk.push(c);
                    break;
                case '[':
                    sk.push(c);
                    break;
                case '{':
                    sk.push(c);
                    break;
                case ')':
                    if(sk.empty())
                        return false;
                    t = sk.top();
                    if(t != '(')
                        return false;
                    sk.pop();
                    break;
                case ']':
                    if(sk.empty())
                        return false;
                    t = sk.top();
                    if(t != '[')
                        return false;
                    sk.pop();
                    break;
                case '}':
                    if(sk.empty())
                        return false;
                    t = sk.top();
                    if(t != '{')
                        return false;
                    sk.pop();
                    break;
            }
            ++p;
        }
        if(sk.empty())
            return true;
        return false;
    }
};

int main()
{

    return 0;
}