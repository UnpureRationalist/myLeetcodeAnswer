#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string licenseKeyFormatting(string s, int k)
    {
        string res;
        int n = s.length();
        int count = 0;
        for (auto c : s)
        {
            if (c == '-')
            {
                ++count;
            }
        }
        int charNum = n - count;
        int mod = charNum % k;
        int i = 0;
        if (mod != 0)
        {
            for (; res.length() < mod; ++i)
            {
                if (s[i] != '-')
                {
                    res.push_back(toupper(s[i]));
                }
            }
            if (i < n - 1)
            {
                res.push_back('-');
            }
        }
        int temp = 0;
        for (; i < n; ++i)
        {
            if (s[i] != '-')
            {
                res.push_back(toupper(s[i]));
                ++temp;
                if (temp == k && i != n - 1)
                {
                    res.push_back('-');
                    temp = 0;
                }
            }
        }
        if (res.back() == '-')
        {
            res.pop_back();
        }
        return res;
    }
};