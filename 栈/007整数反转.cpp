#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        if (x == 0 || x == INT_MIN)
            return 0;
        long long flag = 1;
        long long temp = x;
        if (x < 0)
        {
            flag = -1;
            temp = -x;
        }
        string s = to_string(temp);
        std::reverse(s.begin(), s.end());
        string MAX = to_string(INT_MAX);
        if (s.length() == MAX.length() && s > MAX)
            return 0;
        long long res = atoi(s.c_str());
        res = res * flag;
        if (res < INT_MIN || res > INT_MAX)
            return 0;
        return res;
    }
};

class Solution2
{
public:
    int reverse(int x)
    {
        int rev = 0;
        while (x != 0)
        {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7))
                return 0;
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8))
                return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};

int main()
{
    Solution s;
    cout << s.reverse(-2147483648) << endl;
    return 0;
}