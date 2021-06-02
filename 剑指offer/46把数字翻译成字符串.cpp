#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Solution
{
    int calculate(string s)
    {
        if(s.length() == 1)
            return 1;
        if(s.length() == 2)
        {
            int i = atoi(s.c_str());
            if(s[0] == '1' || (s[0] == '2' && s[1] < '6'))
                return 2;
            else
                return 1;
        }
        if(s[0] == '1' || (s[0] == '2' && s[1] < '6'))
        {
            return calculate(s.substr(1)) + calculate(s.substr(2));
        }
        else
            return calculate(s.substr(1));
    }

public:
    int translateNum(int num)
    {
        string s = to_string(num);
        return calculate(s);
    }
};

int main()
{
    Solution s;
    cout << s.translateNum(12258) << endl;
    return 0;
}