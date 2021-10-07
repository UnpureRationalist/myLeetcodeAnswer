#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
    std::string triCoding(int num)
    {
        if (num == 0)
            return "@";
        std::string res;
        std::string mp = "@$&";
        bool negative = false;
        if (num < 0)
        {
            num = -num;
            negative = true;
        }
        while (num)
        {
            int mod = num % 3;
            num /= 3;
            res.push_back(mp[mod]);
        }
        std::reverse(res.begin(), res.end());
        if (negative)
        {
            res = "-" + res;
        }
        return res;
    }
};

int main()
{
    Solution s;
    cout << s.triCoding(-123) << endl;
    return 0;
}