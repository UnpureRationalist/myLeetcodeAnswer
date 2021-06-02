#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string replaceSpace(string s)
    {
        string res;
        for (auto &c : s)
        {
            if (c == ' ')
            {
                res.push_back('%');
                res.push_back('2');
                res.push_back('0');
            }
            else
            {
                res.push_back(c);
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    cout << s.replaceSpace(" 0 ") << endl;
    return 0;
}